//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 20

// Function Prototypes
void displayMenu();
void rgbToHex(int r, int g, int b);
void hexToRgb(const char *hex);
void validateRgbValues(int r, int g, int b);
void validateHexString(const char *hex);

int main() {
    int choice;
    char hexInput[MAX_INPUT_LENGTH];
    int r, g, b;

    printf("Welcome to the Futuristic Color Code Converter!\n");
    printf("Version 2077\n");

    while (1) {
        displayMenu();
        printf("Please select an option (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // RGB to Hex
                printf("Enter RGB values (0-255) separated by spaces (e.g., 255 0 0 for Red): ");
                scanf("%d %d %d", &r, &g, &b);
                validateRgbValues(r, g, b);
                rgbToHex(r, g, b);
                break;

            case 2:
                // Hex to RGB
                printf("Enter HEX color code (e.g., #FF5733): ");
                scanf("%s", hexInput);
                validateHexString(hexInput);
                hexToRgb(hexInput);
                break;

            case 3:
                // Exit
                printf("Exiting the Futuristic Color Code Converter. Have a colorful day!\n");
                return 0;

            default:
                printf("Invalid option. Please choose again.\n");
                break;
        }
    }
}

// Function to display the menu options
void displayMenu() {
    printf("\n----------------------------------\n");
    printf("1. Convert RGB to Hex\n");
    printf("2. Convert Hex to RGB\n");
    printf("3. Exit\n");
    printf("----------------------------------\n");
}

// Function to convert RGB to Hex color code
void rgbToHex(int r, int g, int b) {
    printf("Hex Color Code: #%02X%02X%02X\n", r, g, b);
}

// Function to convert Hex code to RGB
void hexToRgb(const char *hex) {
    int r, g, b;
    // Skip the '#' character
    sscanf(hex + 1, "%02X%02X%02X", &r, &g, &b);
    printf("RGB Color Code: (%d, %d, %d)\n", r, g, b);
}

// Function to validate RGB values
void validateRgbValues(int r, int g, int b) {
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        fprintf(stderr, "Invalid RGB values! They must be between 0 and 255.\n");
        exit(EXIT_FAILURE);
    }
}

// Function to validate Hex string
void validateHexString(const char *hex) {
    if (hex[0] != '#' || strlen(hex) != 7) {
        fprintf(stderr, "Invalid HEX format! It must start with '#' and be followed by 6 hex digits.\n");
        exit(EXIT_FAILURE);
    }
}