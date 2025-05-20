//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator with the current time
    int numQuestions = rand() % 6 + 5; // generate a random number of questions between 5 and 10
    int score = 0; // initialize the score to 0

    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("You will be asked %d questions about the elements in the periodic table.\n", numQuestions);
    printf("For each question, enter the correct element symbol (e.g. H for Hydrogen).\n");
    printf("You will receive 1 point for each correct answer.\n");
    printf("Good luck!\n");

    for (int i = 0; i < numQuestions; i++) {
        int elementNumber = rand() % 118 + 1; // generate a random element number between 1 and 118
        char elementName[100];
        char elementSymbol[10];
        switch (elementNumber) {
            case 1:
                strcpy(elementName, "Hydrogen");
                strcpy(elementSymbol, "H");
                break;
            case 2:
                strcpy(elementName, "Helium");
                strcpy(elementSymbol, "He");
                break;
            case 6:
                strcpy(elementName, "Carbon");
                strcpy(elementSymbol, "C");
                break;
            case 7:
                strcpy(elementName, "Nitrogen");
                strcpy(elementSymbol, "N");
                break;
            case 8:
                strcpy(elementName, "Oxygen");
                strcpy(elementSymbol, "O");
                break;
            case 79:
                strcpy(elementName, "Gold");
                strcpy(elementSymbol, "Au");
                break;
            case 82:
                strcpy(elementName, "Lead");
                strcpy(elementSymbol, "Pb");
                break;
            default:
                sprintf(elementName, "Element %d", elementNumber);
                sprintf(elementSymbol, "%c", 'A' + (elementNumber - 1));
                break;
        }
        printf("Question %d: What is the symbol for %s?\n", i + 1, elementName);
        char answer[10];
        scanf("%s", answer);
        if (strcmp(answer, elementSymbol) == 0) {
            score++;
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct answer is %s.\n", elementSymbol);
        }
    }

    printf("Congratulations, you have completed the quiz!\n");
    printf("Your final score is %d out of %d.\n", score, numQuestions);

    return 0;
}