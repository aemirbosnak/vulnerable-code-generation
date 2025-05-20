//FormAI DATASET v1.0 Category: Math exercise ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, operator, answer, userAnswer, score = 0;

    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to the Math Test. This test will consist of 10 questions.\n");

    for (int i = 1; i <= 10; i++) {
        num1 = rand() % 10 + 1; // Generate a random number between 1 and 10
        num2 = rand() % 10 + 1; // Generate another random number between 1 and 10

        operator = rand() % 4 + 1; // Generate a random operator

        switch (operator) {
            case 1: // Addition
                answer = num1 + num2;
                printf("%d. %d + %d = ", i, num1, num2);
                break;
            case 2: // Subtraction
                answer = num1 - num2;
                printf("%d. %d - %d = ", i, num1, num2);
                break;
            case 3: // Multiplication
                answer = num1 * num2;
                printf("%d. %d * %d = ", i, num1, num2);
                break;
            case 4: // Division
                answer = num1 / num2;
                printf("%d. %d / %d = ", i, num1, num2);
                break;
        }

        scanf("%d", &userAnswer); // Get the user's answer

        if (userAnswer == answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", answer);
        }
    }

    printf("You got %d out of 10 correct!\n", score);

    return 0;
}