//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int choice;
    float num1, num2, result;
    char operator;
    
    while(1)
    {
        printf("\nEnter your choice:\n");
        printf("1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Square Root\n6.Logarithm\n7.Exit\n");
        scanf("%d", &choice);
        
        if(choice == 7)
        {
            printf("Exiting calculator...\n");
            break;
        }

        switch(choice)
        {
            case 1:
                printf("Enter two numbers to add: ");
                scanf("%f %f", &num1, &num2);
                result = num1 + num2;
                printf("Result: %.2f\n", result);
                break;

            case 2:
                printf("Enter two numbers to subtract: ");
                scanf("%f %f", &num1, &num2);
                result = num1 - num2;
                printf("Result: %.2f\n", result);
                break;

            case 3:
                printf("Enter two numbers to multiply: ");
                scanf("%f %f", &num1, &num2);
                result = num1 * num2;
                printf("Result: %.2f\n", result);
                break;

            case 4:
                printf("Enter two numbers to divide: ");
                scanf("%f %f", &num1, &num2);
                result = num1 / num2;
                printf("Result: %.2f\n", result);
                break;

            case 5:
                printf("Enter a number to find square root: ");
                scanf("%f", &num1);
                if(num1 < 0)
                {
                    printf("Invalid number.\n");
                    break;
                }
                result = sqrt(num1);
                printf("Result: %.2f\n", result);
                break;

            case 6:
                printf("Enter a number to find logarithm (base 10): ");
                scanf("%f", &num1);
                if(num1 <= 0)
                {
                    printf("Invalid number.\n");
                    break;
                }
                result = log10(num1);
                printf("Result: %.2f\n", result);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}