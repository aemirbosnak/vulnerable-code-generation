//FormAI DATASET v1.0 Category: Math exercise ; Style: relaxed
// Welcome to the Math Exercise Program!
// In this program, we will be generating random math exercises for you to solve.
// Let's get started!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, answer, userAnswer, difficulty, questionNum, correctAnswers;
    char operator;

    srand(time(NULL));  // Seed the random number generator

    printf("Welcome to the Math Exercise Program!\n");
    printf("Please choose a difficulty level:\n");
    printf("1. Easy\n2. Medium\n3. Hard\n");

    // Get the difficulty level from the user
    scanf("%d", &difficulty);

    // Set the maximum value of the numbers based on the difficulty level
    switch (difficulty) {
        case 1:
            num1 = rand() % 10;
            num2 = rand() % 10;
            break;
        case 2:
            num1 = rand() % 100;
            num2 = rand() % 100;
            break;
        case 3:
            num1 = rand() % 1000;
            num2 = rand() % 1000;
            break;
        default:
            printf("Invalid difficulty level selected.\n");
            return 1;
    }

    // Get the number of questions from the user
    printf("How many questions do you want to answer? (Maximum is 10)\n");
    scanf("%d", &questionNum);

    // Make sure the number of questions is between 1 and 10
    if (questionNum < 1 || questionNum > 10) {
        printf("Invalid number of questions selected.\n");
        return 1;
    }

    // Start asking the questions
    correctAnswers = 0;
    for (int i = 1; i <= questionNum; i++) {
        // Generate a random operator
        switch (rand() % 4) {
            case 0:
                operator = '+';
                answer = num1 + num2;
                break;
            case 1:
                operator = '-';
                answer = num1 - num2;
                break;
            case 2:
                operator = '*';
                answer = num1 * num2;
                break;
            case 3:
                operator = '/';
                answer = num1 / num2;
                break;
        }

        // Ask the question
        printf("Question %d: What is %d %c %d?\n", i, num1, operator, num2);

        // Get the user's answer
        scanf("%d", &userAnswer);

        // Check if the answer is correct
        if (userAnswer == answer) {
            printf("Correct!\n");
            correctAnswers++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", answer);
        }

        // Generate new random numbers
        num1 = rand() % 10;
        num2 = rand() % 10;
    }

    // Print the final score
    printf("You answered %d out of %d questions correctly.\n", correctAnswers, questionNum);

    return 0;
}