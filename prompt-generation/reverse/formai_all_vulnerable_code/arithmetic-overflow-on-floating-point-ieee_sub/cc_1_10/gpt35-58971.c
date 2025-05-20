//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Dennis Ritchie
#include <stdio.h>

float add(float a, float b){
    return a + b;
}

float subtract(float a, float b){
    return a - b;
}

float multiply(float a, float b){
    return a * b;
}

float divide(float a, float b){
    if(b == 0){
        printf("Cannot divide by zero!");
        return -1;
    }
    else{
        return a / b;
    }
}

int main(){
    float num1, num2;
    char operation;
    
    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);
    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &operation);
    
    switch(operation){
        case '+':
            printf("%.2f + %.2f = %.2f", num1, num2, add(num1, num2));
            break;
        case '-':
            printf("%.2f - %.2f = %.2f", num1, num2, subtract(num1, num2));
            break;
        case '*':
            printf("%.2f * %.2f = %.2f", num1, num2, multiply(num1, num2));
            break;
        case '/':
            printf("%.2f / %.2f = %.2f", num1, num2, divide(num1, num2));
            break;
        default:
            printf("Invalid operation!");
    }
    
    return 0;
}