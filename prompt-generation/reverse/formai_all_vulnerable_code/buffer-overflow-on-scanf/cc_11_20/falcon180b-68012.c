//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: inquisitive
#include <stdio.h>

int main() {
    int choice, correct = 0, wrong = 0;

    printf("Welcome to the Periodic Table Quiz!\n\n");

    do {
        printf("Select a difficulty level:\n");
        printf("1. Easy\n2. Medium\n3. Hard\n");
        scanf("%d", &choice);

        if (choice < 1 || choice > 3) {
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice < 1 || choice > 3);

    int numQuestions, i;

    switch (choice) {
        case 1:
            numQuestions = 10;
            break;
        case 2:
            numQuestions = 20;
            break;
        case 3:
            numQuestions = 30;
            break;
    }

    printf("You will be asked %d questions.\n\n", numQuestions);

    for (i = 0; i < numQuestions; i++) {
        int elementNum, correctAnswer;

        printf("Question %d:\n", i + 1);
        printf("What element has the atomic number %d?\n", elementNum);

        scanf("%d", &elementNum);

        if (elementNum < 1 || elementNum > 118) {
            printf("Invalid answer. Please try again.\n");
            continue;
        }

        correctAnswer = elementNum;

        if (correctAnswer == elementNum) {
            printf("Correct!\n");
            correct++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", correctAnswer);
            wrong++;
        }
    }

    printf("\nYou got %d out of %d questions correct.\n", correct, numQuestions);

    if (correct >= numQuestions / 2) {
        printf("You passed the quiz!\n");
    } else {
        printf("Sorry, you didn't pass the quiz.\n");
    }

    return 0;
}