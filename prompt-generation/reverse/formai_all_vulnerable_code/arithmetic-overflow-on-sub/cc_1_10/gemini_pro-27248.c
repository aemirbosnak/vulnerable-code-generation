//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: scalable
#include <stdio.h>

#define FIB_MAX 100  // Maximum number of Fibonacci numbers to calculate

// Function to calculate the nth Fibonacci number
long long fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to print the Fibonacci sequence up to the nth number
void print_fibonacci(int n) {
    for (int i = 0; i < n; i++) {
        printf("%lld ", fibonacci(i));
    }
    printf("\n");
}

// Function to generate a visual representation of the Fibonacci sequence
void visualize_fibonacci(int n) {
    // Create an array to store the Fibonacci numbers
    long long fib[FIB_MAX];

    // Calculate the Fibonacci numbers
    for (int i = 0; i < n; i++) {
        fib[i] = fibonacci(i);
    }

    // Find the maximum Fibonacci number
    long long max_fib = fib[n - 1];

    // Create a 2D array to store the visual representation
    char visual[n][max_fib + 1];

    // Initialize the visual representation to spaces
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < max_fib + 1; j++) {
            visual[i][j] = ' ';
        }
    }

    // Fill in the visual representation
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < fib[i]; j++) {
            visual[i][j] = '*';
        }
    }

    // Print the visual representation
    for (int i = n - 1; i >= 0; i--) {
        printf("%lld: ", fib[i]);
        for (int j = 0; j < max_fib + 1; j++) {
            printf("%c", visual[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the number of Fibonacci numbers to calculate: ");
    scanf("%d", &n);

    print_fibonacci(n);
    visualize_fibonacci(n);

    return 0;
}