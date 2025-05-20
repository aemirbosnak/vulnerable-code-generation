//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: romantic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Function to calculate Fibonacci number
unsigned long long fibonacci(int n) {
    if (n <= 1) return n;
    unsigned long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// Function to draw the Fibonacci Spiral in ASCII
void draw_fibonacci_spiral(int terms) {
    int width = 80, height = 20;
    char canvas[20][80];

    // Initialize canvas with spaces
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            canvas[i][j] = ' ';

    int x = width / 2, y = height / 2; // Start in the middle
    int dx = 0, dy = -1; // Initial direction

    for (int i = 0; i < terms; i++) {
        unsigned long long f = fibonacci(i);
        int steps = f;

        // Draw the current Fibonacci square
        for (int j = 0; j < steps; j++) {
            if (j < f && x >= 0 && x < width && y >= 0 && y < height) {
                canvas[y][x] = '*'; // mark the square with an asterisk
            }
            // Move in the current direction
            x += dx;
            y += dy;

            // Check bounds
            if (x < 0 || x >= width || y < 0 || y >= height) {
                printf("Canvas overflow, please reduce the number of terms.\n");
                return;
            }
        }

        // Turn 90 degrees clockwise
        int temp = dx;
        dx = dy;
        dy = -temp;
    }

    // Output the canvas
    printf("The Fibonacci Spiral:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("Let us embark on a romantic journey through the spiral of love,\n");
    printf("as we explore the wonders of Fibonacci's delicate embrace.\n");
    
    int terms;
    printf("How many terms of the Fibonacci sequence would you like to visualize? ");
    scanf("%d", &terms);

    if (terms < 0) {
        printf("Ah, my dear, let's cherish the numbers of beauty, not negativity!\n");
        return 1;
    }

    draw_fibonacci_spiral(terms);
    
    printf("Thank you for joining this enchanting exploration of math and nature,\n");
    printf("where every number blossoms like a flower in the spring.\n");
    return 0;
}