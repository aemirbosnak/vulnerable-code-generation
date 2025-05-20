//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TERMS 100
#define MAX_DIGITS 1000

// Function to generate Fibonacci sequence
void fibonacci(int n, int *sequence) {
    int i;
    sequence[0] = 0;
    sequence[1] = 1;
    for (i = 2; i < n; i++) {
        sequence[i] = sequence[i-1] + sequence[i-2];
    }
}

// Function to print Fibonacci sequence
void print_sequence(int n, int *sequence) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", sequence[i]);
    }
    printf("\n");
}

// Function to get user input
void get_input(int *n) {
    int input;
    printf("Enter the number of terms: ");
    scanf("%d", &input);
    *n = input;
}

// Function to get random input
void get_random_input(int *n) {
    srand(time(NULL));
    *n = rand() % MAX_TERMS + 1;
}

// Function to get valid input
void get_valid_input(int *n) {
    int input;
    do {
        printf("Enter the number of terms (1-100): ");
        scanf("%d", &input);
    } while (input < 1 || input > MAX_TERMS);
    *n = input;
}

int main() {
    int n, i, choice;
    int sequence[MAX_TERMS];

    // Get user choice
    printf("Select an option:\n");
    printf("1. Enter number of terms\n");
    printf("2. Generate random number of terms\n");
    printf("3. Quit\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            // Get number of terms from user
            get_valid_input(&n);
            // Generate Fibonacci sequence
            fibonacci(n, sequence);
            // Print sequence
            printf("Fibonacci sequence with %d terms:\n", n);
            print_sequence(n, sequence);
            break;
        case 2:
            // Generate random number of terms
            get_random_input(&n);
            // Generate Fibonacci sequence
            fibonacci(n, sequence);
            // Print sequence
            printf("Fibonacci sequence with %d terms:\n", n);
            print_sequence(n, sequence);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}