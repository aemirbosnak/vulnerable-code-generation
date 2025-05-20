//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    char choice;
    int num1, num2, result;
    float num3, num4, sum;

    printf("Enter your choice:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%c", &choice);

    switch(choice)
    {
        case '1':
            printf("Enter two integers:\n");
            scanf("%d%d", &num1, &num2);
            result = num1 + num2;
            printf("Result: %d\n", result);
            break;

        case '2':
            printf("Enter two integers:\n");
            scanf("%d%d", &num1, &num2);
            result = num1 - num2;
            printf("Result: %d\n", result);
            break;

        case '3':
            printf("Enter two integers:\n");
            scanf("%d%d", &num1, &num2);
            result = num1 * num2;
            printf("Result: %d\n", result);
            break;

        case '4':
            printf("Enter two integers:\n");
            scanf("%d%d", &num1, &num2);
            if(num2 == 0)
            {
                printf("Error! Division by zero is not allowed.\n");
            }
            else
            {
                result = num1 / num2;
                printf("Result: %.2f\n", result);
            }
            break;

        case '5':
            printf("Enter two floating point numbers:\n");
            scanf("%f%f", &num3, &num4);
            sum = num3 + num4;
            printf("Result: %.2f\n", sum);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}