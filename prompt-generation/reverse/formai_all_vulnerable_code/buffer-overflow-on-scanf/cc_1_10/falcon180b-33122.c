//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: recursive
#include<stdio.h>

// Recursive function to add two numbers
int add(int a, int b) {
    if(b == 0) {
        return a;
    }
    return a + add(a, b-1);
}

// Recursive function to subtract two numbers
int subtract(int a, int b) {
    if(b == 0) {
        return a;
    }
    return a - subtract(a, b-1);
}

// Recursive function to multiply two numbers
int multiply(int a, int b) {
    if(b == 0) {
        return 0;
    }
    return a + multiply(a, b-1);
}

// Recursive function to divide two numbers
int divide(int a, int b) {
    if(b == 0) {
        return 0;
    }
    return a + divide(a, b-1);
}

// Recursive function to calculate the factorial of a number
int factorial(int n) {
    if(n == 0) {
        return 1;
    }
    return n * factorial(n-1);
}

int main() {
    int a, b, choice;

    // Prompt user for input
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    // Prompt user for arithmetic operation
    printf("Enter the arithmetic operation to perform:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Factorial\n");
    scanf("%d", &choice);

    // Perform arithmetic operation
    switch(choice) {
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
            printf("Result: %d\n", factorial(a));
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}