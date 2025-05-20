//FormAI DATASET v1.0 Category: Math exercise ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set up random number generator
    srand(time(NULL));
    
    // Generate two random numbers between 1 and 10
    int num1 = rand() % 10 + 1;
    int num2 = rand() % 10 + 1;
    
    // Display the problem for the user to solve
    printf("Welcome to Math Fun!\n");
    printf("What is %d + %d ?\n", num1, num2);
    
    // Get user's answer
    int userAnswer;
    scanf("%d", &userAnswer);
    
    // Check if the answer is correct
    int correctAnswer = num1 + num2;
    if (userAnswer == correctAnswer) {
        printf("Awesome! You got it right!\n");
    } else {
        printf("Oops! You got it wrong. The correct answer is %d.\n", correctAnswer);
    }
    
    // Generate two more random numbers and a random operator to create a new problem
    int num3 = rand() % 10 + 1;
    int num4 = rand() % 10 + 1;
    char operator = rand() % 2 == 0 ? '+' : '-';
    
    // Display the new problem for the user to solve
    printf("Let's try another one!\n");
    printf("What is %d %c %d ?\n", num3, operator, num4);
    
    // Get user's answer
    int userAnswer2;
    scanf("%d", &userAnswer2);
    
    // Check if the answer is correct
    int correctAnswer2 = operator == '+' ? num3 + num4 : num3 - num4;
    if (userAnswer2 == correctAnswer2) {
        printf("Great job! You got it right!\n");
    } else {
        printf("Oh no! You got it wrong. The correct answer is %d.\n", correctAnswer2);
    }
    
    // Generate two more random numbers and a random operator to create a new problem
    int num5 = rand() % 10 + 1;
    int num6 = rand() % 10 + 1;
    char operator2 = rand() % 2 == 0 ? '*' : '/';
    
    // Display the new problem for the user to solve
    printf("One more problem!\n");
    printf("What is %d %c %d ?\n", num5, operator2, num6);
    
    // Get user's answer
    int userAnswer3;
    scanf("%d", &userAnswer3);
    
    // Check if the answer is correct
    int correctAnswer3 = operator2 == '*' ? num5 * num6 : num5 / num6;
    if (userAnswer3 == correctAnswer3) {
        printf("Fantastic! You got it right!\n");
    } else {
        printf("Oops! You got it wrong. The correct answer is %d.\n", correctAnswer3);
    }
    
    printf("Thanks for playing Math Fun! Have a great day!\n");
    
    return 0;
}