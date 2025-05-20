//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For usleep

void draw_fibonacci(int n) {
    unsigned long long int fib[n];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    int posX = 10; // Initial horizontal position
    int posY = 5;  // Initial vertical position

    for (int i = 0; i < n; i++) {
        // Move cursor to (posX, posY)
        printf("\033[%d;%dH", posY, posX);
        printf("Fibonacci %d: %llu", i, fib[i]);

        // Increment position for shifting effect
        posX += 4; 

        // Reset to the start of the line if we reach the edge
        if (posX > 60) {
            posX = 10;
            posY++;
        }

        // Add a small delay before the next output to create animation effect
        usleep(500000); // 0.5 second
    }
}

int main() {
    int n;

    printf("Enter the number of Fibonacci numbers to visualize: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Please enter a value greater than or equal to 2.\n");
        return 1;
    }

    // Clear the terminal
    printf("\033[H\033[J");
  
    // Draw Fibonacci sequence in a shape-shifting manner
    draw_fibonacci(n); 

    // Move cursor to a new line after the output
    printf("\n");
    return 0;
}