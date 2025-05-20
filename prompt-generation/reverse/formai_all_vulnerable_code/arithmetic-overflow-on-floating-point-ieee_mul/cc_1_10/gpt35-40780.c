//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: interoperable
#include<stdio.h>

// Function to add two numbers
double addition(double num1, double num2){
    return num1 + num2; 
}

// Function to subtract two numbers
double subtraction(double num1, double num2){
    return num1 - num2;
}

// Function to multiply two numbers
double multiplication(double num1, double num2){
    return num1 * num2;
}

// Function to divide two numbers
double division(double num1, double num2){
    return num1 / num2;
}

int main(){
    double num1, num2, result;
    char operator;
    
    printf("Enter your calculation: ");
    scanf("%lf %c %lf", &num1, &operator, &num2);
    
    switch(operator){
        case '+':
            result = addition(num1, num2);
            break;
        case '-':
            result = subtraction(num1, num2);
            break;
        case '*':
            result = multiplication(num1, num2);
            break;
        case '/':
            result = division(num1, num2);
            break;
        default:
            printf("Invalid operator!");
            return 0;
    }
    
    printf("Result is : %.2lf", result);
    return 0;
}