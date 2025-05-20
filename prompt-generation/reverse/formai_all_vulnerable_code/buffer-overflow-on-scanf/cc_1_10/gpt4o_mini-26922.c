//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void displayFib(int *arr, int n);
void clearScreen();
void drawLine(int n);
void boxFrame(int n);
int *allocateMemory(int size);

int main() {
    int count;

    clearScreen();
    printf("Enter the number of Fibonacci terms to visualize (greater than 1): ");
    scanf("%d", &count);

    if (count <= 1) {
        printf("Count must be greater than 1! Exiting...\n");
        return 1;
    }

    int *fib = allocateMemory(count);
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < count; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    drawLine(count);
    printf("\nFibonacci Sequence Visualization: \n");
    drawLine(count);
    displayFib(fib, count);
    drawLine(count);

    free(fib);
    return 0;
}

void displayFib(int *arr, int n) {
    int maxLength = snprintf(NULL, 0, "%d", arr[n - 1]);
    char *visual = (char *)malloc(maxLength * 10 + n + 1);
    visual[0] = '\0';

    for (int i = 0; i < n; ++i) {
        char buffer[50];
        snprintf(buffer, sizeof(buffer), "%d ", arr[i]);
        strcat(visual, buffer);
    }

    boxFrame(n);
    printf("%s\n", visual);
    free(visual);
}

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape code to clear the console
}

void drawLine(int n) {
    for (int i = 0; i < n * 2; ++i) {
        printf("=");
    }
    printf("\n");
}

void boxFrame(int n) {
    printf("╔");
    for (int i = 0; i < n * 2 - 1; ++i) {
        printf("═");
    }
    printf("╗\n");
}

int *allocateMemory(int size) {
    int *ptr = (int *)malloc(size * sizeof(int));
    if (!ptr) {
        printf("Memory allocation failed! Exiting...\n");
        exit(1);
    }
    return ptr;
}