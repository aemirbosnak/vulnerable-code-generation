//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void clearScreen() {
    // Clear the terminal screen for better visualization
    printf("\033[H\033[J");
}

void delay(int seconds) {
    // Create a delay function to visualize the Fibonacci sequence slowly
    sleep(seconds);
}

void printFibonacci(int n) {
    long long int first = 0, second = 1, next;
    printf("Fibonacci Sequence up to %d terms:\n", n);
    
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%lld ", first);
            continue;
        }
        if (i == 1) {
            printf("%lld ", second);
            continue;
        }
        next = first + second;
        first = second;
        second = next;
        printf("%lld ", next);
    }
    printf("\n");
}

void visualizeFibonacci(int n) {
    long long int first = 0, second = 1, next;
    
    clearScreen();
    printf("Visualizing Fibonacci Sequence up to %d terms:\n", n);
    
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            printf("%lld: ", first);
            for (int j = 0; j < first; j++) printf("=");
            printf("\n");
            continue;
        }
        if (i == 1) {
            printf("%lld: ", second);
            for (int j = 0; j < second; j++) printf("=");
            printf("\n");
            continue;
        }
        next = first + second;
        first = second;
        second = next;
        
        printf("%lld: ", next);
        for (int j = 0; j < next; j++) printf("=");
        printf("\n");
        
        delay(1); // Adding delay to visualize growth
    }
}

int main() {
    int n;
    
    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("Enter the number of terms you want to visualize: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return EXIT_FAILURE;
    }

    printFibonacci(n);
    delay(2); // Wait before starting the visualization
    visualizeFibonacci(n);
    
    printf("Thank you for using the Fibonacci Sequence Visualizer!\n");
    return EXIT_SUCCESS;
}