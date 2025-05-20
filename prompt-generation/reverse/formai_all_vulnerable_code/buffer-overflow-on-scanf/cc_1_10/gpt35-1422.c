//FormAI DATASET v1.0 Category: Math exercise ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Setup random number generator
    srand(time(NULL));
    
    // Generate two random numbers between 1 and 10
    int num1 = rand() % 10 + 1;
    int num2 = rand() % 10 + 1;
    
    // Print problem prompt
    printf("What is the result of %d multiplied by %d?\n", num1, num2);
    
    // Get user input
    int userAnswer;
    scanf("%d", &userAnswer);
    
    // Calculate correct answer and check user's answer
    int correctAnswer = num1 * num2;
    if (userAnswer == correctAnswer) {
        printf("Congratulations! Your answer is correct.\n");
    } else {
        printf("Sorry, your answer is incorrect. The correct answer is %d.\n", correctAnswer);
    }
    
    // Repeat the process for addition, subtraction, and division
    num1 = rand() % 10 + 1;
    num2 = rand() % 10 + 1;
    printf("What is the result of %d plus %d?\n", num1, num2);
    scanf("%d", &userAnswer);
    correctAnswer = num1 + num2;
    if (userAnswer == correctAnswer) {
        printf("Congratulations! Your answer is correct.\n");
    } else {
        printf("Sorry, your answer is incorrect. The correct answer is %d.\n", correctAnswer);
    }
    
    num1 = rand() % 10 + 1;
    num2 = rand() % 10 + 1;
    printf("What is the result of %d minus %d?\n", num1, num2);
    scanf("%d", &userAnswer);
    correctAnswer = num1 - num2;
    if (userAnswer == correctAnswer) {
        printf("Congratulations! Your answer is correct.\n");
    } else {
        printf("Sorry, your answer is incorrect. The correct answer is %d.\n", correctAnswer);
    }
    
    num1 = rand() % 10 + 1;
    num2 = rand() % 9 + 1; // Avoid division by 0
    printf("What is the result of %d divided by %d (rounded to the nearest integer)?\n", num1, num2);
    scanf("%d", &userAnswer);
    correctAnswer = num1 / num2;
    if (userAnswer == correctAnswer) {
        printf("Congratulations! Your answer is correct.\n");
    } else {
        printf("Sorry, your answer is incorrect. The correct answer is %d.\n", correctAnswer);
    }
    
    return 0;
}