//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert RGB to HEX
void rgbToHex(int r, int g, int b) {
    printf("The HEX representation of RGB(%d, %d, %d) is: #%02X%02X%02X\n", r, g, b, r, g, b);
}

// Function to convert HEX to RGB
void hexToRgb(const char* hex) {
    int r, g, b;
    if (sscanf(hex + 1, "%02x%02x%02x", &r, &g, &b) == 3) {
        printf("The RGB representation of HEX %s is: (%d, %d, %d)\n", hex, r, g, b);
    } else {
        printf("Oops! The HEX input is not valid. Please make sure it starts with '#' and has 6 hex digits.\n");
    }
}

int main() {
    int choice;
    printf("🎉 Welcome to the Color Code Converter! 🌈\n");
    printf("Please choose what you'd like to do:\n");
    printf("1. Convert RGB to HEX\n");
    printf("2. Convert HEX to RGB\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        int r, g, b;
        printf("Please enter the Red value (0-255): ");
        scanf("%d", &r);
        printf("Please enter the Green value (0-255): ");
        scanf("%d", &g);
        printf("Please enter the Blue value (0-255): ");
        scanf("%d", &b);

        if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
            printf("😢 Uh-oh! RGB values should be between 0 and 255. Please try again!\n");
        } else {
            rgbToHex(r, g, b);
        }
    } else if (choice == 2) {
        char hex[8]; // 7 chars for #RRGGBB + 1 for null terminator
        printf("Please enter a HEX color (e.g., #FF5733): ");
        scanf("%s", hex);
        
        if (strlen(hex) != 7 || hex[0] != '#') {
            printf("😟 Oh no! The HEX format doesn't look quite right. Make sure it's #RRGGBB.\n");
        } else {
            hexToRgb(hex);
        }
    } else {
        printf("🤔 Oh dear! That's not a valid choice. Please run the program again and choose 1 or 2.\n");
    }

    printf("🎈 Thank you for using the Color Code Converter! Have a colorful day! 🌞\n");
    return 0;
}