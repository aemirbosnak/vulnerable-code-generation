//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: mathematical
#include <stdio.h>

// Function to calculate Fibonacci numbers recursively
unsigned long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to calculate the golden ratio approximation
double golden_ratio(int n) {
    if (n <= 1) {
        return 0; // Undefined for n=0
    }
    return (double)fibonacci(n) / fibonacci(n - 1);
}

// Function to calculate the sum of the first n Fibonacci numbers
unsigned long long sum_fibonacci(int n) {
    unsigned long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += fibonacci(i);
    }
    return sum;
}

// Function to print Fibonacci sequence up to n terms
void print_fibonacci_sequence(int n) {
    printf("Fibonacci Sequence:\n");
    for (int i = 0; i < n; i++) {
        printf("F(%d) = %llu\n", i, fibonacci(i));
    }
}

// Function to print properties of Fibonacci sequence
void print_fibonacci_properties(int n) {
    printf("\nProperties of the Fibonacci Sequence:\n");
    printf("Number of Fibonacci Numbers: %d\n", n);
    printf("Sum of first %d Fibonacci numbers: %llu\n", n, sum_fibonacci(n));
    if (n > 1) {
        printf("Approximation of Golden Ratio (F(%d)/F(%d)): %.5f\n",
               n, n - 1, golden_ratio(n));
    }
}

int main() {
    int n;

    // User input for number of terms in the Fibonacci sequence
    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &n);

    // Input validation
    if (n < 1) {
        printf("Please enter a positive integer greater than 0.\n");
        return 1;
    }

    // Print the Fibonacci sequence
    print_fibonacci_sequence(n);

    // Print properties of the Fibonacci sequence
    print_fibonacci_properties(n);

    return 0;
}