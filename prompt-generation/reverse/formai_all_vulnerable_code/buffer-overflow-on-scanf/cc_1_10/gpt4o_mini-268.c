//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep function
#include <string.h>

#define WIDTH 60
#define HEIGHT 20

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape codes to clear screen
}

void drawFibonacci(int *fib, int count) {
    int maxVal = fib[count - 1];
    double scale = (double) WIDTH / maxVal;
    
    printf("\nFibonacci Sequence Visualizer\n");
    printf("Index: ");
    for (int i = 0; i < count; i++) {
        printf("%2d ", i);
    }
    printf("\nValue: ");
    for (int i = 0; i < count; i++) {
        printf("%2d ", fib[i]);
    }
    printf("\n\n");

    for (int i = 0; i < count; i++) {
        int barWidth = (int)(fib[i] * scale);
        printf("Fib[%2d]: ", i);
        for (int j = 0; j < barWidth; j++) {
            printf("#");
        }
        printf(" (%d)\n", fib[i]);
    }
}

void generateFibonacci(int *fib, int count) {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < count; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

void visualizeFibonacci(int count) {
    int *fib = (int *)malloc(count * sizeof(int));
    if (!fib) {
        printf("Memory allocation failed\n");
        return;
    }

    generateFibonacci(fib, count);
    clearScreen();
    drawFibonacci(fib, count);

    // Pause to allow visualization
    printf("Press Ctrl+C to exit the visualizer...\n");
    while (1) {
        sleep(1);
        clearScreen();
        drawFibonacci(fib, count);
    }

    free(fib); // Clean up memory
}

int main() {
    int count;

    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("Enter the number of Fibonacci terms (>= 2): ");
    scanf("%d", &count);

    if (count < 2) {
        printf("Please enter a value greater than or equal to 2.\n");
        return 1;
    }

    visualizeFibonacci(count);
    return 0;
}