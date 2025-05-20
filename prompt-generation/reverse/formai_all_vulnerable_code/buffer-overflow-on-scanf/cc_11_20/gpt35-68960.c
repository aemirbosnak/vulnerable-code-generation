//FormAI DATASET v1.0 Category: Color Code Converter ; Style: satisfied
#include <stdio.h>

int main() {
    // variables to hold the RGB values
    int red, green, blue;

    // prompt the user to enter the RGB values
    printf("Enter the values for red, green, and blue (separated by spaces): ");
    scanf("%d %d %d", &red, &green, &blue);

    // check if the input values are within the correct range (0-255)
    if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255) {
        printf("Invalid input values. RGB values must be between 0 and 255.\n");
        return 1;
    }

    // convert the RGB values to hex values
    int hex1 = red / 16;
    int hex2 = red % 16;
    int hex3 = green / 16;
    int hex4 = green % 16;
    int hex5 = blue / 16;
    int hex6 = blue % 16;

    // convert the hex values to color codes
    char color1, color2, color3, color4, color5, color6;

    if (hex1 < 10) {
        color1 = hex1 + '0';
    } else {
        color1 = hex1 + 55;
    }

    if (hex2 < 10) {
        color2 = hex2 + '0';
    } else {
        color2 = hex2 + 55;
    }

    if (hex3 < 10) {
        color3 = hex3 + '0';
    } else {
        color3 = hex3 + 55;
    }

    if (hex4 < 10) {
        color4 = hex4 + '0';
    } else {
        color4 = hex4 + 55;
    }

    if (hex5 < 10) {
        color5 = hex5 + '0';
    } else {
        color5 = hex5 + 55;
    }

    if (hex6 < 10) {
        color6 = hex6 + '0';
    } else {
        color6 = hex6 + 55;
    }

    // print the color code
    printf("The color code is #%c%c%c%c%c%c\n", color1, color2, color3, color4, color5, color6);

    return 0;
}