//FormAI DATASET v1.0 Category: Recursive ; Style: beginner-friendly
#include <stdio.h>

int factorial(int n) {
    // Base case
    if (n == 0) {
        return 1;
    }
    // Recursive case
    else {
        return n * factorial(n-1);
    }
}

int fibonacci(int n) {
    // Base case
    if (n == 0 || n == 1) {
        return n;
    }
    // Recursive case
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

void binary(int decimal) {
    // Base case
    if (decimal == 0) {
        return;
    }
    // Recursive case
    else {
        binary(decimal/2);
        printf("%d", decimal%2);
    }
}

int main() {
    int num, fact, fibo;
    printf("Enter a number to find its factorial: ");
    scanf("%d", &num);
    fact = factorial(num);
    printf("Factorial of %d is %d\n", num, fact);
    printf("Enter a number to find its fibonacci: ");
    scanf("%d", &num);
    fibo = fibonacci(num);
    printf("Fibonacci of %d is %d\n", num, fibo);
    printf("Enter a decimal number to convert to binary: ");
    scanf("%d", &num);
    printf("Binary of %d is ", num);
    binary(num);
    printf("\n");
    return 0;
}