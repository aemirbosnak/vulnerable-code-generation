//FormAI DATASET v1.0 Category: Arithmetic ; Style: beginner-friendly
#include<stdio.h>

int main(){

    int num1, num2, option, result;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("\nWhat operation do you want to perform?");
    printf("\n1) Addition  2) Subtraction    3) Multiplication    4) Division\n");
    scanf("%d", &option);

    switch(option){

        case 1:
            result = num1 + num2;
            printf("\n%d + %d = %d\n", num1, num2, result);
            break;

        case 2:
            result = num1 - num2;
            printf("\n%d - %d = %d\n", num1, num2, result);
            break;

        case 3:
            result = num1 * num2;
            printf("\n%d x %d = %d\n", num1, num2, result);
            break;

        case 4:
            if(num2 == 0){
                printf("\nError: division by zero\n");
                break;
            } else {
                result = num1 / num2;
                printf("\n%d / %d = %d\n", num1, num2, result);
                break;
            }

        default:
            printf("\nInvalid option selected!\n");
            break;
    }

    return 0;
}