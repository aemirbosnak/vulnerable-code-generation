//FormAI DATASET v1.0 Category: Calculator ; Style: imaginative
#include <stdio.h>

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
    if (b == 0) {
        printf("Cannot divide by zero\n");
        return 0;
    } else {
        return a / b;
    }
}

int modulus(int a, int b) {
    if (b == 0) {
        printf("Cannot calculate modulus with zero\n");
        return 0;
    } else {
        return a % b;
    }
}

int main() {
    int num1, num2, choice;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("Enter operation to perform:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Modulus\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Result: %d\n", add(num1, num2));
            break;
        case 2:
            printf("Result: %d\n", subtract(num1, num2));
            break;
        case 3:
            printf("Result: %d\n", multiply(num1, num2));
            break;
        case 4:
            printf("Result: %d\n", divide(num1, num2));
            break;
        case 5:
            printf("Result: %d\n", modulus(num1, num2));
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}