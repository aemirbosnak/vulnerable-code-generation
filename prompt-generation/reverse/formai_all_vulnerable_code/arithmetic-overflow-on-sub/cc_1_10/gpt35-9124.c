//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: scalable
#include <stdio.h>

// function to calculate the Fibonacci series till the given number n
void fib(int n) {
    int first = 0, second = 1, next;
    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i;
        } else {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d ", next);
    }
}

// function to draw the Fibonacci series visualizer
void fibVisualizer(int n) {
    int first = 0, second = 1, next;
    int fibSeries[n];
    fibSeries[0] = first;
    fibSeries[1] = second;
    for (int i = 2; i < n; i++) {
        next = first + second;
        first = second;
        second = next;
        fibSeries[i] = next;
    }
    int maxHeight = fibSeries[n-1];
    for (int i = maxHeight; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (fibSeries[j] > i) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// main function to execute the program
int main() {
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    printf("\nFibonacci series: ");
    fib(n);
    printf("\n\nFibonacci series visualizer: \n");
    fibVisualizer(n);
    return 0;
}