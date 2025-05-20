//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>

void displayFib(int *fibArray, int size) {
    printf("\nFibonacci Sequence:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", fibArray[i]);
    }
    printf("\n");
}

void setTextColor(int color) {
    printf("\033[0;%dm", color);
}

void resetTextColor() {
    printf("\033[0m");
}

void drawFibonacciVisual(int *fibArray, int size) {
    for (int i = 0; i < size; i++) {
        setTextColor(32 + (i % 7)); // Cycles through 7 colors
        printf("\nF(%d) = %d:", i, fibArray[i]);
        
        // Drawing horizontal bars for Fibonacci numbers
        for (int j = 0; j < fibArray[i]; j++) {
            printf("█");
        }
        resetTextColor();
    }
    printf("\n");
}

void calculateFibonacci(int n, int *fibArray) {
    fibArray[0] = 0;
    if (n > 1) {
        fibArray[1] = 1;
        for (int i = 2; i < n; i++) {
            fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
        }
    }
}

int main() {
    int n;

    printf("Enter the number of Fibonacci numbers to display: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    int *fibArray = (int *)malloc(n * sizeof(int));
    if (fibArray == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    calculateFibonacci(n, fibArray);
    displayFib(fibArray, n);
    drawFibonacciVisual(fibArray, n);

    free(fibArray);
    return 0;
}