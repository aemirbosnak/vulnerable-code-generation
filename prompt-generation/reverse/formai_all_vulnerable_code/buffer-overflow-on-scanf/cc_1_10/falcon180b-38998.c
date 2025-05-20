//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Function to perform recursive addition
int recursiveAddition(int n) {
    if (n == 0) {
        return 0;
    }
    else {
        return n + recursiveAddition(n-1);
    }
}

// Function to perform recursive subtraction
int recursiveSubtraction(int n) {
    if (n == 0) {
        return 0;
    }
    else {
        return n - recursiveSubtraction(n-1);
    }
}

// Function to perform recursive multiplication
int recursiveMultiplication(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    else {
        return n * recursiveMultiplication(n-1);
    }
}

// Function to perform recursive division
int recursiveDivision(int n, int d) {
    if (d == 0) {
        printf("Error: Division by zero\n");
        exit(1);
    }
    else if (n == d) {
        return 1;
    }
    else if (n < d) {
        return 0;
    }
    else {
        return 1 + recursiveDivision(n-d, d);
    }
}

int main() {
    int num1, num2, result;

    // Recursive addition
    printf("Recursive addition:\n");
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    result = recursiveAddition(num1) + recursiveAddition(num2);
    printf("%d + %d = %d\n", num1, num2, result);

    // Recursive subtraction
    printf("Recursive subtraction:\n");
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    result = recursiveSubtraction(num1) - recursiveSubtraction(num2);
    printf("%d - %d = %d\n", num1, num2, result);

    // Recursive multiplication
    printf("Recursive multiplication:\n");
    printf("Enter an integer: ");
    scanf("%d", &num1);
    result = recursiveMultiplication(num1);
    printf("%d * 1 = %d\n", num1, result);

    // Recursive division
    printf("Recursive division:\n");
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    result = recursiveDivision(num1, num2);
    if (result == 0) {
        printf("%d / %d = 0\n", num1, num2);
    }
    else {
        printf("%d / %d = %d\n", num1, num2, result);
    }

    return 0;
}