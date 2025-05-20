//GPT-4o-mini DATASET v1.0 Category: Pixel Art Generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define WIDTH 16
#define HEIGHT 16

void clearScreen() {
    printf("\033[H\033[J");
}

void drawPixel(char canvas[HEIGHT][WIDTH], int x, int y, char pixelCharacter) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        // Set the chosen pixel character
        canvas[y][x] = pixelCharacter;
    }
}

void drawCanvas(char canvas[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

void initializeCanvas(char canvas[HEIGHT][WIDTH]) {
    // Fill the canvas with empty space
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            canvas[i][j] = ' ';
        }
    }
}

void drawHeart(char canvas[HEIGHT][WIDTH]) {
    drawPixel(canvas, 7, 5, '*');
    drawPixel(canvas, 8, 5, '*');
    drawPixel(canvas, 6, 6, '*');
    drawPixel(canvas, 7, 6, '*');
    drawPixel(canvas, 8, 6, '*');
    drawPixel(canvas, 9, 6, '*');
    drawPixel(canvas, 5, 7, '*');
    drawPixel(canvas, 4, 8, '*');
    drawPixel(canvas, 5, 9, '*');
    drawPixel(canvas, 10, 7, '*');
    drawPixel(canvas, 11, 8, '*');
    drawPixel(canvas, 10, 9, '*');
    drawPixel(canvas, 6, 8, '*');
    drawPixel(canvas, 9, 8, '*');
}

void drawSmiley(char canvas[HEIGHT][WIDTH]) {
    drawPixel(canvas, 4, 4, 'O');  // Left eye
    drawPixel(canvas, 11, 4, 'O'); // Right eye
    drawPixel(canvas, 7, 10, '_'); // Mouth
    drawPixel(canvas, 6, 9, '/');  // Left mouth curve
    drawPixel(canvas, 8, 9, '\\'); // Right mouth curve
    drawPixel(canvas, 7, 5, 'D');  // Face expression
}

int main() {
    char canvas[HEIGHT][WIDTH];

    clearScreen();

    // Initialize the canvas
    initializeCanvas(canvas);

    // Choose a drawing
    printf("Choose a pixel art to draw:\n");
    printf("1. Heart\n");
    printf("2. Smiley\n");
    
    int choice;
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        drawHeart(canvas);
    } else if (choice == 2) {
        drawSmiley(canvas);
    } else {
        printf("Invalid choice! Exiting.\n");
        return 1;
    }

    // Draw the canvas with the selected art
    clearScreen();
    drawCanvas(canvas);

    // Give the user some time to see the result
    printf("Press Enter to exit...");
    getchar(); // To catch the newline from the previous input
    getchar(); // Wait for user to press Enter

    return 0;
}