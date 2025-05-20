//FormAI DATASET v1.0 Category: Math exercise ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Introduce program to user
    printf("Welcome! This program will generate a series of math exercise problems for you to solve.\n");

    // Ask user for number of problems to generate
    int numProblems;
    printf("How many problems do you want to generate?\n");
    scanf("%d", &numProblems);

    // Generate random numbers for math problems
    srand(time(0));
    int num1, num2;
    
    // Generate and solve math problems
    int correctAnswers = 0;
    for (int i = 1; i <= numProblems; i++) {
        
        // Generate random numbers between 1 and 100
        num1 = rand() % 100 + 1;
        num2 = rand() % 100 + 1;

        // Choose a random math operation (+, -, *, /)
        char operation;
        int answer, userAnswer;
        switch(rand() % 4) {
            case 0: 
                operation = '+';
                answer = num1 + num2;
                break;
            case 1:
                operation = '-';
                answer = num1 - num2;
                break;
            case 2:
                operation = '*';
                answer = num1 * num2;
                break;
            case 3:
                operation = '/';
                answer = num1 / num2;
                break;
        }

        // Prompt user with math problem and collect user's answer
        printf("\nProblem %d: %d %c %d = ?\n", i, num1, operation, num2);
        scanf("%d", &userAnswer);

        // Check user's answer and provide feedback
        if (userAnswer == answer) {
            printf("Correct!");
            correctAnswers++;
        } else {
            printf("Incorrect. The correct answer is %d.", answer);
        }
    }

    // Calculate and display user's score
    float score = (float) correctAnswers / (float) numProblems * 100;
    printf("\nYou scored %.2f%%.\n", score);

    return 0;
}