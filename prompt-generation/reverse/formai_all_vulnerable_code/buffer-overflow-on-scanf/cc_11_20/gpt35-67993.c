//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to display periodic table
void displayPeriodicTable() {
    printf("\n");
    printf(" __________________________________________________________________________________________\n");
    printf("|        |                                     |                                        |\n");
    printf("|  H  1  |                He                 2  |                                        |\n");
    printf("|________|_____________________________________|                                        |\n");
    printf("|        |                                     |             |                          |\n");
    printf("| Li  3  |                Be  4               |   B  5   |   C  6 (Your favourite!)    |\n");
    printf("|________|_____________________________________|_________|______________________________|\n");
    printf("|        |                 |  N  7   |  O  8   |                 |  F  9   |   Ne     10  |\n");
    printf("| Na 11  |     Mg  12      |_________|_________|    Al 13        |_________|______________|\n");
    printf("|________|_________________|                 |_________________|                      |\n");
    printf("|        |                 |                 |                 |             |        |\n");
    printf("| Si 14  |     P  15       |    S  16        |    Cl  17       |    Ar     18        |\n");
    printf("|________|_________________|_________________|_________________|______________________|\n");
    printf("|        |                                     |                                      |\n");
    printf("| K   19 |                Ca  20              |                 Sc  21 (Scrumble?)   |\n");
    printf("|________|_____________________________________|______________________________________|\n");
    printf("|        |                 |                 |                                      |\n");
    printf("| Ti 22  |     V  23       |    Cr  24       |                 Mn  25              |\n");
    printf("|________|_________________|_________________|______________________________________|\n");
    printf("|        |                 |                 |                                      |\n");
    printf("| Fe 26  |     Co 27       |    Ni  28       |                 Cu  29             |\n");
    printf("|________|_________________|_________________|______________________________________|\n");
    printf("|        |                 |    Zn   30      |                                      |\n");
    printf("| Ga 31  |     Ge 32       |_________________|                 As 33              |\n");
    printf("|________|_________________|                                      |__________________|\n");
    printf("|        |                                                        |                  |\n");
    printf("| Se 34  |                          Br      35 (Break?)            |      Kr      36   |\n");
    printf("|________|________________________________________________________|__________________|\n");
}

// function to get random element from periodic table and ask user to identify it
void randomElementQuiz() {
    int randomNum = rand() % 36 + 1; // generates random number between 1-36
    char userAnswer[20];
    char correctAnswer[3];

    switch(randomNum) {
        case 1:
            strcpy(correctAnswer, "H");
            break;
        case 2:
            strcpy(correctAnswer, "He");
            break;
        case 3:
            strcpy(correctAnswer, "Li");
            break;
        case 4:
            strcpy(correctAnswer, "Be");
            break;
        case 5:
            strcpy(correctAnswer, "B");
            break;
        case 6:
            strcpy(correctAnswer, "C");
            break;
        case 7:
            strcpy(correctAnswer, "N");
            break;
        case 8:
            strcpy(correctAnswer, "O");
            break;
        case 9:
            strcpy(correctAnswer, "F");
            break;
        case 10:
            strcpy(correctAnswer, "Ne");
            break;
        case 11:
            strcpy(correctAnswer, "Na");
            break;
        case 12:
            strcpy(correctAnswer, "Mg");
            break;
        case 13:
            strcpy(correctAnswer, "Al");
            break;
        case 14:
            strcpy(correctAnswer, "Si");
            break;
        case 15:
            strcpy(correctAnswer, "P");
            break;
        case 16:
            strcpy(correctAnswer, "S");
            break;
        case 17:
            strcpy(correctAnswer, "Cl");
            break;
        case 18:
            strcpy(correctAnswer, "Ar");
            break;
        case 19:
            strcpy(correctAnswer, "K");
            break;
        case 20:
            strcpy(correctAnswer, "Ca");
            break;
        case 21:
            strcpy(correctAnswer, "Sc");
            break;
        case 22:
            strcpy(correctAnswer, "Ti");
            break;
        case 23:
            strcpy(correctAnswer, "V");
            break;
        case 24:
            strcpy(correctAnswer, "Cr");
            break;
        case 25:
            strcpy(correctAnswer, "Mn");
            break;
        case 26:
            strcpy(correctAnswer, "Fe");
            break;
        case 27:
            strcpy(correctAnswer, "Co");
            break;
        case 28:
            strcpy(correctAnswer, "Ni");
            break;
        case 29:
            strcpy(correctAnswer, "Cu");
            break;
        case 30:
            strcpy(correctAnswer, "Zn");
            break;
        case 31:
            strcpy(correctAnswer, "Ga");
            break;
        case 32:
            strcpy(correctAnswer, "Ge");
            break;
        case 33:
            strcpy(correctAnswer, "As");
            break;
        case 34:
            strcpy(correctAnswer, "Se");
            break;
        case 35:
            strcpy(correctAnswer, "Br");
            break;
        case 36:
            strcpy(correctAnswer, "Kr");
            break;
    }

    printf("\nWhat is the element with atomic number %d on the periodic table?: ", randomNum);
    scanf("%s", userAnswer); // get user input

    if(strcmp(userAnswer, correctAnswer) == 0) {
        printf("\nWell done! You correctly identified the element as %s\n", correctAnswer);
    }
    else {
        printf("\nSorry, the correct answer was %s\n", correctAnswer);
    }
}

// main function
int main() {
    srand(time(NULL)); // seed for random number generator
    int menuChoice;

    printf("Welcome to the Periodic Table Quiz!\n");

    do {
        printf("\nPlease choose an option:\n");
        printf("1. Display the periodic table\n");
        printf("2. Take a quiz\n");
        printf("3. Quit\n");
        printf("Selection: ");
        scanf("%d", &menuChoice); // get user menu choice

        switch(menuChoice) {
            case 1:
                displayPeriodicTable(); // call function to display periodic table
                break;
            case 2:
                randomElementQuiz(); // call function to take quiz
                break;
            case 3:
                printf("\nThank you for playing the Periodic Table Quiz! Goodbye!\n");
                break;
            default:
                printf("\nInvalid input. Please try again.\n");
                break;
        }
    } while(menuChoice != 3);

    return 0;
}