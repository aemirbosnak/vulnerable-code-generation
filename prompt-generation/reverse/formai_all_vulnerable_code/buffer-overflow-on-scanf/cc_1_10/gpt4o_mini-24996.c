//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayMenu() {
    printf("\nWelcome to the Arithmetic Quiz Game!\n");
    printf("Choose an option:\n");
    printf("1. Start the quiz\n");
    printf("2. Exit\n");
    printf("Your choice: ");
}

int generateQuestion(int *num1, int *num2, char *operator) {
    *num1 = rand() % 100; // Generates a number between 0 and 99
    *num2 = rand() % 100; // Generates another number
    int operation = rand() % 4; // Randomly selects an operation

    switch (operation) {
        case 0:
            *operator = '+';
            return *num1 + *num2; // Addition
        case 1:
            *operator = '-';
            return *num1 - *num2; // Subtraction
        case 2:
            *operator = '*';
            return *num1 * *num2; // Multiplication
        case 3:
            *operator = '/';
            if (*num2 != 0) {
                return *num1 / *num2; // Division; check for zero divisor
            } else {
                return generateQuestion(num1, num2, operator); // Try again
            }
    }
    return 0;
}

int main() {
    srand(time(0)); // Seed random number generation
    int choice, num1, num2, answer, userAnswer;
    char operator;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nLet's start the quiz! Answer the following questions:\n");
                int score = 0;
                for (int i = 0; i < 5; i++) { // 5 questions
                    answer = generateQuestion(&num1, &num2, &operator);
                    printf("Question %d: %d %c %d = ?\n", i + 1, num1, operator, num2);
                    printf("Your answer: ");
                    scanf("%d", &userAnswer);

                    if (userAnswer == answer) {
                        printf("Correct!\n");
                        score++;
                    } else {
                        printf("Wrong! The correct answer is %d.\n", answer);
                    }
                }
                printf("\nQuiz finished! Your score: %d out of 5\n", score);
                break;
            case 2:
                printf("Exiting the game. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}