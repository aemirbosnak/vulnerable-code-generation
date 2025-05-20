//FormAI DATASET v1.0 Category: Color Code Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 7 // Maximum length of input string "#XXXXXX"
#define MAX_RGB_VALUE 255 // Maximum value for red, green and blue

// Function declarations
void printInstructions();
int validateInput(char color[]);
int hexToDec(char hexValue);
int hexToRgb(char color[], int *red, int *green, int *blue);
void rgbToHex(int red, int green, int blue, char hexValue[]);

// Main function
int main() {
    char color[MAX_INPUT_LENGTH];
    int red, green, blue;
    char hexValue[MAX_INPUT_LENGTH];
    
    printInstructions();
    
    while (1) {
        printf("\nEnter a color code (#XXXXXX), or press q to quit: ");
        scanf("%s", color);
        
        // Exit program if user enters "q"
        if (strcmp(color, "q") == 0) {
            printf("\nGoodbye.\n");
            break;
        }
        
        // Validate user input
        if (validateInput(color) == 0) {
            printf("Invalid input. Please enter a valid color code.\n");
            continue;
        }
        
        // Convert hex color code to RGB values
        if (hexToRgb(color, &red, &green, &blue) == 0) {
            printf("Invalid input. Please enter a valid color code.\n");
            continue;
        }
        
        // Convert RGB values back to hex color code
        rgbToHex(red, green, blue, hexValue);
        
        printf("The RGB values of %s are (%d, %d, %d) and the corresponding color code is %s.\n",
               color, red, green, blue, hexValue);
    }
    
    return 0;
}

// Function to print instructions to the user
void printInstructions() {
    printf("Welcome to the C Color Code Converter!\n\n");
    printf("This program converts a color code from hexadecimal format to RGB values, and vice versa.\n");
    printf("Enter a color code in the format #XXXXXX, where X is a hex digit (0-9, A-F, a-f).\n");
    printf("The color converter will then display the RGB values, and the corresponding color code.\n");
    printf("Enter \"q\" to quit the program.\n\n");
}

// Function to validate user input
int validateInput(char color[]) {
    int length = strlen(color);
    
    if (length != 7 || color[0] != '#' ||
        !isxdigit(color[1]) || !isxdigit(color[2]) || !isxdigit(color[3]) ||
        !isxdigit(color[4]) || !isxdigit(color[5]) || !isxdigit(color[6])) {
        return 0;
    }
    return 1;
}

// Function to convert hexadecimal value to decimal value
int hexToDec(char hexValue) {
    if (hexValue >= '0' && hexValue <= '9') {
        return hexValue - '0';
    }
    else if (hexValue >= 'A' && hexValue <= 'F') {
        return hexValue - 'A' + 10;
    }
    else { // hexValue >= 'a' && hexValue <= 'f'
        return hexValue - 'a' + 10;
    }
}

// Function to convert hex color code to RGB values
int hexToRgb(char color[], int *red, int *green, int *blue) {
    int i;
    
    // Convert first 2 hex digits to red value
    *red = hexToDec(color[1]) * 16 + hexToDec(color[2]);
    
    // Convert next 2 hex digits to green value
    *green = hexToDec(color[3]) * 16 + hexToDec(color[4]);
    
    // Convert last 2 hex digits to blue value
    *blue = hexToDec(color[5]) * 16 + hexToDec(color[6]);
    
    // Check if RGB values are valid (0-255)
    if (*red < 0 || *red > MAX_RGB_VALUE ||
        *green < 0 || *green > MAX_RGB_VALUE ||
        *blue < 0 || *blue > MAX_RGB_VALUE) {
        return 0;
    }
    return 1;
}

// Function to convert RGB values to hex color code
void rgbToHex(int red, int green, int blue, char hexValue[]) {
    sprintf(hexValue, "#%02X%02X%02X", red, green, blue);
}