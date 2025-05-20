//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define MAX_TERMS 1000
#define MAX_DIGITS 100

// Function to generate a random Fibonacci sequence
void generate_fibonacci(int terms, int max_digits) {
    int i, j, k, n;
    uint64_t a = 1, b = 1;

    // Print header
    printf("Random Fibonacci Sequence:\n");
    printf("------------------------------------\n");

    // Generate terms
    for (i = 0; i < terms; i++) {
        // Generate random number of digits
        n = rand() % max_digits + 1;

        // Generate random Fibonacci number
        for (j = 0; j < n; j++) {
            k = rand() % 2;
            if (k == 0) {
                b += a;
            } else {
                a += b;
            }
        }

        // Print number
        printf("%*d ", n, a);
    }

    // Print newline
    printf("\n");
}

int main() {
    srand(time(NULL));

    // Get number of terms from user
    int terms;
    printf("Enter number of terms: ");
    scanf("%d", &terms);

    // Get maximum number of digits from user
    int max_digits;
    printf("Enter maximum number of digits: ");
    scanf("%d", &max_digits);

    // Validate input
    if (terms <= 0 || terms > MAX_TERMS || max_digits <= 0 || max_digits > MAX_DIGITS) {
        printf("Invalid input.\n");
        return 1;
    }

    // Generate Fibonacci sequence
    generate_fibonacci(terms, max_digits);

    return 0;
}