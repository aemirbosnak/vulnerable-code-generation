//FormAI DATASET v1.0 Category: Arithmetic ; Style: scalable
#include<stdio.h>

int main(){
    int num1, num2, result, operation;
    char choice;
    printf("Welcome to Calculator\n");
    do{
        printf("\n\n\nPlease select an operation\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Modulus\n6. Exit\n");
        printf("Your option: ");
        scanf("%d", &operation);

        if(operation == 6){
            break;
        }
        printf("\nEnter two numbers: ");
        scanf("%d%d", &num1, &num2);

        switch(operation){
            case 1:
                result = num1 + num2;
                printf("The sum of %d and %d is %d", num1, num2, result);
                break;
            case 2:
                result = num1 - num2;
                printf("The difference between %d and %d is %d", num1, num2, result);
                break;
            case 3:
                result = num1 * num2;
                printf("The product of %d and %d is %d", num1, num2, result);
                break;
            case 4:
                if(num2 == 0){
                    printf("Cannot divide by zero");
                }
                else{
                    result = num1 / num2;
                    printf("%d divided by %d is %d", num1, num2, result);
                }
                break;
            case 5:
                result = num1 % num2;
                printf("The modulus of %d and %d is %d", num1, num2, result);
                break;
            default:
                printf("Invalid Choice");
        }
        printf("\nDo you want to continue (y/n)? ");
        scanf(" %c", &choice);
    }while(choice == 'y' || choice == 'Y');
    return 0;
}