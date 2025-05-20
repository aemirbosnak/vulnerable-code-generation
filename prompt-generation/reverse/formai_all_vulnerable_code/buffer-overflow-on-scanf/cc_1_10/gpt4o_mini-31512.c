//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printFibonacci(int n) {
    long long int a = 0, b = 1, c;
    printf("\nFibonacci Sequence:\n");
    printf(" -------------------\n");
    printf("| Index | Value     |\n");
    printf(" -------------------\n");
    
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("| %5d | %10lld |\n", i, a);
            continue;
        }
        if (i == 1) {
            printf("| %5d | %10lld |\n", i, b);
            continue;
        }
        
        c = a + b;
        a = b;
        b = c;
        
        printf("| %5d | %10lld |\n", i, c);
        usleep(500000); // Sleep for half a second to visualize the process
    }
    printf(" -------------------\n");
}

void visualizeFibonacci(int n) {
    long long int a = 0, b = 1, c;
    
    printf("\nVisualizing Fibonacci Sequence:\n");
    printf("=====================================\n");
    
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("   *\n");
            fflush(stdout);
            usleep(500000);
            continue;
        }
        if (i == 1) {
            printf("   *\n   *\n");
            fflush(stdout);
            usleep(500000);
            continue;
        }
        
        c = a + b;
        a = b;
        b = c;

        for (int j = 0; j < c; j++) {
            printf("*");
        }
        printf("\n");
        fflush(stdout);
        usleep(500000);
    }
    
    printf("=====================================\n");
}

int main() {
    int n;
    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("How many terms would you like to generate? ");
    
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input! Please enter a positive integer.\n");
        return 1;
    }

    printFibonacci(n);
    visualizeFibonacci(n);
    
    printf("Thank you for using the Fibonacci Visualizer!\n");
    return 0;
}