//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void hexToRgb(const char *hex);
void rgbToHex(int r, int g, int b);
void printInstructions();

int main() {
    char choice[10];
    printInstructions();

    while (1) {
        printf("Would you like to convert from (1) HEX to RGB or (2) RGB to HEX? (0 to exit): ");
        fgets(choice, sizeof(choice), stdin);
        int option = atoi(choice);

        if (option == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        if (option == 1) {
            char hex[8];
            printf("Please enter a HEX color code (e.g., #FF5733): ");
            fgets(hex, sizeof(hex), stdin);
            hex[strcspn(hex, "\n")] = 0; // Remove newline character
            hexToRgb(hex);
        } else if (option == 2) {
            int r, g, b;
            printf("Please enter RGB values separated by spaces (e.g., 255 87 51): ");
            scanf("%d %d %d", &r, &g, &b);
            getchar(); // Consume the newline character left by scanf
            rgbToHex(r, g, b);
        } else {
            printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

// Function to convert HEX color to RGB
void hexToRgb(const char *hex) {
    // Check if the input is valid
    if (hex[0] != '#' || strlen(hex) != 7) {
        printf("Invalid HEX format. Make sure it starts with '#' followed by 6 hexadecimal digits.\n");
        return;
    }

    int r, g, b;

    // Convert HEX values to integers
    sscanf(hex + 1, "%02x%02x%02x", &r, &g, &b);
    
    // Output the result
    printf("The RGB equivalent of %s is (%d, %d, %d).\n", hex, r, g, b);
}

// Function to convert RGB color to HEX
void rgbToHex(int r, int g, int b) {
    // Validate RGB values
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        printf("Invalid RGB values. Each component must be in the range 0-255.\n");
        return;
    }

    // Output the result
    printf("The HEX equivalent of (%d, %d, %d) is #%02X%02X%02X.\n", r, g, b, r, g, b);
}

// Function to print instructions for the user
void printInstructions() {
    printf("Welcome to the Color Code Converter!\n");
    printf("This program allows you to convert color values between HEX and RGB formats.\n");
    printf("You can choose to convert from HEX color codes to RGB values, or vice versa.\n");
    printf("Follow the prompts for input, and let your creativity with colors shine!\n");
    printf("Enter '0' at any time to exit the program.\n\n");
}