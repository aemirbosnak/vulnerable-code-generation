//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numQuestions;
    int score = 0;
    char playAgain;

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("How many questions would you like to answer? ");
    scanf("%d", &numQuestions);

    for (int i = 0; i < numQuestions; i++) {
        int randomNum = rand() % 118; // There are 118 elements in the periodic table
        int element = randomNum + 1; // Adding 1 because array indices start at 0

        char elementName[50];
        switch (element) {
            case 1:
                strcpy(elementName, "Hydrogen");
                break;
            case 6:
                strcpy(elementName, "Carbon");
                break;
            case 7:
                strcpy(elementName, "Nitrogen");
                break;
            case 8:
                strcpy(elementName, "Oxygen");
                break;
            case 79:
                strcpy(elementName, "Gold");
                break;
            default:
                sprintf(elementName, "Element %d", element); // For elements not listed above
        }

        printf("Question %d: What is the name of element with atomic number %d? ", i + 1, element);
        char userAnswer[50];
        scanf("%s", userAnswer);

        if (strcmp(userAnswer, elementName) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", elementName);
        }
    }

    printf("You scored %d out of %d questions correct.\n", score, numQuestions);
    printf("Would you like to play again? (y/n) ");
    scanf(" %c", &playAgain);

    if (playAgain == 'y' || playAgain == 'Y') {
        main();
    } else {
        printf("Thanks for playing!\n");
        return 0;
    }
}