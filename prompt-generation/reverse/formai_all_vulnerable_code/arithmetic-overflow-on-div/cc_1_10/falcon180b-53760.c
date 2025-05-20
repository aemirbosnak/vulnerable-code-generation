//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// define function prototypes
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

int main() {
    int num1, num2;
    char operation;

    printf("Enter two integers separated by space: ");
    scanf("%d %c %d", &num1, &operation, &num2);
    printf("Operation entered: %c\n", operation);

    switch(operation) {
        case '+':
            printf("Result of addition: %d\n", add(num1, num2));
            break;
        case '-':
            printf("Result of subtraction: %d\n", subtract(num1, num2));
            break;
        case '*':
            printf("Result of multiplication: %d\n", multiply(num1, num2));
            break;
        case '/':
            printf("Result of division: %d\n", divide(num1, num2));
            break;
        default:
            printf("Invalid operation!\n");
            break;
    }

    return 0;
}

// function to perform addition
int add(int a, int b) {
    return a + b;
}

// function to perform subtraction
int subtract(int a, int b) {
    return a - b;
}

// function to perform multiplication
int multiply(int a, int b) {
    return a * b;
}

// function to perform division
int divide(int a, int b) {
    if(b == 0) {
        printf("Cannot divide by zero!\n");
        exit(1);
    }
    return a / b;
}