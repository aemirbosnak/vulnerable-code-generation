//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void displayMenu();
void rgbToHex(int r, int g, int b);
void hexToRgb(const char *hex);
void convertAndDisplay(const char *input);

// Function to show the menu
void displayMenu() {
    printf("Color Code Converter\n");
    printf("====================\n");
    printf("1. RGB to HEX\n");
    printf("2. HEX to RGB\n");
    printf("3. Exit\n");
    printf("Select an option (1-3): ");
}

// Function to convert RGB to HEX
void rgbToHex(int r, int g, int b) {
    printf("HEX: #%02X%02X%02X\n", r, g, b);
}

// Function to convert HEX to RGB
void hexToRgb(const char *hex) {
    int r, g, b;
    if (sscanf(hex, "#%02x%02x%02x", &r, &g, &b) == 3) {
        printf("RGB: (%d, %d, %d)\n", r, g, b);
    } else {
        printf("Invalid HEX code format.\n");
    }
}

// Function to read input and invoke appropriate conversion
void convertAndDisplay(const char *input) {
    if (strlen(input) == 7 && input[0] == '#') {
        // It's a HEX code
        hexToRgb(input);
    } else {
        // Assume it's an RGB input (comma-separated)
        int r, g, b;
        if (sscanf(input, "%d,%d,%d", &r, &g, &b) == 3) {
            if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255) {
                printf("RGB values must be between 0 and 255.\n");
            } else {
                rgbToHex(r, g, b);
            }
        } else {
            printf("Invalid input format. Use 'r,g,b' for RGB or '#RRGGBB' for HEX.\n");
        }
    }
}

int main() {
    int option;
    char input[20];

    while (1) {
        displayMenu();
        if (scanf("%d", &option) != 1) {
            while (getchar() != '\n'); // Clean the input buffer
            printf("Invalid option. Please enter a number between 1 and 3.\n");
            continue;
        }
        
        switch (option) {
            case 1:
                printf("Enter RGB value (r,g,b): ");
                scanf("%s", input);
                convertAndDisplay(input);
                break;
            case 2:
                printf("Enter HEX value (e.g., #RRGGBB): ");
                scanf("%s", input);
                convertAndDisplay(input);
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please select again.\n");
        }
    }

    return 0;
}