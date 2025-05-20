//FormAI DATASET v1.0 Category: Arithmetic ; Style: recursive
#include <stdio.h>

int multiply(int num1, int num2) {
    if (num2 == 0) {
        return 0;
    } else {
        return num1 + multiply(num1, num2 - 1);
    }
}

int power(int num, int exp) {
    if (exp == 0) {
        return 1;
    } else {
        return multiply(num, power(num, exp - 1));
    }
}

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int find_gcd(int num1, int num2) {
    if (num2 == 0) {
        return num1;
    } else {
        return find_gcd(num2, num1 % num2);
    }
}

int main() {
    int num1, num2, result, choice;
    do {
        printf("\n1. Multiply");
        printf("\n2. Power");
        printf("\n3. Fibonacci");
        printf("\n4. Find GCD");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter two numbers to multiply: ");
                scanf("%d %d", &num1, &num2);
                result = multiply(num1, num2);
                printf("\nResult: %d", result);
                break;
            case 2:
                printf("\nEnter a number and its exponent: ");
                scanf("%d %d", &num1, &num2);
                result = power(num1, num2);
                printf("\nResult: %d", result);
                break;
            case 3:
                printf("\nEnter the n-th term of Fibonacci series: ");
                scanf("%d", &num1);
                result = fibonacci(num1);
                printf("\nResult: %d", result);
                break;
            case 4:
                printf("\nEnter two numbers to find their GCD: ");
                scanf("%d %d", &num1, &num2);
                result = find_gcd(num1, num2);
                printf("\nResult: %d", result);
                break;
            case 5:
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid choice");
        }
    } while (choice != 5);
    return 0;
}