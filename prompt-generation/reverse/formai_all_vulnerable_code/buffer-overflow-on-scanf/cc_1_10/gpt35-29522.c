//FormAI DATASET v1.0 Category: Math exercise ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    printf("Welcome to the Genious C Math Exercise program!\n\n");
    printf("In this program, you will be presented with a series of math problems that will test your knowledge and problem-solving skills.\n");
    printf("Are you ready to begin? Let's get started!\n\n");
    
    int counter = 0; // Keeps track of number of correct answers
    int num_problems = 10; // Number of problems to solve
    int user_answer; // Holds user's answer
    int answer; // Holds correct answer
    int operand1, operand2; // Operands for random arithmetic expressions
    char operator; // Holds operator to be used in random arithmetic expressions
    
    // Seed random number generator with current time
    srand(time(0));
    
    // Loop through each problem
    for(int i = 1; i <= num_problems; i++)
    {
        printf("Problem %d:\n", i);
        
        // Generate random arithmetic expression using two operands and one operator
        operand1 = rand() % 100 + 1; // Generates random operand1 from 1 to 100
        operand2 = rand() % 100 + 1; // Generates random operand2 from 1 to 100
        switch(rand() % 4) // Generates random operator (+, -, *, or /)
        {
            case 0:
                operator = '+';
                answer = operand1 + operand2;
                break;
            case 1:
                operator = '-';
                answer = operand1 - operand2;
                break;
            case 2:
                operator = '*';
                answer = operand1 * operand2;
                break;
            case 3:
                operator = '/';
                answer = operand1 / operand2;
                break;
        }
        
        // Display arithmetic expression and prompt user for answer
        printf("%d %c %d = ?\n", operand1, operator, operand2);
        printf("Your answer: ");
        scanf("%d", &user_answer);
        
        // Check if user's answer is correct and provide feedback
        if(user_answer == answer)
        {
            printf("Correct!\n");
            counter++;
        }
        else
        {
            printf("Incorrect. The correct answer is %d.\n", answer);
        }
        
        printf("\n");
    }
    
    // Display final score and congratulations message
    printf("Congratulations! You have completed all %d problems.\n", num_problems);
    printf("Your final score is %d out of %d.\n", counter, num_problems);
    if(counter == num_problems)
    {
        printf("You are a genious at math!\n");
    }
    else
    {
        printf("Keep practicing and you will become a genious at math!\n");
    }
    
    return 0;
}