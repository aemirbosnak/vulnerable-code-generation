//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: Ada Lovelace
#include <stdio.h>

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
    if (b == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return 0;
    }
    return a / b;
}

// function to perform modulus operation
int modulus(int a, int b) {
    if (b == 0) {
        printf("Error: Modulus by zero is not allowed.\n");
        return 0;
    }
    return a % b;
}

int main() {
    int a, b, choice;

    // prompt user to enter two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    // prompt user to choose an operation
    printf("Choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    scanf("%d", &choice);

    // perform chosen operation and display result
    switch (choice) {
        case 1:
            printf("Result: %d\n", add(a, b));
            break;
        case 2:
            printf("Result: %d\n", subtract(a, b));
            break;
        case 3:
            printf("Result: %d\n", multiply(a, b));
            break;
        case 4:
            printf("Result: %d\n", divide(a, b));
            break;
        case 5:
            printf("Result: %d\n", modulus(a, b));
            break;
        default:
            printf("Invalid choice! ");
            break;
    }

    return 0;
}