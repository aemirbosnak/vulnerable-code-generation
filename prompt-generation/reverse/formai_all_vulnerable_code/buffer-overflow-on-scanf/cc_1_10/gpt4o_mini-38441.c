//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: excited
#include <stdio.h>
#include <stdlib.h>

void printFibonacci(int n) {
    long long int a = 0, b = 1, c;
    printf("Fibonacci Sequence up to %d terms:\n", n);
    printf("0: %lld\n", a);
    printf("1: %lld\n", b);
    
    for (int i = 2; i < n; i++) {
        c = a + b;
        printf("%d: %lld\n", i, c);
        a = b;
        b = c;
    }
}

void visualizeFibonacci(int n) {
    long long int a = 0, b = 1, c;
    printf("\nVisualizing Fibonacci Sequence:\n");
    
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("0 ");
        } else if (i == 1) {
            printf("1 ");
        } else {
            c = a + b;
            printf("%lld ", c);
            a = b;
            b = c;
        }
        
        // Simple visualization logic
        printf(" |");
        for(int j = 0; j < c; j += 100000) {
            printf("█");
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("🎉 Welcome to the Fibonacci Sequence Visualizer! 🎉\n");
    printf("How many terms of the Fibonacci sequence do you want to visualize? ");
    scanf("%d", &n);

    if (n < 1) {
        printf("😱 Please enter a positive integer greater than 0!\n");
        return 1;
    }
    
    printFibonacci(n);
    visualizeFibonacci(n);
    
    printf("\n✨ Thank you for using the Fibonacci Sequence Visualizer! ✨\n");
    return 0;
}