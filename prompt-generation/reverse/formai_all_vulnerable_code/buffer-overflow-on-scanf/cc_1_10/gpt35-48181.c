//FormAI DATASET v1.0 Category: Arithmetic ; Style: grateful
#include <stdio.h>

// Show gratitude
void grateful() {
    printf("Thank you for using this program!\n");
}

// Addition function
int add(int a, int b) {
    return a + b;
}

// Subtraction function
int sub(int a, int b) {
    return a - b;
}

// Multiplication function
int mul(int a, int b) {
    return a * b;
}

// Division function
int div(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero.\n");
        return 0;
    }
    return a / b;
}

// Main method
int main() {
    printf("Welcome to the Grateful Arithmetic Program!\n");
    printf("This program performs basic arithmetic operations.\n");

    int a, b;
    char op;

    do {
        printf("Enter two numbers: ");
        scanf("%d %d", &a, &b);

        printf("Enter an operator (+, -, *, /): ");
        scanf(" %c", &op);

        switch(op) {
            case '+':
                printf("%d + %d = %d\n", a, b, add(a, b));
                break;
            case '-':
                printf("%d - %d = %d\n", a, b, sub(a, b));
                break;
            case '*':
                printf("%d * %d = %d\n", a, b, mul(a, b));
                break;
            case '/':
                printf("%d / %d = %d\n", a, b, div(a, b));
                break;
            default:
                printf("Invalid operator.\n");
        }

        printf("Press 'q' to quit or any other key to continue: ");
        scanf(" %c", &op);
    } while (op != 'q');

    grateful();

    return 0;
}