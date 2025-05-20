//FormAI DATASET v1.0 Category: Math exercise ; Style: satisfied
/* Welcome to my unique math exercise program! */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, user_ans, correct_ans, i, score = 0;
    char operation;

    printf("Welcome to the Math Exercise Game!\n\n");
    printf("Here is how it works: The computer will randomly choose an\n");
    printf("operation (+, -, *, /) and two numbers between 1 and 100.\n");
    printf("Your job is to solve the problem before time runs out.\n\n");

    srand(time(0)); // Seed the random number generator

    for (i = 1; i <= 10; i++) { // Loop for 10 questions
        if (i == 1) {
            printf("Let's get started!\n");
        } else {
            printf("\nNext question:\n");
        }

        num1 = rand() % 100 + 1; // Generate random numbers
        num2 = rand() % 100 + 1;
        correct_ans = 0; // Initialize the correct answer to 0

        switch (rand() % 4) { // Randomly select an operation
            case 0:
                operation = '+';
                correct_ans = num1 + num2;
                break;
            case 1:
                operation = '-';
                correct_ans = num1 - num2;
                break;
            case 2:
                operation = '*';
                correct_ans = num1 * num2;
                break;
            case 3:
                operation = '/';
                while (num2 == 0) { // Ensure the denominator is not 0
                    num2 = rand() % 100 + 1;
                }
                correct_ans = num1 / num2;
                break;
        }

        printf("Question %d: %d %c %d = ", i, num1, operation, num2);
        scanf("%d", &user_ans);

        if (user_ans == correct_ans) { // Check if the user's answer is correct
            score += 10; // Increase the score by 10 points
            printf("Correct! Your current score is %d.\n", score);
        } else {
            printf("Incorrect. The correct answer is %d. Your score remains %d.\n", correct_ans, score);
        }
    }

    printf("\nTime's up! Your final score is %d out of 100.\n", score);
    if (score >= 80) {
        printf("Well done! You are a math genius!\n");
    } else if (score >= 50) {
        printf("Not bad, but you can do better next time!\n");
    } else {
        printf("Don't worry, practice makes perfect!\n");
    }

    return 0;
}