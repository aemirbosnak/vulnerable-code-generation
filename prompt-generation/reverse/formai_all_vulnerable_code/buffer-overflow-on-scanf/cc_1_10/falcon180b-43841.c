//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the factorial of a given number
int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate the nth term of the Fibonacci series
int fibonacci(int n) {
    int a = 0, b = 1, c;
    for (int i = 1; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n, choice;

    // Prompt user to enter the number of terms to calculate
    printf("Enter the number of terms to calculate: ");
    scanf("%d", &n);

    // Prompt user to choose between factorial and Fibonacci series
    printf("Choose between factorial and Fibonacci series:\n");
    printf("1. Factorial\n");
    printf("2. Fibonacci series\n");
    scanf("%d", &choice);

    // Calculate factorial or Fibonacci series based on user choice
    if (choice == 1) {
        printf("Enter a number to calculate its factorial: ");
        int num;
        scanf("%d", &num);
        printf("Factorial of %d is %d\n", num, factorial(num));
    } else if (choice == 2) {
        printf("Fibonacci series up to %d terms:\n", n);
        for (int i = 0; i < n; i++) {
            printf("%d ", fibonacci(i));
        }
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}