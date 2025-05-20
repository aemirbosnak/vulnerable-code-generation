//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

// Function to calculate the factorial of a given number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to calculate the nth Fibonacci number
int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to calculate the number of ways to climb n stairs
int climbStairs(int n) {
    if (n == 0) {
        return 1;
    } else {
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
}

int main() {
    int n, m, ans;

    // Problem 1: Find the factorial of a given number
    printf("Enter a number: ");
    scanf("%d", &n);
    ans = factorial(n);
    printf("The factorial of %d is %d\n", n, ans);

    // Problem 2: Find the nth Fibonacci number
    printf("Enter a number: ");
    scanf("%d", &n);
    ans = fibonacci(n);
    printf("The nth Fibonacci number is %d\n", ans);

    // Problem 3: Find the number of ways to climb n stairs
    printf("Enter a number: ");
    scanf("%d", &n);
    ans = climbStairs(n);
    printf("The number of ways to climb %d stairs is %d\n", n, ans);

    return 0;
}