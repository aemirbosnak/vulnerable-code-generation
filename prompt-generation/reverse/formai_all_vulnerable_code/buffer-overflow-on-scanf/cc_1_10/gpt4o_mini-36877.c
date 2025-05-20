//GPT-4o-mini DATASET v1.0 Category: Pixel Art Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEIGHT 20
#define MAX_WIDTH 40
#define EMPTY ' '
#define PIXEL '#'

// Function to initialize the canvas
void initializeCanvas(char canvas[MAX_HEIGHT][MAX_WIDTH], int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            canvas[i][j] = EMPTY;
        }
    }
}

// Function to display the canvas
void displayCanvas(char canvas[MAX_HEIGHT][MAX_WIDTH], int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

// Function to draw a square
void drawSquare(char canvas[MAX_HEIGHT][MAX_WIDTH], int startX, int startY, int size) {
    for (int i = startY; i < startY + size && i < MAX_HEIGHT; i++) {
        for (int j = startX; j < startX + size && j < MAX_WIDTH; j++) {
            canvas[i][j] = PIXEL;
        }
    }
}

// Function to draw a randomized pattern
void drawRandomPattern(char canvas[MAX_HEIGHT][MAX_WIDTH], int height, int width) {
    int numSquares = (height * width) / 20; // Example: create numSquares based on canvas size
    for (int i = 0; i < numSquares; i++) {
        int size = rand() % 4 + 1; // Random size from 1 to 4
        int startX = rand() % width;
        int startY = rand() % height;
        drawSquare(canvas, startX, startY, size);
    }
}

// Function to draw an 'X' shape
void drawXShape(char canvas[MAX_HEIGHT][MAX_WIDTH], int height, int width) {
    for (int i = 0; i < height && i < MAX_HEIGHT; i++) {
        int xPos = (width / 2) + (i % 2 == 0 ? -1 : 1) * (i / 2);
        if (xPos >= 0 && xPos < width) {
            canvas[i][xPos] = PIXEL;
            canvas[i][width - xPos - 1] = PIXEL;
        }
    }
}

int main() {
    int height, width;
    printf("Enter canvas height (max %d): ", MAX_HEIGHT);
    scanf("%d", &height);
    printf("Enter canvas width (max %d): ", MAX_WIDTH);
    scanf("%d", &width);

    if (height > MAX_HEIGHT || width > MAX_WIDTH || height < 1 || width < 1) {
        printf("Invalid dimensions, please enter values between 1 and %d/%d.\n", MAX_HEIGHT, MAX_WIDTH);
        return 1;
    }

    // Create an empty canvas
    char canvas[MAX_HEIGHT][MAX_WIDTH];
    initializeCanvas(canvas, height, width);

    // Seed for random number generation
    srand(time(NULL));

    // Draw a random pattern
    drawRandomPattern(canvas, height, width);
    // Optionally draw an X shape over the random pattern
    drawXShape(canvas, height, width);

    // Display the final canvas
    printf("\nGenerated Pixel Art:\n");
    displayCanvas(canvas, height, width);

    return 0;
}