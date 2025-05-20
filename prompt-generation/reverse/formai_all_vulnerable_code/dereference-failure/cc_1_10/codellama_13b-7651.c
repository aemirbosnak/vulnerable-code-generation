//Code Llama-13B DATASET v1.0 Category: Color Code Converter ; Style: happy
// Color Code Converter Program
#include <stdio.h>

// Function to convert a hexadecimal color code to its RGB values
void hexToRgb(char *hexCode, int *red, int *green, int *blue) {
    // Convert hexadecimal color code to uppercase
    char upperHexCode[7];
    strcpy(upperHexCode, hexCode);
    for (int i = 0; i < strlen(upperHexCode); i++) {
        if (upperHexCode[i] >= 'a' && upperHexCode[i] <= 'f') {
            upperHexCode[i] = upperHexCode[i] - 32;
        }
    }

    // Extract the red, green, and blue values from the hexadecimal color code
    *red = strtol(&upperHexCode[1], NULL, 16);
    *green = strtol(&upperHexCode[3], NULL, 16);
    *blue = strtol(&upperHexCode[5], NULL, 16);
}

// Function to convert RGB values to a hexadecimal color code
void rgbToHex(int red, int green, int blue, char *hexCode) {
    // Convert the RGB values to a hexadecimal color code
    sprintf(hexCode, "#%02x%02x%02x", red, green, blue);
}

// Main function
int main() {
    // Declare variables
    char hexCode[7];
    int red, green, blue;

    // Get the hexadecimal color code from the user
    printf("Enter a hexadecimal color code (e.g. #FF0000): ");
    scanf("%s", hexCode);

    // Convert the hexadecimal color code to RGB values
    hexToRgb(hexCode, &red, &green, &blue);

    // Print the RGB values
    printf("Red: %d\nGreen: %d\nBlue: %d\n", red, green, blue);

    // Convert the RGB values back to a hexadecimal color code
    rgbToHex(red, green, blue, hexCode);

    // Print the hexadecimal color code
    printf("Hexadecimal color code: %s\n", hexCode);

    return 0;
}