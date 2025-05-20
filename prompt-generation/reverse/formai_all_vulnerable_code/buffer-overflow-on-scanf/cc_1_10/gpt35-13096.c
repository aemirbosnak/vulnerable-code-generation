//FormAI DATASET v1.0 Category: Math exercise ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, operator, answer, userAnswer, numCorrect = 0, numWrong = 0;
    srand(time(0)); // Seed for random number generation
    
    printf("Welcome to the Math Quiz!\n\n");

    for (int i = 0; i < 10; i++) { // 10 questions
        num1 = rand() % 100; // Generate random number between 0 and 99
        num2 = rand() % 100;
        operator = rand() % 3; // 0 for addition, 1 for subtraction, 2 for multiplication

        switch (operator) { // Determine which operator to use
            case 0:
                answer = num1 + num2;
                printf("%d + %d = ", num1, num2);
                break;
            case 1:
                answer = num1 - num2;
                printf("%d - %d = ", num1, num2);
                break;
            case 2:
                answer = num1 * num2;
                printf("%d * %d = ", num1, num2);
                break;
            default:
                break;
        }

        scanf("%d", &userAnswer); // Get user input

        if (userAnswer == answer) { // Check if user's answer is correct
            printf("Correct!\n\n");
            numCorrect++;
        } else {
            printf("Incorrect. The correct answer is %d.\n\n", answer);
            numWrong++;
        }
    }

    printf("You got %d questions correct and %d questions wrong.\n", numCorrect, numWrong);

    if (numCorrect >= 8) { // Determine quiz result
        printf("Great job! You passed the quiz.\n");
    } else {
        printf("Next time, try harder!\n");
    }

    return 0;
}