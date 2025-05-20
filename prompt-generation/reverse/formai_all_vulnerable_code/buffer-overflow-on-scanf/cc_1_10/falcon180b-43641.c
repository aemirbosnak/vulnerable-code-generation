//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to check if a string is a valid hex color code
int isValidHexColorCode(char *colorCode) {
    int length = strlen(colorCode);
    if (length!= 7 && length!= 9) {
        return 0;
    }
    for (int i = 0; i < length; i++) {
        char c = colorCode[i];
        if (i == 0 && c!= '#') {
            return 0;
        }
        if (!isxdigit(c)) {
            return 0;
        }
    }
    return 1;
}

// Function to convert a hex color code to RGB
void hexToRgb(char *hex, int *rgb) {
    if (strlen(hex) == 7) {
        rgb[0] = hex[1] * 16 + hex[2];
        rgb[1] = hex[3] * 16 + hex[4];
        rgb[2] = hex[5] * 16 + hex[6];
    } else {
        rgb[0] = hex[1] * 16 + hex[2];
        rgb[1] = hex[3] * 16 + hex[4];
        rgb[2] = hex[5] * 16 + hex[6];
        rgb[3] = 255;
    }
}

// Function to convert an RGB color to hex
void rgbToHex(int *rgb, char *hex) {
    sprintf(hex, "#%02X%02X%02X", rgb[0], rgb[1], rgb[2]);
}

// Function to convert a color code to another format
void convertColorCode(char *input, char *output) {
    if (isValidHexColorCode(input)) {
        int rgb[3];
        hexToRgb(input, rgb);
        rgbToHex(rgb, output);
    } else {
        strcpy(output, input);
    }
}

int main() {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];

    printf("Enter a color code: ");
    scanf("%s", input);

    convertColorCode(input, output);

    printf("The converted color code is: %s\n", output);

    return 0;
}