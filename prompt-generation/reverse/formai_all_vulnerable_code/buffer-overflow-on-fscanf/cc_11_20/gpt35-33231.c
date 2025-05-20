//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: portable
#include <stdio.h>
#include <string.h>

struct Element {
    char symbol[3];
    char name[25];
    int atomicNumber;
    float atomicMass;
};

int main() {
    struct Element periodicTable[118];
    FILE *inputFile = fopen("periodicTable.txt", "r");

    // load the periodic table data from the input file
    if (inputFile != NULL) {
        int i = 0;
        while (!feof(inputFile) && i < 118) {
            fscanf(inputFile, "%s %s %d %f", periodicTable[i].symbol, periodicTable[i].name, &periodicTable[i].atomicNumber, &periodicTable[i].atomicMass);
            i++;
        }
        fclose(inputFile);
    } else {
        printf("Failed to read periodicTable.txt file.");
        return 1;
    }

    // print the periodic table menu
    printf("Welcome to the Periodic Table Quiz!\n\n");
    printf("Please select a category:\n");
    printf("1. Elements by Symbol\n");
    printf("2. Elements by Name\n");
    printf("3. Elements by Atomic Number\n");
    printf("4. Elements by Atomic Mass\n");

    // get the user's choice
    int categoryChoice;
    printf("\nChoice: ");
    scanf("%d", &categoryChoice);

    // prompt the user with the questions according to their choice
    if (categoryChoice == 1) {
        char userAnswer[3];
        int numCorrectAnswers = 0;

        printf("\nEnter 'q' to quit the quiz at any time.\n");

        for (int i = 0; i < 118; i++) {
            printf("\nWhat element has the symbol '%s'? ", periodicTable[i].symbol);
            scanf("%s", userAnswer);

            if (strcmp(userAnswer, "q") == 0) {
                break;
            }

            if (strcmp(userAnswer, periodicTable[i].symbol) == 0) {
                printf("Correct!");
                numCorrectAnswers++;
            } else {
                printf("Incorrect. The correct answer is %s.", periodicTable[i].name);
            }

            printf("\nYour Score: %d/%d", numCorrectAnswers, i + 1);
        }
    } else if (categoryChoice == 2) {
        char userAnswer[25];
        int numCorrectAnswers = 0;

        printf("\nEnter 'q' to quit the quiz at any time.\n");

        for (int i = 0; i < 118; i++) {
            printf("\nWhat is the name of the element with the symbol '%s'? ", periodicTable[i].symbol);
            scanf("%s", userAnswer);

            if (strcmp(userAnswer, "q") == 0) {
                break;
            }

            if (strcmp(userAnswer, periodicTable[i].name) == 0) {
                printf("Correct!");
                numCorrectAnswers++;
            } else {
                printf("Incorrect. The correct answer is %s.", periodicTable[i].name);
            }

            printf("\nYour Score: %d/%d", numCorrectAnswers, i + 1);
        }
    } else if (categoryChoice == 3) {
        int userAnswer;
        int numCorrectAnswers = 0;

        printf("\nEnter '0' to quit the quiz at any time.\n");

        for (int i = 0; i < 118; i++) {
            printf("\nWhat is the atomic number of %s? ", periodicTable[i].name);
            scanf("%d", &userAnswer);

            if (userAnswer == 0) {
                break;
            }

            if (userAnswer == periodicTable[i].atomicNumber) {
                printf("Correct!");
                numCorrectAnswers++;
            } else {
                printf("Incorrect. The correct answer is %d.", periodicTable[i].atomicNumber);
            }

            printf("\nYour Score: %d/%d", numCorrectAnswers, i + 1);
        }
    } else if (categoryChoice == 4) {
        float userAnswer;
        int numCorrectAnswers = 0;

        printf("\nEnter '0' to quit the quiz at any time.\n");

        for (int i = 0; i < 118; i++) {
            printf("\nWhat is the atomic mass of %s? ", periodicTable[i].name);
            scanf("%f", &userAnswer);

            if (userAnswer == 0) {
                break;
            }

            if (userAnswer == periodicTable[i].atomicMass) {
                printf("Correct!");
                numCorrectAnswers++;
            } else {
                printf("Incorrect. The correct answer is %.2f.", periodicTable[i].atomicMass);
            }

            printf("\nYour Score: %d/%d", numCorrectAnswers, i + 1);
        }
    } else {
        printf("Invalid choice. Please try again.");
    }

    return 0;
}