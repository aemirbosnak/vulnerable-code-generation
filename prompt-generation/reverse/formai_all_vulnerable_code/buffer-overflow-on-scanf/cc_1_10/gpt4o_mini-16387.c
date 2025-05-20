//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

void visualizeFibonacci(int n) {
    long long first = 0;
    long long second = 1;
    long long next;

    printf("Fibonacci Sequence Visualization:\n");
    printf("Index\tValue\tVisualization\n");
    printf("===================================\n");
    
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            next = first;
        } else if (i == 1) {
            next = second;
        } else {
            next = first + second;
            first = second;
            second = next;
        }

        printf("%d\t%lld\t", i, next);
        
        // Limit visualization to avoid excessive output
        if (next < 100) {
            for (long long j = 0; j < next; j++) {
                printf("*");
            }
        } else {
            printf("Too many for display...");
        }
        printf("\n");
    }
}

int main() {
    int count;

    printf("Enter the number of Fibonacci terms to visualize (1 - 90): ");
    scanf("%d", &count);

    // Validate input
    if (count < 1 || count > 90) {
        printf("Please enter a number between 1 and 90.\n");
        return 1;
    }

    visualizeFibonacci(count);

    return 0;
}