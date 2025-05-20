//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: relaxed
#include<stdio.h>
#include<math.h>

int main()
{
    int choice, i;
    double num1, num2, result;
    char operator;

    printf("Enter your choice:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Square root\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter two numbers: ");
            scanf("%lf %c %lf", &num1, &operator, &num2);
            if(operator!= '+')
            {
                printf("Error! Invalid operator.\n");
                return 0;
            }
            result = num1 + num2;
            printf("Result: %lf\n", result);
            break;

        case 2:
            printf("Enter two numbers: ");
            scanf("%lf %c %lf", &num1, &operator, &num2);
            if(operator!= '-')
            {
                printf("Error! Invalid operator.\n");
                return 0;
            }
            result = num1 - num2;
            printf("Result: %lf\n", result);
            break;

        case 3:
            printf("Enter two numbers: ");
            scanf("%lf %c %lf", &num1, &operator, &num2);
            if(operator!= '*')
            {
                printf("Error! Invalid operator.\n");
                return 0;
            }
            result = num1 * num2;
            printf("Result: %lf\n", result);
            break;

        case 4:
            printf("Enter two numbers: ");
            scanf("%lf %c %lf", &num1, &operator, &num2);
            if(operator!= '/')
            {
                printf("Error! Invalid operator.\n");
                return 0;
            }
            if(num2 == 0)
            {
                printf("Error! Division by zero.\n");
                return 0;
            }
            result = num1 / num2;
            printf("Result: %lf\n", result);
            break;

        case 5:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            if(num1 < 0)
            {
                printf("Error! Negative number.\n");
                return 0;
            }
            result = sqrt(num1);
            printf("Result: %lf\n", result);
            break;

        default:
            printf("Invalid choice.\n");
            return 0;
    }

    return 0;
}