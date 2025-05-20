//FormAI DATASET v1.0 Category: Math exercise ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, userAnswer, correctAnswer, option;
    char operator;
    srand(time(NULL));  // seed random number function with current time

    printf("Welcome to the Math Exercise Program!\n\n");

    while(1) {  // infinite loop until user chooses to quit
        // randomly generate two numbers between 1 and 100 inclusive
        num1 = rand() % 100 + 1;  
        num2 = rand() % 100 + 1;

        // randomly choose an arithmetic operator (+, -, or *)
        option = rand() % 3;
        switch(option) {
            case 0:
                operator = '+';
                correctAnswer = num1 + num2;
                break;
            case 1:
                operator = '-';
                correctAnswer = num1 - num2;
                break;
            case 2:
                operator = '*';
                correctAnswer = num1 * num2;
                break;
        }

        // ask user to solve the equation and take input
        printf("What is %d %c %d? ", num1, operator, num2);
        scanf("%d", &userAnswer);

        // check if the answer is correct and provide feedback
        if(userAnswer == correctAnswer) {
            printf("Congratulations! Your answer is correct.\n\n");
        }
        else {
            printf("Sorry, your answer is incorrect. The correct answer is %d.\n\n", correctAnswer);
        }

        // ask user if they want to continue or quit
        printf("Do you want to solve another math exercise? (1 for Yes, 0 for No) ");
        scanf("%d", &option);
        printf("\n");

        if(!option) {
            printf("Thank you for using the Math Exercise Program. Goodbye!\n");
            break;  // break out of infinite loop if user chooses to quit
        }
    }

    return 0;
}