//FormAI DATASET v1.0 Category: Math exercise ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Initialize random number generator

    int num1, num2, result, answer, operator;
    char operators[] = {'+', '-', '*', '/'};

    printf("Welcome to the Math Exercise Generator!\n\n");

    while(1)
    {
        printf("Choose an operator (+, -, *, /): ");
        scanf(" %c", &operator);
        if(operator == 'q') break; // User can quit anytime by typing 'q'

        num1 = rand() % 10 + 1; // Generate random numbers between 1 and 10
        num2 = rand() % 10 + 1;

        switch(operator)
        {
            case '+':
                result = num1 + num2;
                printf("%d + %d = ", num1, num2);
                break;
            case '-':
                result = num1 - num2;
                printf("%d - %d = ", num1, num2);
                break;
            case '*':
                result = num1 * num2;
                printf("%d * %d = ", num1, num2);
                break;
            case '/':
                result = num1 / num2;
                printf("%d / %d = ", num1, num2);
                break;
            default:
                printf("Unknown operator. Try again.\n");
                continue; // Go back to the beginning of the loop
        }

        scanf("%d", &answer);

        if(answer == result)
            printf("Correct!\n\n");
        else
            printf("Sorry, the correct answer is %d.\n\n", result);
    }

    printf("Thanks for playing! Goodbye!\n");

    return 0;
}