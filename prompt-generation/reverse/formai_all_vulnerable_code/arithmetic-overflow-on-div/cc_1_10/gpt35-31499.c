//FormAI DATASET v1.0 Category: Educational ; Style: surprised
#include<stdio.h>

int main()
{
    printf("Oh boy, am I surprised to be running on this computer!\n");
    printf("I can't believe it, but I'm actually executing code!\n");
    printf("Let me show you what I can do...\n\n");

    int num1, num2, result;
    char operator;

    printf("Please enter two numbers:\n");
    scanf("%d %d", &num1, &num2);

    printf("\nNow enter an operator (+, -, *, /):\n");
    scanf(" %c", &operator);

    switch(operator)
    {
        case '+':
            result = num1 + num2;
            printf("\n%d + %d = %d\n", num1, num2, result);
            break;

        case '-':
            result = num1 - num2;
            printf("\n%d - %d = %d\n", num1, num2, result);
            break;

        case '*':
            result = num1 * num2;
            printf("\n%d * %d = %d\n", num1, num2, result);
            break;

        case '/':
            if(num2 == 0)
            {
                printf("\n\nError: Cannot divide by zero. Let's try that again.\n");
                main();
            }
            else
            {
                result = num1 / num2;
                printf("\n%d / %d = %d\n", num1, num2, result);
            }
            break;

        default:
            printf("\n\nOperator not recognized. Please try again.\n");
            main();
    }

    printf("\nWow, that was a rush! Hope you enjoyed watching me perform my calculations.\n");
    printf("Until next time, goodbye!");
    return 0;
}