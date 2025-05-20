//Falcon-180B DATASET v1.0 Category: Recursive ; Style: all-encompassing
#include <stdio.h>

/* Function to print the digits of a number */
void printDigits(int n) {
    if (n == 0) {
        return;
    }
    printf("%d", n % 10);
    printDigits(n / 10);
}

/* Function to calculate the factorial of a number */
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

/* Function to find the nth Fibonacci number */
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

/* Function to find the sum of the digits of a number */
int sumDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    /* Print the digits of the number */
    printf("The digits of %d are: ", n);
    printDigits(n);
    printf("\n");

    /* Calculate the factorial of the number */
    printf("The factorial of %d is: %d\n", n, factorial(n));

    /* Find the nth Fibonacci number */
    printf("The %dth Fibonacci number is: %d\n", n, fibonacci(n));

    /* Find the sum of the digits of the number */
    printf("The sum of the digits of %d is: %d\n", n, sumDigits(n));

    return 0;
}