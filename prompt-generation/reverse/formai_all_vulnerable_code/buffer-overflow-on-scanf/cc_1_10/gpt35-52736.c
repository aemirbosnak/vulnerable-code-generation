//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Claude Shannon
/* 
 * This program converts a given color in RGB format to its equivalent hexadecimal color code.
 */

#include <stdio.h>
#include <stdlib.h>

// function to convert RGB values to hexadecimal code
void RGBtoHex(int r, int g, int b, char *hexCode) {

    int hexVal[6];
    int rem, temp;
    int i = 0, j;

    // converting red color value to hexadecimal
    while (r != 0) {
        rem = r % 16;
        hexVal[i++] = rem < 10 ? 48 + rem : 55 + rem;
        r = r / 16;
    }

    // converting green color value to hexadecimal
    while (g != 0) {
        rem = g % 16;
        hexVal[i++] = rem < 10 ? 48 + rem : 55 + rem;
        g = g / 16;
    }

    // converting blue color value to hexadecimal
    while (b != 0) {
        rem = b % 16;
        hexVal[i++] = rem < 10 ? 48 + rem : 55 + rem;
        b = b / 16;
    }

    // arranging the hexadecimal values in correct order
    for (j = 0; j < 6; j++)
        hexCode[j] = hexVal[5 - j];

}

int main() {

    int red, green, blue;
    char hexCode[7];

    // inputting the RGB color values
    printf("Enter the RGB values of the color (in the range of 0-255): \n");
    printf("Red: ");
    scanf("%d", &red);
    printf("Green: ");
    scanf("%d", &green);
    printf("Blue: ");
    scanf("%d", &blue);

    // validating if the RGB values are in valid range
    if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255) {
        printf("Invalid RGB values. Please enter values in the range of 0-255.\n");
        return 1;
    }

    // calling the RGB to hexadecimal conversion function
    RGBtoHex(red, green, blue, hexCode);

    // printing the hexadecimal color code
    printf("The corresponding hexadecimal color code is #%s\n", hexCode);

    return 0;
}