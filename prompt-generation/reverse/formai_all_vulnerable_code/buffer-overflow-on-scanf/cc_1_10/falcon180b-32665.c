//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: recursive
#include <stdio.h>

// Function to perform addition recursively
long long add(int a, int b) {
    if (b == 0)
        return a;
    return 1 + add(a, b - 1);
}

// Function to perform subtraction recursively
long long subtract(int a, int b) {
    if (b == 0)
        return a;
    return add(a, -1 * b);
}

// Function to perform multiplication recursively
long long multiply(int a, int b) {
    if (b == 0 || a == 0)
        return 0;
    if (b == 1)
        return a;
    return add(a, multiply(a, b - 1));
}

// Function to perform division recursively
long long divide(int a, int b) {
    if (b == 0)
        return 0;
    if (a == b)
        return 1;
    if (a < b)
        return 0;
    return add(1, divide(a, b - 1));
}

// Function to perform modulus recursively
long long modulus(int a, int b) {
    if (b == 0)
        return a;
    return modulus(a, b - 1);
}

// Function to perform exponentiation recursively
long long exponentiation(int a, int b) {
    if (b == 0)
        return 1;
    return multiply(a, exponentiation(a, b - 1));
}

// Function to perform factorial recursively
long long factorial(int n) {
    if (n == 0)
        return 1;
    return multiply(n, factorial(n - 1));
}

int main() {
    int a, b, choice;
    printf("Enter two integers:\n");
    scanf("%d %d", &a, &b);
    printf("Choose an operation:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Modulus\n6. Exponentiation\n7. Factorial\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("%lld\n", add(a, b));
            break;
        case 2:
            printf("%lld\n", subtract(a, b));
            break;
        case 3:
            printf("%lld\n", multiply(a, b));
            break;
        case 4:
            printf("%lld\n", divide(a, b));
            break;
        case 5:
            printf("%lld\n", modulus(a, b));
            break;
        case 6:
            printf("%lld\n", exponentiation(a, b));
            break;
        case 7:
            printf("%lld\n", factorial(a));
            break;
        default:
            printf("Invalid choice\n");
    }
    return 0;
}