//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: artistic
#include <stdio.h>

void draw_triangle(int n, int x, int y, char canvas[64][128]) {
    // Base case: when n reaches 0, we stop recursion
    if (n == 0) {
        return;
    }

    // Calculate the coordinates for the current triangle
    int height = 1 << (n - 1); // height of the triangle
    int base_width = height * 2; // base width

    // Draw the current triangle
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < base_width; j++) {
            // Condition for creating the triangle shape
            if (j >= (base_width / 2 - i) && j <= (base_width / 2 + i)) {
                canvas[y + i][x + j] = '*';
            }
        }
    }

    // Recursive calls for the two smaller triangles
    draw_triangle(n - 1, x, y + height, canvas); // Bottom-left triangle
    draw_triangle(n - 1, x + height, y + height, canvas); // Bottom-right triangle
}

int main() {
    int n;
    printf("Enter the level of Sierpinski Triangle (depth): ");
    scanf("%d", &n);

    // Create a canvas for the drawing
    char canvas[64][128];
    
    // Initialize the canvas with spaces
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 128; j++) {
            canvas[i][j] = ' ';
        }
    }

    // Draw the Sierpinski triangle
    draw_triangle(n, 32, 0, canvas);

    // Print the canvas
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 128; j++) {
            putchar(canvas[i][j]);
        }
        putchar('\n');
    }

    return 0;
}