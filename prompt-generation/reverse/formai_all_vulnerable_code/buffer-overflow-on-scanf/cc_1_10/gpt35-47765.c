//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: future-proof
#include <stdio.h>

// function to generate Fibonacci sequence
void fibonacci(int limit) {
    int a = 0, b = 1, c, i;
    printf("%d %d ", a, b);
    for (i = 2; i < limit; i++) {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }
}

// function to create visualization of Fibonacci sequence
void visualFibonacci(int limit) {
    int a = 0, b = 1, c, i, j, k;
    for (i = 1; i <= limit; i++) {
        c = a + b;
        a = b;
        b = c;
        for (j = 1; j <= c; j++) {
            for (k = 1; k <= j; k++) {
                printf("* ");
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main() {
    int choice, limit;

    printf("Enter 1 to generate Fibonacci sequence or 2 to visualize Fibonacci sequence: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter limit for Fibonacci sequence: ");
        scanf("%d", &limit);
        printf("Fibonacci sequence: ");
        fibonacci(limit);
    } else if (choice == 2) {
        printf("Enter limit for Fibonacci visualization: ");
        scanf("%d", &limit);
        visualFibonacci(limit);
    } else {
        printf("Invalid choice!");
    }

    return 0;
}