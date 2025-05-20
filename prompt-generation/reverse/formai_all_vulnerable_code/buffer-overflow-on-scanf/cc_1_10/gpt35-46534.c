//FormAI DATASET v1.0 Category: Color Code Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Function to convert RGB values to Hexadecimal
char* RGBtoHex(int red, int green, int blue) {

    // Allocate memory for the Hexadecimal value string
    char *hexValue = (char *) malloc(sizeof(char) * 8);

    // Convert RGB values to Hexadecimal
    sprintf(hexValue,"#%02X%02X%02X", red, green, blue);

    // Return the Hexadecimal value string
    return hexValue;
}

// Function to convert Hexadecimal value to RGB values
int* HexToRGB(char hexValue[]) {

    // Allocate memory for the RGB values array
    int *rgbValues = (int *) malloc(sizeof(int) * 3);

    // Convert Hexadecimal to RGB values
    sscanf(hexValue, "#%2x%2x%2x", &rgbValues[0], &rgbValues[1], &rgbValues[2]);

    // Return the RGB values array
    return rgbValues;
}

int main() {
    int red, green, blue;
    char hexValue[8];

    printf("Enter the RGB color values (0-255):\n");
    printf("Red: ");
    scanf("%d", &red);
    printf("Green: ");
    scanf("%d", &green);
    printf("Blue: ");
    scanf("%d", &blue);

    // Convert RGB values to Hexadecimal
    char *result = RGBtoHex(red, green, blue);
    printf("\nHexadecimal Value: %s\n", result);

    printf("\nEnter a Hexadecimal color value:\n");
    scanf("%s", hexValue);

    // Convert Hexadecimal value to RGB values
    int *rgbResult = HexToRGB(hexValue);
    printf("\nRGB Values:\nRed: %d\nGreen: %d\nBlue: %d\n", rgbResult[0], rgbResult[1], rgbResult[2]);

    // Free dynamically allocated memory
    free(result);
    free(rgbResult);

    return 0;
}