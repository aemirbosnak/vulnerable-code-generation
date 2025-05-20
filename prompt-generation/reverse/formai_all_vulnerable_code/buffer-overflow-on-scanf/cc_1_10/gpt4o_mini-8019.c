//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

void displayFibonacci(int n) {
    unsigned long long a = 0, b = 1, next;

    printf("Fibonacci Series up to %d terms:\n", n);
    printf("----------------------------------\n");

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%3d: %llu\n", i, a);
            printf("   *\n");  // Visual representation
            continue;
        }
        if (i == 1) {
            printf("%3d: %llu\n", i, b);
            printf("   *\n"); // Visual representation
            continue;
        }
        next = a + b;
        printf("%3d: %llu\n", i, next);
        
        // Visual representation
        for (unsigned long long j = 0; j < next; j += 10000000) {
            printf("   *");
        }
        printf("\n");

        a = b;
        b = next;
    }

    printf("----------------------------------\n");
}

void saveToFile(int n) {
    FILE *file = fopen("fibonacci_sequence.txt", "w");
    if (file == NULL) {
        printf("Error creating file.\n");
        return;
    }
    
    unsigned long long a = 0, b = 1, next;

    fprintf(file, "Fibonacci Series up to %d terms:\n", n);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            fprintf(file, "%3d: %llu\n", i, a);
            continue;
        }
        if (i == 1) {
            fprintf(file, "%3d: %llu\n", i, b);
            continue;
        }
        next = a + b;
        fprintf(file, "%3d: %llu\n", i, next);
        a = b;
        b = next;
    }

    fclose(file);
    printf("Fibonacci sequence saved to 'fibonacci_sequence.txt'.\n");
}

int main() {
    int terms;

    printf("Welcome to Fibonacci Sequence Visualizer!\n");
    printf("This program will compute the Fibonacci sequence and visualize it in a creative text format.\n");
    printf("How many terms of the Fibonacci series would you like? ");
    scanf("%d", &terms);

    if (terms <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    displayFibonacci(terms);
    saveToFile(terms);

    return 0;
}