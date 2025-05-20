//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Structure to store a range of numbers
typedef struct {
    int start;
    int end;
} Range;

// Function to generate the Fibonacci sequence within a given range
int* generate_fibonacci(Range range) {
    // Allocate memory for the Fibonacci sequence
    int* sequence = malloc((range.end - range.start + 1) * sizeof(int));

    // Initialize the first two numbers in the sequence
    sequence[0] = 0;
    sequence[1] = 1;

    // Generate the rest of the sequence
    for (int i = 2; i <= range.end - range.start; i++) {
        sequence[i] = sequence[i - 1] + sequence[i - 2];
    }

    // Return the Fibonacci sequence
    return sequence;
}

// Function to print the Fibonacci sequence
void print_fibonacci(int* sequence, Range range) {
    // Print the Fibonacci sequence within the given range
    for (int i = range.start; i <= range.end; i++) {
        printf("%d ", sequence[i - range.start]);
    }

    // Print a newline character
    printf("\n");
}

// Function to get a valid input range from the user
Range get_input_range() {
    Range range;

    // Get the start and end of the range from the user
    printf("Enter the start of the range: ");
    scanf("%d", &range.start);

    printf("Enter the end of the range: ");
    scanf("%d", &range.end);

    // Validate the range
    while (range.start < 0 || range.end < 0 || range.start > range.end) {
        printf("Invalid range. Please enter a valid range.\n");
        printf("Enter the start of the range: ");
        scanf("%d", &range.start);

        printf("Enter the end of the range: ");
        scanf("%d", &range.end);
    }

    // Return the valid range
    return range;
}

// Main function
int main() {
    // Get the input range from the user
    Range range = get_input_range();

    // Generate the Fibonacci sequence within the given range
    int* sequence = generate_fibonacci(range);

    // Print the Fibonacci sequence
    print_fibonacci(sequence, range);

    // Free the memory allocated for the Fibonacci sequence
    free(sequence);

    return 0;
}