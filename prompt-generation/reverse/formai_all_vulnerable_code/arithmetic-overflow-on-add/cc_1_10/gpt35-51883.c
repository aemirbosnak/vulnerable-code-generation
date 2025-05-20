//FormAI DATASET v1.0 Category: Educational ; Style: genious
#include <stdio.h>

// Function declarations
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

// Main function
int main() {
    int a, b;
    char op;

    // Prompt user for input
    printf("Enter an expression (e.g. 2 + 3): ");
    scanf("%d %c %d", &a, &op, &b);

    // Perform the specified operation
    switch(op) {
        case '+':
            printf("%d + %d = %d\n", a, b, add(a, b));
            break;
        case '-':
            printf("%d - %d = %d\n", a, b, subtract(a, b));
            break;
        case '*':
            printf("%d * %d = %d\n", a, b, multiply(a, b));
            break;
        case '/':
            printf("%d / %d = %d\n", a, b, divide(a, b));
            break;
        default:
            printf("Invalid operator: %c\n", op);
            break;
    }

    return 0;
}

// Function definitions
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if(b == 0) {
        printf("Error: division by zero\n");
        return 0;
    }
    return a / b;
}