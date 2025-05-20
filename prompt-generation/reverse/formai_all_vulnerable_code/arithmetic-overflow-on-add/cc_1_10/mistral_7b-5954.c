//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX 50

// Function to calculate Fibonacci sequence up to n
void fibonacci(int n) {
    int a = 0, b = 1, c;

    printf("\nFibonacci Sequence up to %d:\n", n);
    printf("%d %d ", a, b);

    for (int i = 0; i < n - 2; i++) {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }
}

// Function to find the sum of even-valued numbers in the Fibonacci sequence
int sum_even_fibonacci(int n) {
    int a = 0, b = 1, c, sum = 0;

    fibonacci(n + 2); // Calculate the first n+2 Fibonacci numbers

    for (int i = 2; i <= n; i += 2) {
        c = a + b;
        if (i % 2 == 0) // Check if the number is even
            sum += c; // Add the even number to the sum
        a = b;
        b = c;
    }

    return sum;
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input! Please enter a positive number.\n");
        return 1;
    }

    printf("\nSum of even-valued Fibonacci numbers up to %d: %d\n", n, sum_even_fibonacci(n));

    return 0;
}