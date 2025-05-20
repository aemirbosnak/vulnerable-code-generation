//GPT-4o-mini DATASET v1.0 Category: Fractal Generation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

void drawSierpinskiTriangle(int row, int col, int height) {
    // If the height is zero, nothing to draw
    if (height <= 0) return;

    // Recursive call for the top triangle
    drawSierpinskiTriangle(row, col + (1 << (height - 1)), height - 1);
    // Recursive call for the left triangle
    drawSierpinskiTriangle(row + (1 << (height - 1)), col, height - 1);
    // Recursive call for the right triangle
    drawSierpinskiTriangle(row + (1 << (height - 1)), col + (1 << (height - 1)), height - 1);

    // Base case: drawing the filled triangle
    if (height == 1) {
        printf("\033[%d;%dH* ", row, col); // Move cursor to (row, col)
    }
}

void printSpaces(int height) {
    for (int i = 0; i < (1 << height) - 1; i++) {
        printf(" ");
    }
}

int main() {
    int height;

    printf("Enter the height of the Sierpinski Triangle (1 - 8): ");
    scanf("%d", &height);

    // Validate height input
    if (height < 1 || height > 8) {
        fprintf(stderr, "Error: height must be between 1 and 8.\n");
        return EXIT_FAILURE;
    }

    // Clear console
    printf("\033[2J");

    // Print spaces for the triangle alignment
    printSpaces(height - 1);

    // Draw Sierpinski Triangle starting at the top center
    drawSierpinskiTriangle(0, 0, height);
    
    // Allow for some time to see the output
    printf("\nPress Enter to exit...");
    getchar(); // To consume the newline after the height input
    getchar(); // Wait for user to press Enter

    return EXIT_SUCCESS;
}