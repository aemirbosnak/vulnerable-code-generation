//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 15
#define SUCCESS 0
#define ERROR -1

// Function prototypes
int isValidRGB(int r, int g, int b);
void rgbToHex(int r, int g, int b, char* hexColor);
void convertColor();
void displayColor(char* hexColor);

// Main function
int main() {
    printf("Welcome to the RGB to Hexadecimal Color Code Converter\n");
    char choice;

    do {
        convertColor();
        printf("Would you like to convert another color? (Y/N): ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');

    printf("Thank you for using the converter!\n");
    return SUCCESS;
}

// Function to check if RGB values are valid
int isValidRGB(int r, int g, int b) {
    return (r >= 0 && r <= 255) && (g >= 0 && g <= 255) && (b >= 0 && b <= 255);
}

// Function to convert RGB to Hex
void rgbToHex(int r, int g, int b, char* hexColor) {
    sprintf(hexColor, "#%02X%02X%02X", r, g, b);
}

// Function to handle the conversion process
void convertColor() {
    int r, g, b;
    char hexColor[7]; // Hex color string of the form #RRGGBB

    printf("Please enter the RGB values:\n");
    printf("Red (0-255): ");
    scanf("%d", &r);
    printf("Green (0-255): ");
    scanf("%d", &g);
    printf("Blue (0-255): ");
    scanf("%d", &b);

    if (isValidRGB(r, g, b)) {
        rgbToHex(r, g, b, hexColor);
        displayColor(hexColor);
    } else {
        printf("Error: One or more RGB values are out of range. Please enter values between 0 and 255.\n");
    }
}

// Function to display the converted hex color
void displayColor(char* hexColor) {
    printf("The hexadecimal color code is: %s\n", hexColor);
}