//FormAI DATASET v1.0 Category: Color Code Converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Function to convert RGB to HEX code
int rgbToHex(int r, int g, int b) {
    int hex = 0;
    // Left shift red color
    hex |= (r << 16);
    // Left shift green color
    hex |= (g << 8);
    // Add blue color to create final hex code
    hex |= b;
    return hex;
}

// Function to convert HEX to RGB code
void hexToRgb(int hex, int *r, int *g, int *b) {
    // Extract red color
    *r = (hex & 0xff0000) >> 16;
    // Extract green color
    *g = (hex & 0x00ff00) >> 8;
    // Extract blue color
    *b = (hex & 0x0000ff);
}

int main() {
    int r, g, b, hex;
    char option;
    
    printf("Welcome to Color Code Converter!\n\n");

    do {
        printf("Please select an option:\n");
        printf("1. Convert RGB to HEX code\n");
        printf("2. Convert HEX to RGB code\n");
        printf("3. Exit\n");
        scanf(" %c", &option); // Space before %c to clear newline character
        
        switch (option) {
            case '1':
                printf("\nEnter Red, Green, and Blue colors (0-255):\n");
                scanf("%d %d %d", &r, &g, &b);
                // Check if the colors are within range
                if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
                    printf("Error: Colors must be within 0-255 range.\n");
                    break;
                }
                hex = rgbToHex(r, g, b);
                printf("\nHEX code: #%06X\n\n", hex);
                break;
            case '2':
                printf("\nEnter HEX code (e.g. FFFFFF):\n");
                scanf("%X", &hex);
                int success = sscanf("000000", "%2X%2X%2X", &r, &g, &b); // Initialize RGB colors with 0
                // Check if the HEX code is valid
                if (hex > 0xffffff || success != 3) {
                    printf("Error: Invalid HEX code.\n");
                    break;
                }
                hexToRgb(hex, &r, &g, &b);
                printf("\nRGB code: (%d,%d,%d)\n\n", r, g, b);
                break;
            case '3':
                printf("\nExiting Color Code Converter. Have a good day!\n");
                exit(0);
            default:
                printf("\nInvalid option. Please try again.\n\n");
        }
        
    } while (option != '3');
    
    return 0;
}