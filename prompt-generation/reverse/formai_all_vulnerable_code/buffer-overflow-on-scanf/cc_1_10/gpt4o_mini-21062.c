//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int r; // Red value
    int g; // Green value
    int b; // Blue value
} Color;

void printRomanticMessage() {
    printf("\nIn the world of colors, love is a shade of red,\n");
    printf("And when mixed with green, it blooms like a flower bed.\n");
    printf("Blue whispers secrets beneath the stars so bright,\n");
    printf("Together, they create a canvas of pure delight.\n");
}

Color hexToRGB(const char *hex) {
    Color color;
    
    // Check if the string starts with '#'
    if (hex[0] == '#') {
        hex++; // Skip past the '#' character
    }

    // Convert the hex string to RGB values
    sscanf(hex, "%02x%02x%02x", &color.r, &color.g, &color.b);
    return color;
}

void printColor(Color color) {
    printf("\nAh, the heart's color pulse can be felt:\n");
    printf("Red: %d, Green: %d, Blue: %d\n", color.r, color.g, color.b);
    printf("A color that speaks the language of love's glow.\n");
}

void rgbToHex(Color color, char *hex) {
    // Convert RGB to Hexadecimal format
    sprintf(hex, "#%02x%02x%02x", color.r, color.g, color.b);
}

void romanticColorMenu() {
    printf("\nWelcome to the Color of Love Converter!\n");
    printf("1. Convert Hexadecimal to RGB\n");
    printf("2. Convert RGB to Hexadecimal\n");
    printf("3. Exit\n");
}

int main() {
    int choice;
    char hex[7]; // To hold a hex color code
    Color color;
    char hexResult[7]; // Resulting hex value after conversion

    printf("\nAn enchanting journey awaits...\n");
    printRomanticMessage();

    while (1) {
        romanticColorMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter a hexadecimal color code (e.g., #ff5733): ");
            scanf("%s", hex);
            color = hexToRGB(hex);
            printColor(color);
        } else if (choice == 2) {
            printf("Enter the RGB values (0-255) separated by spaces (e.g., 255 87 51): ");
            scanf("%d %d %d", &color.r, &color.g, &color.b);
            rgbToHex(color, hexResult);
            printf("\nThe exquisite hex representation of your love's hues is: %s\n", hexResult);
        } else if (choice == 3) {
            printf("\nThank you for this colorful rendezvous!\n");
            printf("May your days be filled with vibrant hues of love...\n");
            break;
        } else {
            printf("Oh dear, it seems you have wandered off the path!\n");
        }
        
        printf("\nWould you like to explore more? (1 for Yes, 0 for No): ");
        int exploreMore;
        scanf("%d", &exploreMore);
        
        if (exploreMore == 0) {
            printf("\nParting is such sweet sorrow...\n");
            break;
        }
    }
    return 0;
}