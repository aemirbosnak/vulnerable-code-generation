//FormAI DATASET v1.0 Category: Calculator ; Style: happy
#include <stdio.h>

int add(int x, int y){
    return x + y;
}

int subtract(int x, int y){
    return x - y;
}

int multiply(int x, int y){
    return x * y;
}

float divide(int x, int y){
    return (float)x / y;
}

int main(){
    int num1, num2;
    char operator;

    printf("Hello! I'm a happy calculator bot!\n");
    printf("Please enter the first number: ");
    scanf("%d", &num1);
    printf("Please enter the operator (+, -, *, /): ");
    scanf(" %c", &operator);
    printf("Please enter the second number: ");
    scanf("%d", &num2);
    
    switch(operator) {
        case '+':
            printf("Result: %d\n", add(num1, num2));
            break;
        case '-':
            printf("Result: %d\n", subtract(num1, num2));
            break;
        case '*':
            printf("Result: %d\n", multiply(num1, num2));
            break;
        case '/':
            printf("Result: %.2f\n", divide(num1, num2));
            break;
        default:
            printf("Invalid operator!\n");
            break;
    }
    
    printf("Thank you for using the happy calculator bot! I hope to see you soon!\n");
    
    return 0;
}