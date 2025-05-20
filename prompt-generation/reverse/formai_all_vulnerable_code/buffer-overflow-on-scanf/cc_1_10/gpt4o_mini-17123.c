//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20

// Structure to represent RGB colors
typedef struct {
    int r;
    int g;
    int b;
} RGB;

// Structure to represent HEX colors
typedef struct {
    char hex[MAX_LENGTH];
} HEX;

// Function to convert HEX to RGB
RGB hexToRGB(const char *hex) {
    RGB rgb;
    sscanf(hex + 1, "%02x%02x%02x", &rgb.r, &rgb.g, &rgb.b);
    return rgb;
}

// Function to convert RGB to HEX
void rgbToHEX(RGB rgb, HEX *hex) {
    sprintf(hex->hex, "#%02x%02x%02x", rgb.r, rgb.g, rgb.b);
}

// Function to validate a HEX color string
int isValidHex(const char *hex) {
    return (hex[0] == '#' && strlen(hex) == 7);
}

// Function to display the menu
void displayMenu() {
    printf("\n==========================\n");
    printf(" C Color Code Converter\n");
    printf("==========================\n");
    printf("1. Convert HEX to RGB\n");
    printf("2. Convert RGB to HEX\n");
    printf("3. Exit\n");
    printf("==========================\n");
    printf("Please select an option (1-3): ");
}

// Main function
int main() {
    while (1) {
        displayMenu();
        int option;
        scanf("%d", &option);
        getchar(); // To consume the newline character left in the buffer

        switch (option) {
            case 1: {
                char hex[MAX_LENGTH];
                printf("Enter HEX color (e.g. #RRGGBB): ");
                fgets(hex, sizeof(hex), stdin);
                hex[strcspn(hex, "\n")] = 0; // Remove newline character
                
                if (!isValidHex(hex)) {
                    printf("Invalid HEX format! Please use #RRGGBB format.\n");
                    break;
                }

                RGB rgb = hexToRGB(hex);
                printf("RGB Value: (%d, %d, %d)\n", rgb.r, rgb.g, rgb.b);
                break;
            }
            case 2: {
                RGB rgb;
                printf("Enter RGB values (R G B): ");
                scanf("%d %d %d", &rgb.r, &rgb.g, &rgb.b);

                if (rgb.r < 0 || rgb.r > 255 || rgb.g < 0 || rgb.g > 255 || rgb.b < 0 || rgb.b > 255) {
                    printf("RGB values must be between 0 and 255!\n");
                    break;
                }

                HEX hex;
                rgbToHEX(rgb, &hex);
                printf("HEX Value: %s\n", hex.hex);
                break;
            }
            case 3:
                printf("Thank you for using the C Color Code Converter! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please select a valid option (1-3).\n");
        }
    }

    return 0;
}