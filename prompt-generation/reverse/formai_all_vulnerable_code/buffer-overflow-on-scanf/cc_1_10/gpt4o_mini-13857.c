//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printLine(int n, char symbol) {
    for (int i = 0; i < n; i++) {
        printf("%c", symbol);
    }
    printf("\n");
}

void clearScreen() {
    printf("\033[H\033[J");
}

void visualizeFibonacci(int terms) {
    int a = 0, b = 1, nextTerm;
    
    printf("Fibonacci Sequence Visualization:\n");
    printLine(40, '=');
    
    for (int i = 1; i <= terms; i++) {
        printf("Term %2d: %d\n", i, a);
        printLine(a, '*');
        nextTerm = a + b;
        a = b;
        b = nextTerm;
        
        sleep(1); // Pause for a second for visual effect
    }
    
    printLine(40, '=');
    printf("End of Visualization.\n");
}

int main() {
    int numberOfTerms;

    clearScreen();
    
    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printLine(40, '-');
    printf("Please enter the number of terms you wish to visualize: ");
    
    // Validating user input
    while (1) {
        scanf("%d", &numberOfTerms);
        if (numberOfTerms > 0) {
            break;
        }
        printf("Please enter a valid positive integer: ");
    }
    
    visualizeFibonacci(numberOfTerms);
    
    return 0;
}