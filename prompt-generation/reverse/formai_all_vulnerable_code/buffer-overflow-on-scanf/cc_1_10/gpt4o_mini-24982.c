//GPT-4o-mini DATASET v1.0 Category: Pixel Art Generator ; Style: active
#include <stdio.h>
#include <stdlib.h>

void drawPixelArt(int width, int height, char pixelChar) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // An example design: We use different patterns to represent a simple art piece
            if ((x + y) % 2 == 0) {
                printf("%c", pixelChar);  // Pattern 1: Checkered pattern
            } else {
                printf(" ");  // Pattern 2: Spaces to create a design
            }
        }
        printf("\n");  // Move to the next line after finishing one row
    }
}

int main() {
    int width, height;
    char pixelChar;

    // Prompt user for pixel size and character
    printf("Welcome to the Pixel Art Generator!\n");
    printf("Please enter the width of the pixel art (e.g., 10): ");
    scanf("%d", &width);
    printf("Please enter the height of the pixel art (e.g., 5): ");
    scanf("%d", &height);
    printf("Please enter a character to use for the pixel art (e.g., *): ");
    scanf(" %c", &pixelChar);  // Notice space before %c to consume any newline character

    // Draw the pixel art based on user input
    printf("\nHere is your pixel art:\n");
    drawPixelArt(width, height, pixelChar);

    // Additional art options
    printf("\nWould you like to try another pattern? (Y/N): ");
    char another;
    scanf(" %c", &another);

    while (another == 'Y' || another == 'y') {
        printf("Please enter the width of the new pixel art: ");
        scanf("%d", &width);
        printf("Please enter the height of the new pixel art: ");
        scanf("%d", &height);
        printf("Please enter a character to use for the new pixel art: ");
        scanf(" %c", &pixelChar);

        printf("\nHere is your new pixel art:\n");
        drawPixelArt(width, height, pixelChar);

        printf("\nWould you like to try another pattern? (Y/N): ");
        scanf(" %c", &another);
    }

    printf("Thank you for using the Pixel Art Generator! Goodbye!\n");
    return 0;
}