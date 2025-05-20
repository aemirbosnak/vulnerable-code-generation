//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: complex
#include <stdio.h>
#define MAX_TERMS 30

void display(int sequence[]) {
    int i;
    printf("\nFibonacci Sequence: ");
    for(i = 0; sequence[i + 1] != -1; i++) {
        printf("%d, ", sequence[i]);
    }
    printf("%d\n", sequence[i]);
}

void fibonacci(int sequence[], int terms) {
    int i;
    sequence[0] = 0;
    sequence[1] = 1;

    for (i = 2; i < terms; i++) {
        sequence[i] = sequence[i-1] + sequence[i-2];
    }
    sequence[i] = -1; // Mark the end of sequence
}

void plot(int sequence[], int terms) {
    int maxTerm, i, j;
    maxTerm = sequence[terms-1];
    
    printf("\nFibonacci Plot: \n");
    for (i = 1; i <= maxTerm; i++) {
        printf("%d: ", i);

        for (j = 0; j < terms && sequence[j] <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

int main() {
    int sequence[MAX_TERMS];
    int terms;

    printf("Enter the number of terms to generate (max 30): ");
    scanf("%d", &terms);
    
    if (terms <= 0 || terms > MAX_TERMS) {
        printf("Invalid input. Please enter a value between 1 and 30.\n");
        return 1;
    }

    fibonacci(sequence, terms);
    display(sequence);
    plot(sequence, terms);

    return 0;
}