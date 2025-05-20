//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TERMS 1000
#define MAX_DIGITS 1000

// Function to generate the Fibonacci sequence up to a given number of terms
void generate_fibonacci_sequence(int num_terms) {
    int i, j, k;
    int fibonacci_numbers[MAX_TERMS];

    fibonacci_numbers[0] = 0;
    fibonacci_numbers[1] = 1;

    for (i = 2; i < num_terms; i++) {
        fibonacci_numbers[i] = fibonacci_numbers[i-1] + fibonacci_numbers[i-2];
    }

    // Print the sequence
    for (i = 0; i < num_terms; i++) {
        printf("%d ", fibonacci_numbers[i]);
    }
}

// Function to print the Fibonacci sequence in a visually appealing way
void print_fibonacci_sequence(int num_terms) {
    int i, j, k, max_digits = 0;
    int fibonacci_numbers[MAX_TERMS];

    generate_fibonacci_sequence(num_terms);

    // Find the maximum number of digits in the sequence
    for (i = 0; i < num_terms; i++) {
        k = fibonacci_numbers[i];
        while (k > 0) {
            max_digits = max_digits > k % 10? max_digits : k % 10;
            k /= 10;
        }
    }

    // Print the sequence with proper spacing
    for (i = 0; i < num_terms; i++) {
        k = fibonacci_numbers[i];
        for (j = 0; j < max_digits; j++) {
            printf("%d ", k % 10);
            k /= 10;
        }
        printf("\n");
    }
}

int main() {
    int num_terms;

    // Get the number of terms from the user
    printf("Enter the number of terms: ");
    scanf("%d", &num_terms);

    // Generate and print the Fibonacci sequence
    srand(time(NULL));
    print_fibonacci_sequence(num_terms);

    return 0;
}