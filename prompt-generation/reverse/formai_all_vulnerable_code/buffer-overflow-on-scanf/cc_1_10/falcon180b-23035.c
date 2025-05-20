//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the factorial of a number
int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate the Fibonacci sequence
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

// Function to calculate the sum of the digits of a number
int sumOfDigits(int n) {
    int sum = 0;
    while (n!= 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    // Prompt the user for a number
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    // Calculate the factorial of the number
    int fact = factorial(num);
    printf("The factorial of %d is %d\n", num, fact);

    // Calculate the Fibonacci sequence up to the number
    int fib = fibonacci(num);
    printf("The %dth Fibonacci number is %d\n", num, fib);

    // Calculate the sum of the digits of the number
    int s = sumOfDigits(num);
    printf("The sum of the digits of %d is %d\n", num, s);

    return 0;
}