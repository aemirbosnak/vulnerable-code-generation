//FormAI DATASET v1.0 Category: Calculator ; Style: relaxed
#include<stdio.h>

int main(){
    int choice, num1, num2, result;
    printf("Welcome to my Calculator program!\n");

    do{
        printf("Please select an operation:\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter two numbers to add:\n");
                scanf("%d%d", &num1, &num2);
                result = num1 + num2;
                printf("The result of %d + %d = %d\n", num1, num2, result);
                break;

            case 2:
                printf("Enter two numbers to subtract:\n");
                scanf("%d%d", &num1, &num2);
                result = num1 - num2;
                printf("The result of %d - %d = %d\n", num1, num2, result);
                break;

            case 3:
                printf("Enter two numbers to multiply:\n");
                scanf("%d%d", &num1, &num2);
                result = num1 * num2;
                printf("The result of %d x %d = %d\n", num1, num2, result);
                break;

            case 4:
                printf("Enter two numbers to divide:\n");
                scanf("%d%d", &num1, &num2);
                if(num2 == 0){
                    printf("Error: division by zero\n");
                    break;
                }
                result = num1 / num2;
                printf("The result of %d / %d = %d\n", num1, num2, result);
                break;

            case 5:
                printf("Thank you for using my Calculator program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please select a number between 1 and 5.\n");
                break;
        }

    }while(choice != 5);

    return 0;
}