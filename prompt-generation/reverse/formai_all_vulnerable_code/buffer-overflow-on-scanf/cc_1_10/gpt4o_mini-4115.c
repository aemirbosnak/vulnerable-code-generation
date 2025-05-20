//GPT-4o-mini DATASET v1.0 Category: Pixel Art Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Function to display the pixel art
void displayPixelArt(int width, int height, char pixelChar, char bgChar) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Smiley face coordinates
            if ((x == width / 2 - 1 && y == height / 2 - 1) || // Left eye
                (x == width / 2 + 1 && y == height / 2 - 1) || // Right eye
                (x >= width / 2 - 2 && x <= width / 2 + 2 && y == height / 2) || // Mouth
                (x >= width / 2 - 1 && x <= width / 2 + 1 && y == height / 2 + 2)) { // Face outline
                printf("%c", pixelChar);
            } else {
                printf("%c", bgChar);
            }
        }
        printf("\n");
    }
}

// Function to get user input with limits
int getUserInput(const char *prompt, int min, int max) {
    int val;
    do {
        printf("%s (%d - %d): ", prompt, min, max);
        scanf("%d", &val);
    } while (val < min || val > max);
    return val;
}

// Main function
int main() {
    int width, height;
    char pixelChar, bgChar;

    printf("Welcome to Pixel Art Generator!\n");

    // Get configurable input for pixel art
    width = getUserInput("Enter the width of the art (5 - 40)", 5, 40);
    height = getUserInput("Enter the height of the art (5 - 20)", 5, 20);
    printf("Enter the character for the pixels: ");
    scanf(" %c", &pixelChar);  // note the space before %c to consume any leftover newline character
    printf("Enter the background character: ");
    scanf(" %c", &bgChar); 

    // Call the function to display the pixel art
    printf("\nHere is your Pixel Art:\n");
    displayPixelArt(width, height, pixelChar, bgChar);

    return 0;
}