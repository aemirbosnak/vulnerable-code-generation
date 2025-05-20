//FormAI DATASET v1.0 Category: Color Code Converter ; Style: genious
#include <stdio.h>

// function to convert RGB values to hexadecimal code
int RGB2Hex(int r, int g, int b) {
    // check if RGB values are within valid range
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        printf("Invalid RGB values\n");
        return -1; // return -1 indicating error
    }
    // calculate hexadecimal code for RGB values
    int hex = (r << 16) | (g << 8) | b;
    return hex;
}

// function to convert hexadecimal code to RGB values
void Hex2RGB(int hex, int *r, int *g, int *b) {
    // check if hexadecimal code is valid
    if (hex < 0x000000 || hex > 0xFFFFFF) {
        printf("Invalid hexadecimal code\n");
        return; // return without modifying RGB values
    }
    // extract R, G, B values from hexadecimal code
    *r = (hex >> 16) & 0xFF;
    *g = (hex >> 8) & 0xFF;
    *b = hex & 0xFF;
}

int main() {
    printf("Welcome to the C Color Code Converter Program!\n");

    // get user input for RGB values
    int r, g, b;
    printf("Enter the red (0-255): ");
    scanf("%d", &r);
    printf("Enter the green (0-255): ");
    scanf("%d", &g);
    printf("Enter the blue (0-255): ");
    scanf("%d", &b);
    
    // convert RGB values to hexadecimal code
    int hex = RGB2Hex(r, g, b);
    if (hex == -1) {
        return 1; // exit program with error code 1
    }
    printf("The hexadecimal code for RGB (%d, %d, %d) is #%06X\n", r, g, b, hex);

    // get user input for hexadecimal code
    int input;
    printf("Enter a hexadecimal code (without #): ");
    scanf("%X", &input);
    
    // convert hexadecimal code to RGB values
    int red, green, blue;
    Hex2RGB(input, &red, &green, &blue);
    printf("The RGB values for #%06X are (%d, %d, %d)\n", input, red, green, blue);

    printf("Thank you for using the C Color Code Converter Program!\n");
    return 0; // exit program with success code 0
}