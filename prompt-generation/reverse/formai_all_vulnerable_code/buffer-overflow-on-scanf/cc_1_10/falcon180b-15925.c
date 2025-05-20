//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: imaginative
#include <stdio.h>
#include <math.h>

int main()
{
    int num1, num2, operator;
    char choice;

    printf("Enter the number of calculations you want to perform: ");
    scanf("%d", &num1);

    //Loop to perform calculations
    for(int i=0; i<num1; i++)
    {
        printf("Enter the first number: ");
        scanf("%d", &num2);

        printf("Enter the operator (+, -, *, /): ");
        scanf(" %c", &operator);

        switch(operator)
        {
            case '+':
                printf("The sum of %d and %d is %d", num2, num2, num2+num2);
                break;

            case '-':
                printf("The difference between %d and %d is %d", num2, num2, num2-num2);
                break;

            case '*':
                printf("The product of %d and %d is %d", num2, num2, num2*num2);
                break;

            case '/':
                if(num2!= 0)
                {
                    printf("The quotient of %d and %d is %.2f", num2, num2, (float)num2/(float)num2);
                }
                else
                {
                    printf("Division by zero is not allowed!");
                }
                break;

            default:
                printf("Invalid operator!");
        }

        printf("\nDo you want to perform another calculation? (Y/N): ");
        scanf(" %c", &choice);

        if(choice == 'N' || choice == 'n')
        {
            break;
        }
    }

    return 0;
}