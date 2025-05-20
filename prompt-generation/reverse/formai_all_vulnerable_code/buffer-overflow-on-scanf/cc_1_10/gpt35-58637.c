//FormAI DATASET v1.0 Category: Math exercise ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, operator, result, answer, score = 0;

    printf("\n===== MATH QUIZ =====\n");

    srand(time(0)); // Seed for randomness

    for (int i = 0; i < 10; i++) { // 10 questions
        num1 = rand() % 10 + 1; // Random number between 1-10
        num2 = rand() % 10 + 1;
        operator = rand() % 4; // Random operator (+, -, *, /)

        switch (operator) {
            case 0:
                result = num1 + num2;
                printf("\n%d + %d = ", num1, num2);
                break;
            case 1:
                result = num1 - num2;
                printf("\n%d - %d = ", num1, num2);
                break;
            case 2:
                result = num1 * num2;
                printf("\n%d * %d = ", num1, num2);
                break;
            case 3:
                result = num1 / num2;
                printf("\n%d / %d = ", num1, num2);
                break;
        }

        scanf("%d", &answer); // Read user input

        if (answer == result) { // Check if answer is correct
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", result);
        }
    }

    printf("\nYou scored %d out of 10.\n", score);

    if (score >= 7) {
        printf("Congratulations! You passed the quiz.\n");
    } else {
        printf("Sorry, you didn't pass the quiz. Better luck next time!\n");
    }

    return 0;
}