//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Function to convert RGB to Hex
void RGBToHex(int r, int g, int b) {
    printf("Your RGB values %d, %d, %d transform into the mystical Hex: #%02X%02X%02X\n", r, g, b, r, g, b);
}

// Function to convert Hex to RGB
void HexToRGB(const char *hex) {
    int r, g, b;
    // Convert hex to RGB values
    if (sscanf(hex + 1, "%02x%02x%02x", &r, &g, &b) == 3) {
        printf("The magic of Hex color %s unveils its RGB form: (%d, %d, %d)\n", hex, r, g, b);
    } else {
        printf("Alas! The Hex code is not valid. The colors remain hidden...\n");
    }
}

int main() {
    int choice;
    printf("Welcome to the Shape-Shifting Color Code Converter!\n");
    printf("1. Convert RGB to Hex\n");
    printf("2. Convert Hex to RGB\n");
    printf("Choose your path (1 or 2): ");
    scanf("%d", &choice);

    // Color transformation based on user choice
    if (choice == 1) {
        int r, g, b;
        printf("Enter RGB values (separated by spaces): ");
        scanf("%d %d %d", &r, &g, &b);
        if (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255) {
            RGBToHex(r, g, b);
        } else {
            printf("Beware! RGB values must be between 0 and 255. The colors fade away...\n");
        }
    } else if (choice == 2) {
        char hex[8];
        printf("Enter Hex color code (e.g., #FF5733): ");
        scanf("%s", hex);
        if (hex[0] == '#' && strlen(hex) == 7) {
            HexToRGB(hex);
        } else {
            printf("Oh no! The Hex code is not in the correct format. Reality is skewed...\n");
        }
    } else {
        printf("A strange choice! The shape-shifting program puzzled...\n");
    }

    printf("Thank you for using the Shape-Shifting Color Code Converter! Farewell!\n");
    return 0;
}