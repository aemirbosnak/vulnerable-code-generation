//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

// Function to perform arithmetic operations recursively
int arithmetic(int num1, int num2, char operation) {

    // Base case
    if (num2 == 0) {
        switch (operation) {
            case '+':
                return num1;
            case '-':
                return num1;
            case '*':
                return 0;
            case '/':
                return 0;
        }
    }

    // Recursive case
    switch (operation) {
        case '+':
            return num1 + arithmetic(num1, num2 - 1, operation);
        case '-':
            return num1 - arithmetic(num1, num2 - 1, operation);
        case '*':
            return num1 * arithmetic(num1, num2 - 1, operation);
        case '/':
            return num1 / arithmetic(num1, num2 - 1, operation);
    }
}

int main() {
    int num1, num2, result;
    char operation;

    // Taking input from user
    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("Enter arithmetic operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // Calling recursive function to perform arithmetic operation
    result = arithmetic(num1, num2, operation);

    // Printing result
    printf("Result: %d", result);

    return 0;
}