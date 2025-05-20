//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int numElements = rand() % 118 + 1;
    int numQuestions = rand() % 10 + 1;
    int score = 0;
    char symbol[3];
    char name[50];
    int atomicNumber;
    int correctAnswers = 0;

    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("In this quiz, you will be asked %d questions about the elements in the periodic table.\n", numQuestions);
    printf("Each question will give you a symbol or name of an element, and you must answer with its atomic number.\n");
    printf("Good luck!\n");

    for (int i = 0; i < numElements; i++) {
        atomicNumber = rand() % 118 + 1;
        strcpy(name, "");
        strcpy(symbol, "");
        if (atomicNumber == 1) {
            strcpy(name, "Hydrogen");
            strcpy(symbol, "H");
        } else if (atomicNumber == 6) {
            strcpy(name, "Carbon");
            strcpy(symbol, "C");
        } else if (atomicNumber == 7) {
            strcpy(name, "Nitrogen");
            strcpy(symbol, "N");
        } else if (atomicNumber == 8) {
            strcpy(name, "Oxygen");
            strcpy(symbol, "O");
        } else if (atomicNumber == 79) {
            strcpy(name, "Gold");
            strcpy(symbol, "Au");
        } else {
            sprintf(name, "Element %d", atomicNumber);
            sprintf(symbol, "%c", 'A' + (atomicNumber - 1));
        }

        int questionType = rand() % 2;
        if (questionType == 0) {
            printf("Question %d: What is the atomic number of %s?\n", i + 1, name);
        } else {
            printf("Question %d: What is the atomic number of %c?\n", i + 1, symbol[0]);
        }

        int userAnswer;
        scanf("%d", &userAnswer);

        if (userAnswer == atomicNumber) {
            printf("Correct!\n");
            correctAnswers++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", atomicNumber);
        }
    }

    printf("\nYou got %d out of %d questions correct.\n", correctAnswers, numQuestions);

    return 0;
}