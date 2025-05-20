//GPT-4o-mini DATASET v1.0 Category: Pixel Art Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEIGHT 20
#define MAX_WIDTH 40
#define MAX_COLORS 8

// Function to set color in terminal
void setColor(int background, int foreground) {
    printf("\033[%d;%dm", background + 40, foreground + 30);
}

// Function to reset color
void resetColor() {
    printf("\033[0m");
}

// Function to generate random pixel art
void generatePixelArt(int height, int width) {
    // 2D array to hold pixel colors
    int pixels[MAX_HEIGHT][MAX_WIDTH];
    
    // Randomly fill pixels with color values
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            pixels[i][j] = rand() % MAX_COLORS; // Random color index
        }
    }

    // Print the pixel art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int foreground = pixels[i][j];
            int background = (foreground + 1) % MAX_COLORS;
            setColor(background, foreground);
            printf("  "); // Print pixel as a block
        }
        printf("\n");
    }
    resetColor();
}

// Main function
int main() {
    srand(time(NULL)); // Seed random number generator

    int height, width;

    // Get user input for height and width
    printf("Enter height of pixel art (max %d): ", MAX_HEIGHT);
    scanf("%d", &height);
    printf("Enter width of pixel art (max %d): ", MAX_WIDTH);
    scanf("%d", &width);

    // Validate input dimensions
    if (height > MAX_HEIGHT || width > MAX_WIDTH || height < 1 || width < 1) {
        printf("Dimensions should be between 1 and %d for height, and between 1 and %d for width.\n", MAX_HEIGHT, MAX_WIDTH);
        return 1;
    }

    // Generate and display pixel art
    generatePixelArt(height, width);
    return 0;
}