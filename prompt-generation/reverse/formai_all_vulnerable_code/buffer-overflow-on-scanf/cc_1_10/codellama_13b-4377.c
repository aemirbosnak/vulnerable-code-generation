//Code Llama-13B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: romantic
/*
 * Fibonacci Sequence Visualizer
 * By: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 100
#define HEIGHT 50

void draw_fibonacci(int n) {
    int x = 0, y = 0, x_prev = 0, y_prev = 0, x_next = 0, y_next = 0;
    char canvas[HEIGHT][WIDTH];

    // Initialize the canvas with spaces
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            canvas[i][j] = ' ';
        }
    }

    // Draw the first two points
    canvas[HEIGHT / 2][WIDTH / 2] = 'X';
    canvas[HEIGHT / 2 - 1][WIDTH / 2] = 'X';

    // Draw the remaining points
    for (int i = 3; i <= n; i++) {
        // Calculate the next point
        x_next = x + sqrt(pow(x_prev - x, 2) + pow(y_prev - y, 2));
        y_next = y + sqrt(pow(x_prev - x, 2) + pow(y_prev - y, 2));

        // Draw the next point
        canvas[HEIGHT - y_next][WIDTH - x_next] = 'X';

        // Update the current point
        x_prev = x;
        y_prev = y;
        x = x_next;
        y = y_next;
    }

    // Print the canvas
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);
    draw_fibonacci(n);
    return 0;
}