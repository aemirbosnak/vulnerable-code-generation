//FormAI DATASET v1.0 Category: Math exercise ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Welcome message for the user
    printf("Welcome to the Grateful Math Exercise Program!\n");
    printf("We will randomly generate a set of math problems for you.\n");
    printf("Please answer as many questions as possible.\n");
    
    // Variables to store user input and program calculations
    int num_problems, correct_answers = 0, num1, num2, user_answer, correct_answer;
    char operator;
    
    // Ask user for number of problems to generate
    printf("How many problems would you like to solve? ");
    scanf("%d", &num_problems);
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate random math problems and ask user for answers
    for (int i = 1; i <= num_problems; i++) {
        num1 = rand() % 50 + 1;
        num2 = rand() % 50 + 1;
        
        // Randomly choose an operator (+ or -)
        if (rand() % 2 == 0) {
            operator = '+';
            correct_answer = num1 + num2;
        } else {
            operator = '-';
            correct_answer = num1 - num2;
        }
        
        // Ask user for answer
        printf("\nProblem #%d: %d %c %d = ", i, num1, operator, num2);
        scanf("%d", &user_answer);
        
        // Check if user's answer is correct
        if (user_answer == correct_answer) {
            printf("Correct! Thanks for your answer\n");
            correct_answers++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", correct_answer);
        }
    }
    
    // Thank user for using the program and display their score
    printf("\nThank you for using the Grateful Math Exercise Program!\n");
    printf("You answered %d out of %d problems correctly.\n", correct_answers, num_problems);
    
    return 0;
}