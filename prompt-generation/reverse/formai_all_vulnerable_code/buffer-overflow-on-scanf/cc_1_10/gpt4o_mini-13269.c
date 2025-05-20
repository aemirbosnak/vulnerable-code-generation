//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

void printHeart(int n) {
    printf("\n\n");
    for (int i = n / 2; i <= n; i += 2) {
        for (int j = 1; j < n - i; j += 2) {
            printf(" ");
        }
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    for (int i = n; i >= 1; i--) {
        for (int j = i; j < n; j++) {
            printf(" ");
        }
        for (int j = 1; j <= (i * 2) - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void displayFibonacci(int count) {
    long long first = 0, second = 1, next;

    printf("The Fibonacci Sequence flows like a river of love:\n");
    for (int i = 0; i < count; i++) {
        if (i <= 1)
            next = i;
        else {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%lld ", next);
        if ((i + 1) % 10 == 0)
            printf("\n");
    }
    
    printf("\n\n");
}

void decorateFibonacciLove() {
    printf("💖  Embracing the Elegance of Fibonacci 💖\n");
    printf("Let the sequence entwine your heart..\n");
}

int main() {
    int count;
    
    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("How many terms of the Fibonacci sequence do you desire? ");
    scanf("%d", &count);

    if (count <= 0) {
        printf("Ah, my love, do not wish for zero terms—resurrect your desire with at least one embrace.\n");
        return 0;
    }

    decorateFibonacciLove();
    displayFibonacci(count);

    printf("Let us now visualize this romance with a heart of stars...\n");
    printHeart(10); // Heart shape for our love

    printf("May this Fibonacci journey inspire numbers and love in your heart.\n");

    return 0;
}