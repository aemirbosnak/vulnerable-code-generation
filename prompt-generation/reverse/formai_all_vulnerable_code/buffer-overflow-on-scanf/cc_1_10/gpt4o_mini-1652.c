//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Oooooo, colors! Who doesn't love a good color?
// Let's make this world more colorful, one code at a time!

// Function prototypes
void rgbToHex(int r, int g, int b);
void hexToRgb(const char* hex);
void printWelcomeMessage();
void printGoodbyeMessage();

int main() {
    printWelcomeMessage();

    int choice;
    
    // A little menu for our colorful adventure!
    printf("Choose your adventure:\n");
    printf("1. RGB to Hex\n");
    printf("2. Hex to RGB\n");
    printf("3. Exit (the colorless void)\n");
    
    // This is not a cruel game, I promise!
    while (1) {
        printf("Your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            int r, g, b;
            printf("Enter R (0-255): ");
            scanf("%d", &r);
            printf("Enter G (0-255): ");
            scanf("%d", &g);
            printf("Enter B (0-255): ");
            scanf("%d", &b);
            // Check if values are actually colors and not an alien language
            if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
                printf("Oops! Maybe try a different color, like a carrot or something.\n");
            } else {
                rgbToHex(r, g, b);
            }
        } else if (choice == 2) {
            char hex[7];
            printf("Enter HEX code (without #, e.g., FF5733): ");
            scanf("%6s", hex); // Ensuring a strict limit to avoid colorful overflow
            hexToRgb(hex);
        } else if (choice == 3) {
            printGoodbyeMessage();
            break;
        } else {
            printf("What kind of adventure is that? Please choose again!\n");
        }
    }
    return 0;
}

void rgbToHex(int r, int g, int b) {
    // Ready to be stunned by the brightness of the RGB!
    printf("Converting RGB(%d, %d, %d) to Hex...\n", r, g, b);
    printf("Your color in HEX is: #%02X%02X%02X\n", r, g, b);
}

void hexToRgb(const char* hex) {
    // Let's decode those mysterious colors!
    int r, g, b;
    if (sscanf(hex, "%2X%2X%2X", &r, &g, &b) != 3) {
        printf("Yikes! That doesn’t appear to be a valid hex color code. Color crisis averted!\n");
        return;
    }
    printf("Your HEX # %s converts to RGB(%d, %d, %d)\n", hex, r, g, b);
}

void printWelcomeMessage() {
    // Welcome message, but not too welcome!
    printf("🎨 Welcome to the Color Code Converter! 🎨\n");
    printf("Here you can convert RGB values to HEX and vice versa!\n");
    printf("Let's get colorful!\n");
}

void printGoodbyeMessage() {
    // A farewell, but not too sad!
    printf("🌈 Thanks for stopping by the Color Code Converter! 🌈\n");
    printf("May your colors always be bright and your code always compile!\n");
}