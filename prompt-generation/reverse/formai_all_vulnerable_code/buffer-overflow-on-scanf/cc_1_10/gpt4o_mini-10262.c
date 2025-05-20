//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Structure to represent RGB color
typedef struct {
    unsigned char r; // Red component
    unsigned char g; // Green component
    unsigned char b; // Blue component
} RGB;

// Structure to represent HEX color
typedef struct {
    char hex[7]; // HEX color code (without '#')
} HEX;

// Function to convert RGB to HEX
HEX rgbToHex(RGB rgb) {
    HEX hexColor;
    snprintf(hexColor.hex, sizeof(hexColor.hex), "%02X%02X%02X", rgb.r, rgb.g, rgb.b);
    return hexColor;
}

// Function to convert HEX to RGB
RGB hexToRgb(const char* hex) {
    RGB rgbColor;
    sscanf(hex, "%2hhX%2hhX%2hhX", &rgbColor.r, &rgbColor.g, &rgbColor.b);
    return rgbColor;
}

// Function to print the color
void printColor(const char* label, RGB color) {
    printf("%s: RGB(%d, %d, %d)\n", label, color.r, color.g, color.b);
}

// Function to display the color in HEX format
void displayHEX(HEX hex) {
    printf("HEX: #%s\n", hex.hex);
}

// Function to run the color converter
void runColorConverter() {
    int choice;
    RGB rgbColor;
    HEX hexColor;

    printf("Color Code Converter\n");
    printf("1. Convert RGB to HEX\n");
    printf("2. Convert HEX to RGB\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter RGB values (0-255) separated by spaces (e.g., 255 0 0): ");
        scanf("%hhu %hhu %hhu", &rgbColor.r, &rgbColor.g, &rgbColor.b);
        hexColor = rgbToHex(rgbColor);
        printColor("Input Color", rgbColor);
        displayHEX(hexColor);
    } else if (choice == 2) {
        printf("Enter HEX color code (without #): ");
        char inputHex[7];
        scanf("%6s", inputHex);
        rgbColor = hexToRgb(inputHex);
        printf("Input HEX: #%s\n", inputHex);
        printColor("Converted Color", rgbColor);
    } else {
        printf("Invalid choice! Please restart the program.\n");
    }
}

// Main function
int main() {
    runColorConverter();
    return 0;
}