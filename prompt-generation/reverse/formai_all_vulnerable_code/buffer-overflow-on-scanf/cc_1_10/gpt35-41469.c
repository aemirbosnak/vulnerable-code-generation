//FormAI DATASET v1.0 Category: Color Code Converter ; Style: peaceful
#include <stdio.h>

// Function to convert RGB to HEX color code
int rgbToHex(int r, int g, int b) {
    // Shift bits to create HEX value
    int hex = ((r << 16) | (g << 8) | b);

    return hex;
}

// Function to convert HEX to RGB color code
void hexToRgb(int hex) {
    // Extract color codes from HEX and store in RGB variables
    int r = (hex >> 16) & 0xFF;
    int g = (hex >> 8) & 0xFF;
    int b = (hex) & 0xFF;

    printf("RGB Value: %d, %d, %d\n", r, g, b);
}

int main() {
    int r, g, b, hex;
    char option;

    printf("Welcome to the Color Code Converter!\n\n");

    do {
        // Menu options
        printf("Select an option:\n");
        printf("1. Convert RGB to HEX\n");
        printf("2. Convert HEX to RGB\n\n");

        // User input
        printf("Option: ");
        scanf(" %c", &option);

        // RGB to HEX conversion
        if (option == '1') {
            printf("\nEnter the RGB values (0-255):\n");
            printf("Red: ");
            scanf("%d", &r);
            printf("Green: ");
            scanf("%d", &g);
            printf("Blue: ");
            scanf("%d", &b);

            hex = rgbToHex(r, g, b);

            printf("\nHEX Value: %X\n", hex);
        }
        // HEX to RGB conversion
        else if (option == '2') {
            printf("\nEnter the HEX value (ex: FFFFFF): ");
            scanf("%X", &hex);

            hexToRgb(hex);
        }
        // Invalid option
        else {
            printf("\nInvalid option. Please try again.\n\n");
        }

        // Ask user if they want to convert another color code
        printf("\nConvert another color code? (Y/N): ");
        scanf(" %c", &option);

        // Display goodbye message if user chooses to exit
        if (option == 'N' || option == 'n') {
            printf("\nThank you for using the Color Code Converter. Goodbye!\n");
        }

    } while (option == 'Y' || option == 'y');

    return 0;
}