//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rgbToHex(int r, int g, int b, char* hexColor) {
    sprintf(hexColor, "#%02X%02X%02X", r, g, b);
}

void hexToRgb(const char* hexColor, int* r, int* g, int* b) {
    unsigned int hexValue;
    sscanf(hexColor + 1, "%x", &hexValue);
    *r = (hexValue >> 16) & 0xFF;
    *g = (hexValue >> 8) & 0xFF;
    *b = hexValue & 0xFF;
}

void printMenu() {
    printf("Color Code Converter\n");
    printf("---------------------\n");
    printf("1. Convert RGB to Hex\n");
    printf("2. Convert Hex to RGB\n");
    printf("3. Exit\n");
    printf("---------------------\n");
}

void convertRgbToHex() {
    int r, g, b;
    char hexColor[8];
    
    printf("Enter RGB values (0-255) separated by spaces: ");
    scanf("%d %d %d", &r, &g, &b);

    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        printf("Error: RGB values must be between 0 and 255.\n");
        return;
    }

    rgbToHex(r, g, b, hexColor);
    printf("Hex Color: %s\n", hexColor);
}

void convertHexToRgb() {
    char hexColor[8];
    int r, g, b;

    printf("Enter Hex color code (e.g., #FFFFFF): ");
    scanf("%s", hexColor);

    if (hexColor[0] != '#' || strlen(hexColor) != 7) {
        printf("Error: Invalid Hex format. Use #RRGGBB format.\n");
        return;
    }

    hexToRgb(hexColor, &r, &g, &b);
    printf("RGB Color: (%d, %d, %d)\n", r, g, b);
}

int main() {
    int choice;

    while (1) {
        printMenu();
        printf("Select an option (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                convertRgbToHex();
                break;
            case 2:
                convertHexToRgb();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please select again.\n");
                break;
        }
        
        printf("\n");
    }

    return 0;
}