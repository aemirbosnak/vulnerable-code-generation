//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Function to check if a number is even
bool is_even(int number) {
    return number % 2 == 0;
}

// Function to generate Fibonacci sequence up to n
void generate_fibonacci_sequence(int n) {
    int fib_sequence[n + 1];
    fib_sequence[0] = 0;
    fib_sequence[1] = 1;

    for (int i = 2; i <= n; ++i) {
        fib_sequence[i] = fib_sequence[i - 1] + fib_sequence[i - 2];
    }

    printf("Fibonacci sequence of length %d:\n", n);
    for (int i = 0; i <= n; ++i) {
        printf("%d ", fib_sequence[i]);
    }
    printf("\n");
}

// Function to measure the time taken to execute a function
double measure_time(void (*function)(int), int n) {
    clock_t start, end;
    double elapsed_time;

    start = clock();
    function(n);
    end = clock();

    elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    return elapsed_time;
}

int main(void) {
    int sequence_length;
    double elapsed_time;

    // Seed random number generator for reproducibility
    srand(time(NULL));

    printf("Enter the length of the Fibonacci sequence to generate: ");
    scanf("%d", &sequence_length);

    if (sequence_length <= 0) {
        printf("Invalid sequence length. Exiting...\n");
        return EXIT_FAILURE;
    }

    // Generate Fibonacci sequence
    generate_fibonacci_sequence(sequence_length);

    // Measure time taken to generate Fibonacci sequence
    elapsed_time = measure_time(generate_fibonacci_sequence, sequence_length);

    printf("Time taken to generate a Fibonacci sequence of length %d: %.16f seconds\n", sequence_length, elapsed_time);

    return EXIT_SUCCESS;
}