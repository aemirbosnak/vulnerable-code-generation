//Falcon-180B DATASET v1.0 Category: Educational ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

int main()
{
    int num1, num2, result;
    char choice;

    do
    {
        printf("\nEnter your choice:\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
        scanf("%c", &choice);

        switch(choice)
        {
            case '1':
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                result = num1 + num2;
                printf("Result: %d\n", result);
                break;

            case '2':
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                result = num1 - num2;
                printf("Result: %d\n", result);
                break;

            case '3':
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                result = num1 * num2;
                printf("Result: %d\n", result);
                break;

            case '4':
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                if(num2 == 0)
                {
                    printf("Division by zero is not allowed.\n");
                }
                else
                {
                    result = num1 / num2;
                    printf("Result: %d\n", result);
                }
                break;

            default:
                printf("Invalid choice.\n");
        }

        printf("\nDo you want to continue? (Y/N): ");
        scanf("%c", &choice);
    }
    while(choice == 'Y' || choice == 'y');

    return 0;
}