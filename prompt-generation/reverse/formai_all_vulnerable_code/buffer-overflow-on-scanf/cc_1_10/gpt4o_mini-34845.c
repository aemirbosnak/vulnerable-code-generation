//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

void print_fibonacci(int n) {
    unsigned long long a = 0;
    unsigned long long b = 1;
    unsigned long long next;
    
    printf("Fibonacci Sequence:\n");
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%llu ", a);
            continue;
        }
        if (i == 1) {
            printf("%llu ", b);
            continue;
        }
        next = a + b;
        printf("%llu ", next);
        a = b;
        b = next;
    }
    printf("\n\n");
}

void visualize_fibonacci(int n) {
    unsigned long long a = 0;
    unsigned long long b = 1;
    unsigned long long next;

    printf("Visualizing Fibonacci Sequence:\n");

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%llu: ", a);
            for (int j = 0; j < a; j++) printf("#");
            printf("\n");
            continue;
        }
        if (i == 1) {
            printf("%llu: ", b);
            for (int j = 0; j < b; j++) printf("#");
            printf("\n");
            continue;
        }
        next = a + b;
        printf("%llu: ", next);
        for (int j = 0; j < next; j++) printf("#");
        printf("\n");
        a = b;
        b = next;
    }
}

int main() {
    int n;

    printf("Enter the number of terms in the Fibonacci sequence to generate: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Please enter a positive integer!\n");
        return 1;
    }

    print_fibonacci(n);
    visualize_fibonacci(n);

    return 0;
}