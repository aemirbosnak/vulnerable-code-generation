//GPT-4o-mini DATASET v1.0 Category: Pixel Art Generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

void drawPixelArt(char art[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            putchar(art[i][j]);
        }
        putchar('\n');
    }
}

int main() {
    int width, height;
    char fillChar;

    printf("Welcome to the C Pixel Art Generator!\n");
    
    // Prompt for width and height
    printf("Enter the width of the pixel art (max %d): ", MAX_WIDTH);
    scanf("%d", &width);
    if (width < 1 || width > MAX_WIDTH) {
        printf("Width must be between 1 and %d.\n", MAX_WIDTH);
        return 1;
    }
    
    printf("Enter the height of the pixel art (max %d): ", MAX_HEIGHT);
    scanf("%d", &height);
    if (height < 1 || height > MAX_HEIGHT) {
        printf("Height must be between 1 and %d.\n", MAX_HEIGHT);
        return 1;
    }

    // Prompt for fill character
    printf("Enter a character to fill the pixel art: ");
    scanf(" %c", &fillChar);

    // Initialize the pixel art array
    char pixelArt[MAX_HEIGHT][MAX_WIDTH];

    // Fill the pixel art with the specified character
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            pixelArt[i][j] = fillChar;
        }
    }

    // Models a simple design logic (create a border with spaces)
    for (int i = 0; i < width; i++) {
        if (i % 2 == 0) {
            pixelArt[0][i] = ' ';
            pixelArt[height - 1][i] = ' ';
        }
    }

    for (int i = 0; i < height; i++) {
        if (i % 2 == 0) {
            pixelArt[i][0] = ' ';
            pixelArt[i][width - 1] = ' ';
        }
    }

    // Display the pixel art
    printf("\nHere is your pixel art:\n");
    drawPixelArt(pixelArt, width, height);

    return 0;
}