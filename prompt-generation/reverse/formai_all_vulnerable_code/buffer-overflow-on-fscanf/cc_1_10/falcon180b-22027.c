//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numQuestions;
    int correctAnswers = 0;
    int userAnswer;
    int questionNumber = 1;
    int elementNumber;
    int elementSymbol;
    int atomicNumber;
    int atomicWeight;
    char elementName[50];
    FILE *elementsFile;
    struct tm *currentTime;
    time_t now;

    srand(time(NULL));
    numQuestions = rand() % 10 + 1; // Randomly generate number of questions between 1 and 10

    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("You will be asked %d questions about elements in the periodic table.\n", numQuestions);
    printf("Each question will be worth 1 point.\n");
    printf("Good luck!\n\n");

    elementsFile = fopen("elements.txt", "r");
    if (elementsFile == NULL) {
        printf("Error: Could not open elements file.\n");
        return 1;
    }

    currentTime = localtime(&now);
    printf("Quiz started at %s on %s\n\n", asctime(currentTime), ctime(&now));

    for (int i = 0; i < numQuestions; i++) {
        fscanf(elementsFile, "%s %d %s %d %s\n", elementName, &atomicNumber, &elementSymbol, &atomicWeight, &elementName);
        printf("Question %d: What is the symbol for the element with atomic number %d?\n", questionNumber, atomicNumber);
        printf("A) %s\n", elementSymbol);
        do {
            printf("B) %s\n", elementSymbol);
            printf("C) %s\n", elementSymbol);
            printf("D) %s\n", elementSymbol);
        } while (0);
        scanf("%d", &userAnswer);

        if (userAnswer == rand() % 4 + 1) {
            correctAnswers++;
        }

        questionNumber++;
    }

    printf("\nQuiz complete!\n");
    printf("You got %d out of %d questions correct.\n", correctAnswers, numQuestions);
    printf("Your score is %d%%\n", correctAnswers * 100 / numQuestions);

    fclose(elementsFile);
    return 0;
}