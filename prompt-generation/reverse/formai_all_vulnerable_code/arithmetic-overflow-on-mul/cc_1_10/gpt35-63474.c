//FormAI DATASET v1.0 Category: Calculator ; Style: funny
#include<stdio.h>
#include<stdlib.h>

void main()
{
    int num1, num2, result;
    char operator;

    printf("Welcome to Funny Calculator\n");
    printf("Enter first number:\n");
    scanf("%d", &num1);
    printf("Enter second number:\n");
    scanf("%d", &num2);
    printf("Enter operator (+, -, *, /):\n");
    scanf(" %c", &operator); //need space before %c to ignore newline character

    if(operator == '+')
    {
        result = num1 + num2;
        printf("Hurray! Your answer is %d\n", result);
    }
    else if(operator == '-')
    {
        result = num1 - num2;
        printf("Hohoho!! You got %d\n", result);
    }
    else if(operator == '*')
    {
        result = num1 * num2;
        printf("Yippee! The answer is %d\n", result);
    }
    else if(operator == '/')
    {
        if(num2 == 0)
        {
            printf("You cannot divide by zero, genius!\n");
        }
        else
        {
            result = num1 / num2;
            printf("Congrats! You got %d\n", result);
        }
    }
    else
    {
        printf("Invalid Operator! Do you even math, bro?\n");
    }

    printf("Thanks for using Funny Calculator\n");
    printf("You are now one step closer to being a math wizard, ha ha!\n");
    printf("This program was brought to you by Code-Jokes Corporation\n");
    printf("We make code funny, because who said coding can't be fun?\n");

    exit(0);
}