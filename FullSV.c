#include <stdio.h>
#include <stdlib.h>

/*                    ------------------ FULL VERSION ------------------

                DIES IST DIE VOLLVERSION DES SPIELS. MIT SCHIFFE PLATZIEREN USW.
*/

// SCHÖNERES SPIELENDE
// KENTER COUNTER

int schiffsgroesse[] = {5, 4, 4, 3, 3, 3, 2, 2, 2, 2}; //Array mit den vorhandenen Schiffsgroessen. Global erstellt
int p1 = 0;
int p2 = 0;

  int myspielfeld1[10][10] =
     {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

  int enspielfeld1[10][10] =
     {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

void menue2(){

printf("\n\n\t- VICTORY MENU - \n");
  printf("\n\n\tZum navigieren bitte Optionen 1 bis 2 auswaehlen (falls vohanden)");
  printf("\n\n\t1): Zum Main Menu");
  printf("\n\t2): Programm beenden");
  printf("\n\n\tEingabe: ");

    int option2;
    char buf4[100];              // Eingabepuffer
    fgets(buf4, 100, stdin);     // Lese in Eingabepuffer ein
    sscanf(buf4, "%d", &option2); // scanf("%d", &option);
    switch(option2)
    {
    case 1:
    p1 = 0;
    p2 = 0;
    for(int i = 0; i != 10; i ++){
        for(int j = 0; j != 10; j++){
            myspielfeld1[i][j] = 0;
            enspielfeld1[i][j] = 0;
        }
    }
        system("@cls||clear");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        main();
    
    case 2:
        printf("\n\t\t\t\t- PROGRAMM BEENDET -\n\n\n");
        exit(0);
    
    default:
    system("@cls||clear");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tBitte Optionen 1 bis 2 auswaehlen");
    menue2();
    }
}

//Test ob ein Schiff gekenter ist
int istSchiffGekentert(int spielfeld[10][10]) {
    int schiffGekentert = 0;
    //Zwei for-Schleifen laufen ganzes Spielfeld ab und suchen abgeschossene Schiffe. Ist ein abgeschossenes gefunden wird geprueft, ob sich daneben noch ein anderes unabgeschossenes befindet. Wenn nein, dann ist das Schiff komplett abgeschossen und gekentert
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (spielfeld[i][j] == 6) {
                if (spielfeld[i - 1][j] == 1) { //�berpruefung des Felds oberhalb des aktuellen Werts
                    schiffGekentert = 1;
                    break;
                } else if (spielfeld[i][j + 1] == 1) { //�berpruefung des Felds rechts des aktuellen Werts
                    schiffGekentert = 1;
                    break;
                } else if (spielfeld[i + 1][j] == 1) { //�berpruefung des Felds unterhalb des aktuellen Werts
                    schiffGekentert = 1;
                    break;
                } else if (spielfeld[i][j - 1] == 1) { //�berpruefung des Felds links des aktuellen Werts
                    schiffGekentert = 1;
                    break;
                }

            }
            if (schiffGekentert == 1) {//noetig?
                break;
            }
        }
        if (schiffGekentert == 1) { //noetig?
            break;
        }
    }
    return schiffGekentert;
}

void anzeigen(int spielfeld1[10][10], int spielfeld2[10][10])
{
  int row = 1;
  int row2 = 1;
  printf("\n\n\t\t\t    Gegnerisches Spielfeld");                              printf("\t\t\t\t\t\t Dein Spielfeld");
  printf("\n\n\t        A    B    C    D    E    F    G    H    I    J");      printf("\t\t\t  A    B    C    D    E    F    G    H    I    J");
  printf("\n\t     ----------------------------------------------------");     printf("\t       ----------------------------------------------------\n");

  for (int i = 0; i != 10; i++){
    if (row < 10){
      printf("\t %d   |", row);
    }else{
      printf("\t %d  |", row);
    }row++;
    
     for (int j = 0; j != 10; j++){
      if (spielfeld1[i][j] == 6){
        printf("  X  ");
      }
      else if (spielfeld1[i][j] == 4){
        printf("  3  ");
      }else{
        printf("  0  ");
      }
      if ((j + 1) % 10 == 0){
        printf("|");
      }
    }
    
    if (row2 < 10){
      printf("\t   %d   |", row2);
    }else{
      printf("\t   %d  |", row2);
    }row2++;
    
    for (int j = 0; j != 10; j++){
      if (spielfeld2[i][j] == 6){
        printf("  X  ");
      }
      else if (spielfeld2[i][j] == 4){
        printf("  3  ");
      }
      else{
        printf("  %d  ", spielfeld2[i][j]);
      }
      if ((j + 1) % 10 == 0){
        printf("|");
      }
    }

    if (i < 9){
      printf("\n\t     |                                                  |"); printf("\t       |                                                  |\n");
    }else{
      printf("\n\t     ----------------------------------------------------"); printf("\t       ----------------------------------------------------\n");
    }
  }
  printf("\n\n");
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void spiel(int spielfeld1[10][10], int spielfeld2[10][10], int *p)
{
  while (*p < 30)
  {      
    anzeigen(spielfeld1, spielfeld2);
    char xko = 0;
    int yko = 0;
    printf("\n\n\tLegende:      Standard: 0      Wasser: 3      Schiffsteil: 1      Getroffenes Schiffsteil: X");
    printf("\n\n\tProgramm beenden:\tSpalte: Z\tZeile: 1337 \n");
    printf("\n\tGib die x-Koordinate (Spalte) ein, die du beschiessen willst (A-J): ");

    char buf2[100];           // Eingabepuffer
    fgets(buf2, 100, stdin);  // Lese in Eingabepuffer ein
    sscanf(buf2, "%c", &xko); // scanf("%d", &xko);

    if (xko == 'Z')
    {
      printf("\n\n\t\t\t\t- PROGRAMM BEENDET -\n\n\n");
     exit(0);
    }
    else if (xko < 'A' || xko > 'J')
    {
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tFalsche Eingabe!");
      continue;
    }
    printf("\n\tGib die y-Koordinate (Zeile) ein, die du beschiessen willst (1-10): ");

    char buf3[100];           // Eingabepuffer
    fgets(buf3, 100, stdin);  // Lese in Eingabepuffer ein
    sscanf(buf3, "%d", &yko); // scanf("%d", &yko);

    if (yko == 1337)
    {
      printf("\n\n\t\t\t\t- PROGRAMM BEENDET -\n\n\n");
      exit(0);
    }
    else if (yko == 0 || yko < 0 || yko > 10)
    {
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tFalsche Eingabe!");
      continue;
    }

    if (spielfeld1[yko - 1][xko - 65] == 1)
    {
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t        - SPIEL LAEUFT - \n");
      printf("\n\t\t\t\t\t\t\t\t   Getroffen!");
      spielfeld1[yko - 1][xko - 65] = 6;
      if(istSchiffGekentert(spielfeld1) ==0){
        printf("\n\n\t\t\t\t\t\t\t\tSchiff gekentert!\n");
      }
      (*p)++;
     //istSchiffGekentert(spielfeld1);
    }
    else if (spielfeld1[yko - 1][xko - 65] == 0)
    {
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t        - SPIEL LAEUFT - \n");
      printf("\n\t\t\t\t\t\t\t\tNicht getroffen.");
      spielfeld1[yko - 1][xko - 65] = 4;
      break;
    }
    else if (spielfeld1[yko - 1][xko - 65] == 6 || 4)
    {
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t        - SPIEL LAEUFT - \n");
      printf("\n\t\t\t\t\t\t\t\tSchon getroffen.");
      break;
    }
  }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//Ausgabe welche Schiffe noch verfuegbar sind
void printSchiffslaenge(int durchlauf){
    int AnzahlOffeneSchiffe = (10 - durchlauf); //Variable wird zum durchlaufen genutzt, damit jede Runde eine Ziffer weniger ausgegeben wird.

    printf("\nDiese Schiffslaengen koennen noch platziert werden:");
    for (int i = 0; i < AnzahlOffeneSchiffe; i++) {
        if (i == (AnzahlOffeneSchiffe - 1)) {
            printf(" %d\n\n", schiffsgroesse[i]);
        } else {
            printf(" %d,", schiffsgroesse[i]);
        }
    }
}


//Ausgewaehlte Schiffslaenge aus Liste entfernen
void schiffListeNeu(int groesse, int durchlauf) {
    int zwischenspeicher;

    for (int i = 0; i < (10 - durchlauf); i++) {
        if (schiffsgroesse[i] == groesse) { //Schleife laeuft durch, bis ein Schiff mit der passenden Laenge gefunden wurde. Ist das passiert wird i = 10 gestzt, womit die Schleife endet
            for (int j = i; j < (j +(9 - i)); i++) {  //Die Stelle der gefundenen Schiffslaenge wird genutzt und das Element wird ans Ende des Arrays verschoben
                zwischenspeicher = schiffsgroesse[i];
                schiffsgroesse[i] = schiffsgroesse[i + 1];
                schiffsgroesse[i + 1] = zwischenspeicher;
            }
            i = 10; //Ist Schiffslaenge gefunden wird i = 10 gesetzt, damit Schleife abbricht
        }
    }
}


//Eingabe, welches Schiff gesetzt werden soll
void schiffsauswahl(int *groesse, int durchlauf) {
    int gueltigeEingabe = 1;
    char buffer[10];

    //Schleife laeuft so lange, bis es eine gueltige Eingabe gibt
    while (gueltigeEingabe == 1) {
        printf("Welches Schiff moechtest du platzieren?\n");
        scanf("%d", groesse);
        printf("\n");
        for (int i = 0; i < (10 - durchlauf); i++) {
            if (*groesse > 1 && *groesse < 6) { //Pruefen ob genannte Schiffslaenge noch verfuegbar ist
                if (schiffsgroesse[i] == *groesse) {
                    gueltigeEingabe = 0;
                }
            }
        }
        fgets(buffer, 10, stdin); //Eingabezeile leeren
        if (gueltigeEingabe == 1) { //Ausgabe, dass Eingabe ungueltig ist
            *groesse = 0;
            printf("Ungueltige Eingabe\n\n");
        }
    }

}


//Ausrichtung des Schiffes bestimmen
void ausrichtung(int groesse, int *ausrichtungsindex) {
    int gueltigeEingabe = 1;
    char buffer[10];

    //Funktion laeuft, bis es eine gueltige Eingabe gibt
    while (gueltigeEingabe == 1) {
        printf("In welcher Ausrichtung moechtest du das Schiff platzieren?\n\n");
        printf("Ausrichtung 1: X        Ausrichtung 2: X");
        //Zwei for-Schleifen fuer Ausgabe der Ausrichtungsrichtung
        for (int i = 0; i < (groesse - 1); i++) {
            printf(" X");
        }
        for (int i = 0; i < (groesse - 1); i++) {
            printf("\n               X");
        }
        printf("\n\nAusrichtung: ");
        scanf("%d", ausrichtungsindex);
        printf("\n\n");
        fgets(buffer, 10, stdin); //Eingabezeile leeren
        if ((*ausrichtungsindex > 0) && (*ausrichtungsindex < 3)) {
            gueltigeEingabe = 0;
        } else {
            printf("Ungueltige Eingabe\n\n");
        }
    }

}


//Kontrolle ob Schiff im Nebenfeld
int kontrolleNebenfelder(int ausrichtungsindex, int groesse, int spalte, int zeile, int spielfeld[10][10]) {
    int gueltigeEingabe = 0;
    switch (ausrichtungsindex) {
        case 1: //Ausrichtungsindex = 1 -> Senkrecht
            for (int i = (zeile - 1); i < (groesse + zeile - 1); i++) { //Schleife laeuft so oft, wie Schiff lang ist und ueberprueft ob an eingegebenem Punkt bzw. im Uhrzeigersinn rundrum schon ein Schiff platziert ist
                if (spielfeld[i][spalte - 1] == 1) {
                    printf("Schiff kann hier nicht platziert werden\n");
                    gueltigeEingabe = 1;
                    break;
                } else if (spielfeld[i - 1][spalte - 1] == 1) {
                    printf("Schiff kann hier nicht platziert werden\n");
                    gueltigeEingabe = 1;
                    break;
                } else if (spielfeld[i][spalte] == 1 && spalte != 10) {
                    printf("Schiff kann hier nicht platziert werden\n");
                    gueltigeEingabe = 1;
                    break;
                } else if (spielfeld[i + 1][spalte - 1] == 1) {
                    printf("Schiff kann hier nicht platziert werden\n");
                    gueltigeEingabe = 1;
                    break;
                } else if (spielfeld[i][spalte - 2] == 1 && spalte != 10) {
                    printf("Schiff kann hier nicht platziert werden\n");
                    gueltigeEingabe = 1;
                    break;
                }
            }
            return gueltigeEingabe; //Wert ob Eingabe gueltig ist wird zurueck gegeben
            break;

        case 2: //Ausrichtungsindex = 2 -> Waagerecht
            for (int i = (spalte - 1); i < (groesse + spalte - 1); i++) { //Schleife laeuft so oft, wie Schiff lang ist und ueberprueft ob an eingegebenem Punkt bzw. im Uhrzeigersinn rundrum schon ein Schiff platziert ist
                if (spielfeld[zeile - 1][i] == 1) {
                    printf("Schiff kann hier nicht platziert werden\n");
                    gueltigeEingabe = 1;
                    break;
                } else if (spielfeld[zeile - 1][i - 1] == 1) {
                    printf("Schiff kann hier nicht platziert werden\n");
                    gueltigeEingabe = 1;
                    break;
                } else if (spielfeld[zeile - 2][i] == 1 && i != 9) {
                    printf("Schiff kann hier nicht platziert werden\n");
                    gueltigeEingabe = 1;
                    break;
                } else if (spielfeld[zeile - 1][i + 1] == 1) {
                    printf("Schiff kann hier nicht platziert werden\n");
                    gueltigeEingabe = 1;
                    break;
                } else if (spielfeld[zeile][i] == 1 && i != 9) {
                    printf("Schiff kann hier nicht platziert werden\n");
                    gueltigeEingabe = 1;
                    break;
                }
            }
            return gueltigeEingabe; //Wert ob Eingabe gueltig ist wird zurueck gegeben
            break;

        default:
            break;
    }
    return 1;
}


//Buchstabeneingabe zu Ziffer
void buchstabeZuZiffer(int *spalte, char spaltenbuchstabe) {
    //Buchstabeneingabe wird in Zifferneingabe umgewandelt. Ist Eingabe eine andere als die gueltigen Buchstaben wird sie auf einen ungueltigen Wert gesetzt
    if (spaltenbuchstabe == 'A' || spaltenbuchstabe == 'a') {
        *spalte = 1;
    } else if (spaltenbuchstabe == 'B' || spaltenbuchstabe == 'b') {
        *spalte = 2;
    } else if (spaltenbuchstabe == 'C' || spaltenbuchstabe == 'c') {
        *spalte = 3;
    } else if (spaltenbuchstabe == 'D' || spaltenbuchstabe == 'd') {
        *spalte = 4;
    } else if (spaltenbuchstabe == 'E' || spaltenbuchstabe == 'e') {
        *spalte = 5;
    } else if (spaltenbuchstabe == 'F' || spaltenbuchstabe == 'f') {
        *spalte = 6;
    } else if (spaltenbuchstabe == 'G' || spaltenbuchstabe == 'g') {
        *spalte = 7;
    } else if (spaltenbuchstabe == 'H' || spaltenbuchstabe == 'h') {
        *spalte = 8;
    } else if (spaltenbuchstabe == 'I' || spaltenbuchstabe == 'i') {
        *spalte = 9;
    } else if (spaltenbuchstabe == 'J' || spaltenbuchstabe == 'j') {
        *spalte = 10;
    }  else {
        *spalte = 0;
    }
}


//Koordinaten der Schiffe eintippen
void koordinateneingabe(int ausrichtungsindex, int groesse, int *spalte, int *zeile, int spielfeld[10][10]) {
    int gueltigeEingabe = 1;
    int letztesFeld;

    //Darstellung welche Koordinaten man eingeben soll
    switch (ausrichtungsindex) {
        case 1: //Senkrecht
            printf("Gib die Koordinaten des obersten X an\n");
            printf("    X <--");
            for (int i = 0; i < (groesse - 1); i++) {
                printf("\n    X");
            }
            printf("\n\n");
            break;

        case 2: //Waagerecht
            printf("Gib die Koordinaten des ersten X von links an\n");
            for (int i = 0; i < groesse; i++) {
                printf(" X");
            }
            printf("\n ^\n");
            break;

        default:
            break;
    }

    //So lange, bis Eingabe gueltig ist. Schleife gilt fuer Spalten, Zeilen und Nebenfelder
    while (gueltigeEingabe == 1) {
        gueltigeEingabe = 1;
        char spaltenbuchstabe;

        //Spalteneingabe und �berpruefung
        while (gueltigeEingabe == 1) {
            printf("Spalte: ");
            scanf("%s", &spaltenbuchstabe);
            buchstabeZuZiffer(spalte, spaltenbuchstabe);
            letztesFeld = (*spalte) + (groesse - 1); //Spalte des letzten Schiffsteils wird berechnet und folgend bei der �berpruefung genutzt
            if ((*spalte) < 1 || (*spalte) > 10) { //Ob Spalteneingabe in gueltigem Zahlenbereich liegt
                printf("Ungueltige Spalteneingabe\n");
            } else if ((ausrichtungsindex == 2) && (letztesFeld > 10)) { //Ob durch Spalteneingabe das Schiff ueber den Rand hinausragt. Nur bei waagerechter Eingabe
                printf("Schiff kann hier nicht platziert werden\n");
            } else {
                gueltigeEingabe = 0;
            }
        }

        //Zeileneingabe und �berpruefung
        gueltigeEingabe = 1;
        char buffer[10];

        while (gueltigeEingabe == 1) {
            printf("Zeile: ");
            scanf("%d", zeile);
            fgets(buffer, 10, stdin); //Eingabezeile wird geloescht
            letztesFeld = (*zeile) + (groesse - 1); //Zeile des letzten Schiffsteils wird berechnet und folgend bei der �berpruefung genutzt
            if (((*zeile) < 1) || ((*zeile) > 10)) { //Ob Spalteneingabe in gueltigem Zahlenbereich liegt
                printf("Ungueltige Zeileneingabe\n");
            } else if ((ausrichtungsindex == 1) && (letztesFeld > 10)) { //Ob durch Zeileneingabe das Schiff ueber den Rand hinausragt. Nur bei senkrechter Eingabe
                printf("Schiff kann hier nicht platziert werden\n");
            } else {
                gueltigeEingabe = 0;
            }
        }
        gueltigeEingabe = kontrolleNebenfelder(ausrichtungsindex, groesse, *spalte, *zeile, spielfeld); //�berpruefung ob ein Schiff im Nebenfeld liegt
    }
}


//Schiffe auf Spielfeld setzen
void eingabeSchiffsposition(int ausrichtungsindex, int spalte, int zeile, int groesse, int spielfeld[10][10]) {
    switch (ausrichtungsindex) {
        case 1: //Senkrecht
            for (int i = (zeile - 1); i < (zeile + groesse - 1); i++) { //So oft, wie Schiff gro� ist wird im Spielfeld eine 1/Schiff gesetzt
                spielfeld[i][spalte - 1] = 1;
            }
            break;

        case 2: //Waagerecht
            for (int i = (spalte - 1); i < (spalte + groesse - 1); i++) { //So oft, wie Schiff gro� ist wird im Spielfeld eine 1/Schiff gesetzt
                spielfeld[zeile - 1][i] = 1;
            }
            break;

        default:
            break;
    }
}


//oberste Funktion
void schiffePlatzieren(int spielfeld1[10][10], int spielfeld2[10][10]) {

    int groesse, spalte, zeile, ausrichtungsindex; //Variablen die fuer Platzierungsablauf benoetigt werden

    for (int durchlauf = 0; durchlauf < 10; durchlauf++) {//Zehnmal laeuft die Platzierungsfunktion
        ausrichtungsindex = 0;
        anzeigen(spielfeld2 ,spielfeld1);
        printSchiffslaenge(durchlauf);
        schiffsauswahl(&groesse, durchlauf);
        ausrichtung(groesse, &ausrichtungsindex);
        anzeigen(spielfeld2 ,spielfeld1);
        koordinateneingabe(ausrichtungsindex, groesse, &spalte, &zeile, spielfeld1);
        eingabeSchiffsposition(ausrichtungsindex, spalte, zeile, groesse, spielfeld1);
        schiffListeNeu(groesse, durchlauf);
    }
    printf("\n\n\tAlle Schiffe sind platziert. Weiter gehts mit Spieler 2!\n\n");

}


int main()
{
  int option;

  printf("\n\n\t- MAIN MENU - \n");
  printf("\n\n\tZum navigieren bitte Optionen 1 bis 2 auswaehlen (falls vohanden)");
  printf("\n\n\t1): Spiel Starten");
  printf("\n\t2): Programm beenden");
  printf("\n\n\tEingabe: ");

  char buf[100];              // Eingabepuffer
  fgets(buf, 100, stdin);     // Lese in Eingabepuffer ein
  sscanf(buf, "%d", &option); // scanf("%d", &option);

  switch (option)
  {

  case 1:
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t        - SPIEL LAEUFT - \n");
    schiffePlatzieren(myspielfeld1, enspielfeld1);
    schiffePlatzieren(enspielfeld1, enspielfeld1);
    while(1){ // switch player funktion
     printf("\n\n\t\t\t\t\t\t\t\tSpieler 1 ist dran\n\n");
     spiel(enspielfeld1, myspielfeld1, &p1); //spieler 1 ist dran
     if (p1 >= 30) {
         break;
     }
     printf("\n\n\t\t\t\t\t\t\t\tSpieler 2 ist dran\n\n");
     spiel(myspielfeld1, enspielfeld1, &p2); //spieler 2 ist dran
     if (p2 >= 30) {
         break;
     }
    }
    system("@cls||clear");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    if (p1 >= 30) {
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t- SPIELER 1 HAT GEWONNEN -\n\n\n\n");
    }
    if (p2 >= 30) {
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t- SPIELER 2 HAT GEWONNEN -\n\n\n\n");
    }
    menue2();

  case 2:
    printf("\n\t\t\t\t- PROGRAMM BEENDET -\n\n\n");
    exit(0);

  default:
    system("@cls||clear");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tBitte Optionen 1 bis 2 auswaehlen");
    main();
  }
}