//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: authentic
#include <stdio.h>

int main()
{
    int num1, num2, sum;
    char operator;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("Enter the operator (+, -, *, /): ");
    scanf(" %c", &operator);

    switch(operator)
    {
        case '+':
            sum = num1 + num2;
            printf("The sum of %d and %d is %d", num1, num2, sum);
            break;

        case '-':
            sum = num1 - num2;
            printf("The difference between %d and %d is %d", num1, num2, sum);
            break;

        case '*':
            sum = num1 * num2;
            printf("The product of %d and %d is %d", num1, num2, sum);
            break;

        case '/':
            if(num2 == 0)
            {
                printf("Division by zero is not allowed");
            }
            else
            {
                sum = num1 / num2;
                printf("The quotient of %d and %d is %d", num1, num2, sum);
            }
            break;

        default:
            printf("Invalid operator!");
    }

    return 0;
}