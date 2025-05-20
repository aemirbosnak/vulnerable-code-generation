//FormAI DATASET v1.0 Category: Calculator ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, choice;

    printf("Welcome to BRAVE Calculator\n");

    while(1) {
        printf("\nChoose an operation to perform:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter two numbers: ");
                scanf("%d %d", &num1, &num2);
                printf("%d + %d = %d\n", num1, num2, num1+num2);
                break;
            case 2:
                printf("\nEnter two numbers: ");
                scanf("%d %d", &num1, &num2);
                printf("%d - %d = %d\n", num1, num2, num1-num2);
                break;
            case 3:
                printf("\nEnter two numbers: ");
                scanf("%d %d", &num1, &num2);
                printf("%d * %d = %d\n", num1, num2, num1*num2);
                break;
            case 4:
                printf("\nEnter two numbers: ");
                scanf("%d %d", &num1, &num2);
                if(num2 != 0) {
                    printf("%d / %d = %d\n", num1, num2, num1/num2);
                } else {
                    printf("Cannot divide by zero\n");
                }
                break;
            case 5:
                printf("\nEnter two numbers: ");
                scanf("%d %d", &num1, &num2);
                if(num2 != 0) {
                    printf("%d %% %d = %d\n", num1, num2, num1%num2);
                } else {
                    printf("Cannot divide by zero\n");
                }
                break;
            case 6:
                printf("\nThank you for using BRAVE Calculator!\n");
                exit(0);
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    }
    return 0;
}