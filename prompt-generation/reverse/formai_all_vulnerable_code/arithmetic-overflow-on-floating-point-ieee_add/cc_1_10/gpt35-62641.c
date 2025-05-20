//FormAI DATASET v1.0 Category: Arithmetic ; Style: Cyberpunk
#include<stdio.h>

int main(){

    printf("Welcome to the dystopian world of advanced arithmetic!\n");
    printf("Please enter two numbers to perform calculations on.\n");

    float num1, num2, result;
    char operator;
    scanf("%f%c%f", &num1, &operator, &num2);

    switch(operator){
        case '+':
            result = num1 + num2;
            printf("%.2f plus %.2f is %.2f\n", num1, num2, result);
            break;

        case '-':
            result = num1 - num2;
            printf("%.2f minus %.2f is %.2f\n", num1, num2, result);
            break;

        case '*':
            result = num1 * num2;
            printf("%.2f multiplied by %.2f is %.2f\n", num1, num2, result);
            break;

        case '/':
            if(num2 == 0){
                printf("Division by zero is not allowed in this universe!\n");
                break;
            }
            result = num1 / num2;
            printf("%.2f divided by %.2f is %.2f\n", num1, num2, result);
            break;

        case '%':
            if(num2 == 0){
                printf("Modulo by zero is not allowed in this universe!\n");
                break;
            }
            result = (int)num1 % (int)num2;
            printf("%.2f modulo %.2f is %.2f\n", num1, num2, result);
            break;

        default:
            printf("You have entered an unknown operator. Please try again.\n");
            break;
    }

    printf("Thank you for using our arithmetic program in this dystopian world!\n");

    return 0;
}