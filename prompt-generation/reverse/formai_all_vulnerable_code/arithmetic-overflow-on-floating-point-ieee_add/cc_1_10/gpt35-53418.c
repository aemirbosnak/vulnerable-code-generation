//FormAI DATASET v1.0 Category: Calculator ; Style: happy
#include<stdio.h>

int main(){
    printf("Welcome to the Happy Calculator program! 😊\n");
    printf("This program will perform basic mathematical operations between two numbers.\n");
    printf("Please enter two values to begin:\n");

    float num1, num2, result;
    char operator;

    scanf("%f %f", &num1, &num2);

    printf("Please enter the operator (+, -, *, /) to perform the operation:\n");
    scanf(" %c", &operator);

    switch(operator){
        case '+': 
            result = num1 + num2;
            printf("%.2f + %.2f = %.2f 😃\n", num1, num2, result);
            break;

        case '-': 
            result = num1 - num2;
            printf("%.2f - %.2f = %.2f 😃\n", num1, num2, result);
            break;

        case '*': 
            result = num1 * num2;
            printf("%.2f * %.2f = %.2f 😃\n", num1, num2, result);
            break;

        case '/': 
            if(num2 == 0){
                printf("Oops! Division by zero is not allowed 😕\n");
            }
            else{
                result = num1 / num2;
                printf("%.2f / %.2f = %.2f 😃\n", num1, num2, result);
            }
            break;

        default: 
            printf("Invalid operator selected 😔\n");
            break;
    }

    printf("Thank you for using the Happy Calculator! 😊");

    return 0;
}