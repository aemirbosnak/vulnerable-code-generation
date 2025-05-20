//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 100 // Maximum length of Fibonacci sequence
#define MAX_BAR_LENGTH 50       // Maximum length of visualized bars

void generate_sequence(int sequence[MAX_SEQUENCE_LENGTH], int n);
void visualize_sequence(int sequence[MAX_SEQUENCE_LENGTH], int n);

int main() {
    int sequence[MAX_SEQUENCE_LENGTH];
    int n;

    printf("Enter a number n to generate the first n terms of the Fibonacci sequence: ");
    scanf("%d", &n);

    generate_sequence(sequence, n);
    visualize_sequence(sequence, n);

    return 0;
}

// Function to generate the first n terms of the Fibonacci sequence
void generate_sequence(int sequence[MAX_SEQUENCE_LENGTH], int n) {
    if (n <= 0) {
        printf("Error: Invalid input!\n");
        exit(0);
    } else if (n == 1) {
        sequence[0] = 0;
    } else if (n == 2) {
        sequence[0] = 0;
        sequence[1] = 1;
    } else {
        sequence[0] = 0;
        sequence[1] = 1;
        for (int i = 2; i < n; i++) {
            sequence[i] = sequence[i-1] + sequence[i-2];
        }
    }
}

// Function to visualize the Fibonacci sequence as a bar graph
void visualize_sequence(int sequence[MAX_SEQUENCE_LENGTH], int n) {
    int max_value = sequence[n-1];
    int bar_lengths[MAX_SEQUENCE_LENGTH];

    printf("\nFibonacci Sequence: ");

    for (int i = 0; i < n; i++) {
        bar_lengths[i] = (int)((double)sequence[i] / max_value * MAX_BAR_LENGTH);
    }

    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%d: ", sequence[i]);
        for (int j = 0; j < bar_lengths[i]; j++) {
            printf("#");
        }
        printf("\n");
    }
}