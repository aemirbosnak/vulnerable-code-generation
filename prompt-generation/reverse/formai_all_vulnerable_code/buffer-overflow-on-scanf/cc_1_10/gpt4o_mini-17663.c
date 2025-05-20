//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Function to convert RGB to Hex
void rgbToHex(int r, int g, int b, char hex[]) {
    sprintf(hex, "#%02X%02X%02X", r, g, b);
}

// Function to take input safely
int getInput(const char *prompt) {
    int value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &value) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // clear the input buffer
        } else if (value < 0 || value > 255) {
            printf("Value must be between 0 and 255.\n");
        } else {
            break; // valid input
        }
    }
    return value;
}

int main() {
    // Variable declarations
    int red, green, blue;
    char hexColor[8]; // +1 for null terminator

    printf("Welcome to the RGB to Hex Color Converter!\n");
    
    // Get RGB values from user
    red = getInput("Enter Red component (0-255): ");
    green = getInput("Enter Green component (0-255): ");
    blue = getInput("Enter Blue component (0-255): ");

    // Convert to Hex
    rgbToHex(red, green, blue, hexColor);

    // Display the result
    printf("The hexadecimal color code for RGB(%d, %d, %d) is: %s\n", red, green, blue, hexColor);
    
    // Ask if the user wants to do another conversion
    char another;
    do {
        printf("Do you want to convert another RGB color? (y/n): ");
        while(getchar() != '\n'); // clear the input buffer
        scanf("%c", &another);
        if (another == 'y' || another == 'Y') {
            red = getInput("Enter Red component (0-255): ");
            green = getInput("Enter Green component (0-255): ");
            blue = getInput("Enter Blue component (0-255): ");
            rgbToHex(red, green, blue, hexColor);
            printf("The hexadecimal color code for RGB(%d, %d, %d) is: %s\n", red, green, blue, hexColor);
        }
    } while (another == 'y' || another == 'Y');

    printf("Thank you for using the RGB to Hex Color Converter!\n");
    return 0;
}