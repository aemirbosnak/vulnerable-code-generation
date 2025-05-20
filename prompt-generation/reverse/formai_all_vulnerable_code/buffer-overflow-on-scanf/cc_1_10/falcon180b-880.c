//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TERMS 1000
#define MAX_DIGITS 1000

// Function to generate Fibonacci sequence up to n terms
void generate_fibonacci_sequence(int n) {
    int fib_sequence[MAX_TERMS];
    fib_sequence[0] = 0;
    fib_sequence[1] = 1;
    int i;
    for (i = 2; i < n; i++) {
        fib_sequence[i] = fib_sequence[i-1] + fib_sequence[i-2];
    }

    // Print the sequence
    printf("Fibonacci sequence up to %d terms:\n", n);
    for (i = 0; i < n; i++) {
        printf("%d ", fib_sequence[i]);
    }
    printf("\n");
}

// Function to display the sequence in a visual format
void visualize_fibonacci_sequence(int n) {
    int fib_sequence[MAX_TERMS];
    fib_sequence[0] = 0;
    fib_sequence[1] = 1;
    int i;
    for (i = 2; i < n; i++) {
        fib_sequence[i] = fib_sequence[i-1] + fib_sequence[i-2];
    }

    // Print the sequence in a visual format
    printf("Fibonacci sequence up to %d terms:\n", n);
    for (i = 0; i < n; i++) {
        int digits = (int)log10(fib_sequence[i]) + 1;
        char str[MAX_DIGITS];
        sprintf(str, "%d", fib_sequence[i]);
        int j;
        for (j = 0; j < digits; j++) {
            printf("%c", str[j]);
        }
        printf("\n");
    }
}

// Function to generate a random Fibonacci sequence up to n terms
void generate_random_fibonacci_sequence(int n) {
    srand(time(NULL));
    int fib_sequence[MAX_TERMS];
    fib_sequence[0] = rand() % 100;
    fib_sequence[1] = rand() % 100;
    int i;
    for (i = 2; i < n; i++) {
        fib_sequence[i] = (fib_sequence[i-1] + fib_sequence[i-2]) % 100;
    }

    // Print the sequence
    printf("Random Fibonacci sequence up to %d terms:\n", n);
    for (i = 0; i < n; i++) {
        printf("%d ", fib_sequence[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    printf("Enter 1 to generate Fibonacci sequence up to n terms\n");
    printf("Enter 2 to visualize Fibonacci sequence up to n terms\n");
    printf("Enter 3 to generate random Fibonacci sequence up to n terms\n");
    scanf("%d", &choice);

    int n;
    if (choice == 1 || choice == 2) {
        printf("Enter the number of terms: ");
        scanf("%d", &n);
    }

    switch (choice) {
        case 1:
            generate_fibonacci_sequence(n);
            break;
        case 2:
            visualize_fibonacci_sequence(n);
            break;
        case 3:
            generate_random_fibonacci_sequence(n);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}