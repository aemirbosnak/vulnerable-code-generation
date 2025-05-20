//Falcon2-11B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: ephemeral
#include <stdio.h>
#include <math.h>

// Function to add two numbers
int add(int a, int b) {
    return a + b;
}

// Function to subtract two numbers
int subtract(int a, int b) {
    return a - b;
}

// Function to multiply two numbers
int multiply(int a, int b) {
    return a * b;
}

// Function to divide two numbers
int divide(int a, int b) {
    return a / b;
}

// Function to square a number
int square(int a) {
    return pow(a, 2);
}

// Function to raise a number to a power
int power(int a, int b) {
    return pow(a, b);
}

int main() {
    int num1, num2;
    char op;
    
    printf("Enter the first number: ");
    scanf("%d", &num1);
    
    printf("Enter the operation (+, -, *, /, sqrt, or exp): ");
    scanf(" %c", &op);
    
    printf("Enter the second number: ");
    scanf("%d", &num2);
    
    switch (op) {
        case '+':
            printf("%d\n", add(num1, num2));
            break;
        case '-':
            printf("%d\n", subtract(num1, num2));
            break;
        case '*':
            printf("%d\n", multiply(num1, num2));
            break;
        case '/':
            printf("%d\n", divide(num1, num2));
            break;
        case'sqrt':
            printf("%d\n", sqrt(num1));
            break;
        case 'exp':
            printf("%d\n", pow(num1, num2));
            break;
        default:
            printf("Invalid operation!\n");
    }
    
    return 0;
}