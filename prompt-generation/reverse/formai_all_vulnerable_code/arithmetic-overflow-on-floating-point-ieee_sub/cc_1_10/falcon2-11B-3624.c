//Falcon2-11B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Dennis Ritchie
#include<stdio.h>
#include<math.h>

int main()
{
    int option, number, operator, result = 0;
    float num1, num2, n, p;

    do
    {
        printf("1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Square root\n6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&option);

        switch(option)
        {
            case 1:
                printf("Enter the first number: ");
                scanf("%f",&num1);
                printf("Enter the second number: ");
                scanf("%f",&num2);
                result = num1 + num2;
                printf("Result: %f",result);
                break;

            case 2:
                printf("Enter the first number: ");
                scanf("%f",&num1);
                printf("Enter the second number: ");
                scanf("%f",&num2);
                result = num1 - num2;
                printf("Result: %f",result);
                break;

            case 3:
                printf("Enter the first number: ");
                scanf("%f",&num1);
                printf("Enter the second number: ");
                scanf("%f",&num2);
                result = num1 * num2;
                printf("Result: %f",result);
                break;

            case 4:
                printf("Enter the first number: ");
                scanf("%f",&num1);
                printf("Enter the second number: ");
                scanf("%f",&num2);
                result = num1 / num2;
                printf("Result: %f",result);
                break;

            case 5:
                printf("Enter the number: ");
                scanf("%f",&num1);
                result = sqrt(num1);
                printf("Result: %f",result);
                break;

            case 6:
                printf("Thank you for using the calculator.\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
        }
    }while(option!=6);

    return 0;
}