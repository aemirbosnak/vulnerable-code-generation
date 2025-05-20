//FormAI DATASET v1.0 Category: Math exercise ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set up variables
    int num1, num2, answer, userAnswer;
    char operator;
    int correctAnswers = 0, incorrectAnswers = 0;
    time_t t;
    
    // Initialize random seed
    srand((unsigned) time(&t));
    
    // Display instructions and get number of questions
    int numQuestions;
    printf("Welcome to the Math Quiz Game!\n");
    printf("You will be asked a series of math questions to test your math skills.\n");
    printf("Please enter the number of questions you would like to answer: ");
    scanf("%d", &numQuestions);
    
    // Loop through the number of questions specified
    for (int i = 1; i <= numQuestions; i++) {
        // Generate random numbers between 1 and 100
        num1 = rand() % 100 + 1;
        num2 = rand() % 100 + 1;
        
        // Generate random operator
        int opNum = rand() % 4;
        if (opNum == 0) {
            operator = '+';
            answer = num1 + num2;
        } else if (opNum == 1) {
            operator = '-';
            answer = num1 - num2;
        } else if (opNum == 2) {
            operator = '*';
            answer = num1 * num2;
        } else {
            operator = '/';
            answer = num1 / num2;
        }
        
        // Display question and get user answer
        printf("\nQuestion %d:\n", i);
        printf("%d %c %d = ", num1, operator, num2);
        scanf("%d", &userAnswer);
        
        // Check if user answer is correct and keep score
        if (userAnswer == answer) {
            printf("Correct!\n");
            correctAnswers++;
        } else {
            printf("Incorrect. The answer was %d.\n", answer);
            incorrectAnswers++;
        }
    }
    
    // Display final score
    printf("\nYou answered %d questions correctly and %d questions incorrectly.\n", correctAnswers, incorrectAnswers);
    
    return 0;
}