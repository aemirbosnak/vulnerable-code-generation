//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TERMS 1000
#define WINDOW_WIDTH 80
#define WINDOW_HEIGHT 25

void generate_fibonacci_sequence(int num_terms, int *sequence) {
    sequence[0] = 0;
    sequence[1] = 1;
    for (int i = 2; i < num_terms; i++) {
        sequence[i] = sequence[i-1] + sequence[i-2];
    }
}

void print_fibonacci_sequence(int num_terms, int *sequence) {
    for (int i = 0; i < num_terms; i++) {
        printf("%d ", sequence[i]);
    }
    printf("\n");
}

void visualize_fibonacci_sequence(int num_terms, int *sequence) {
    system("clear");
    printf("Visualizing Fibonacci Sequence...\n\n");
    int row = 0;
    for (int i = 0; i < num_terms; i++) {
        int col = 0;
        for (int j = 0; j < sequence[i]; j++) {
            printf("*");
            col++;
        }
        printf("\n");
        row++;
    }
}

int main() {
    int num_terms;
    printf("Enter the number of terms for the Fibonacci sequence: ");
    scanf("%d", &num_terms);

    if (num_terms <= 0 || num_terms > MAX_TERMS) {
        printf("Invalid number of terms.\n");
        return 1;
    }

    int sequence[MAX_TERMS];
    generate_fibonacci_sequence(num_terms, sequence);

    printf("Fibonacci Sequence:\n");
    print_fibonacci_sequence(num_terms, sequence);

    visualize_fibonacci_sequence(num_terms, sequence);

    return 0;
}