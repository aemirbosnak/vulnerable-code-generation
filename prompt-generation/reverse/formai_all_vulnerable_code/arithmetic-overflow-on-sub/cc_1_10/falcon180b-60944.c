//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the sum of two integers
int sum(int a, int b) {
    return a + b;
}

// Function to calculate the difference between two integers
int diff(int a, int b) {
    return a - b;
}

// Function to calculate the product of two integers
int prod(int a, int b) {
    return a * b;
}

// Function to calculate the quotient of two integers
int quot(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero\n");
        exit(1);
    }
    return a / b;
}

// Function to calculate the remainder of two integers
int rem(int a, int b) {
    return a % b;
}

// Function to calculate the power of two integers
int pow(int a, int b) {
    int result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}

int main() {
    int a, b, choice;

    printf("Enter two integers:\n");
    scanf("%d %d", &a, &b);

    printf("Enter the operation you want to perform:\n");
    printf("1. Sum\n2. Difference\n3. Product\n4. Quotient\n5. Remainder\n6. Power\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("The sum of %d and %d is %d\n", a, b, sum(a, b));
            break;
        case 2:
            printf("The difference between %d and %d is %d\n", a, b, diff(a, b));
            break;
        case 3:
            printf("The product of %d and %d is %d\n", a, b, prod(a, b));
            break;
        case 4:
            printf("The quotient of %d and %d is %d\n", a, b, quot(a, b));
            break;
        case 5:
            printf("The remainder of %d and %d is %d\n", a, b, rem(a, b));
            break;
        case 6:
            printf("The power of %d to %d is %d\n", a, b, pow(a, b));
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}