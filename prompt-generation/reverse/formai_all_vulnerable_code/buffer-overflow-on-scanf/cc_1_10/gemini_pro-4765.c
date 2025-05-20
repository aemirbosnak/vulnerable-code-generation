//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of Fibonacci numbers to be displayed
#define MAX_NUMBERS 100

// Define the colors to be used for the Fibonacci numbers
#define COLOR_EVEN "\033[1;30m"
#define COLOR_ODD "\033[1;31m"
#define COLOR_RESET "\033[0m"

// Function to generate the Fibonacci sequence
long long* generate_fibonacci_sequence(int n) {
    long long* sequence = malloc(n * sizeof(long long));
    sequence[0] = 0;
    sequence[1] = 1;
    for (int i = 2; i < n; i++) {
        sequence[i] = sequence[i - 1] + sequence[i - 2];
    }
    return sequence;
}

// Function to print the Fibonacci sequence in color
void print_fibonacci_sequence(long long* sequence, int n) {
    for (int i = 0; i < n; i++) {
        if (sequence[i] % 2 == 0) {
            printf(COLOR_EVEN "%lld" COLOR_RESET, sequence[i]);
        } else {
            printf(COLOR_ODD "%lld" COLOR_RESET, sequence[i]);
        }
        printf(" ");
    }
    printf("\n");
}

// Main function
int main() {
    // Get the number of Fibonacci numbers to be displayed from the user
    int n;
    printf("Enter the number of Fibonacci numbers to be displayed: ");
    scanf("%d", &n);

    // Generate the Fibonacci sequence
    long long* sequence = generate_fibonacci_sequence(n);

    // Print the Fibonacci sequence in color
    print_fibonacci_sequence(sequence, n);

    // Free the allocated memory
    free(sequence);
    return 0;
}