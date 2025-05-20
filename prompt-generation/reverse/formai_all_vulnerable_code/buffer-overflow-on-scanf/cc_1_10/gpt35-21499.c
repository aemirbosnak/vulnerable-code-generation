//FormAI DATASET v1.0 Category: Color Code Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//helper function to convert hex string to decimal integer
int hexCharToInt(char c) {
    if (c >= '0' && c <= '9') {
        return (int)c - '0';
    } else if (c >= 'A' && c <= 'F') {
        return (int)(c - 'A') + 10;
    } else if (c >= 'a' && c <= 'f') {
        return (int)(c - 'a') + 10;
    } else {
        printf("[ERROR] Invalid hex character: '%c'\n", c);
        exit(1);
    }
}

//function to convert hex color code to RGB values
void hexToRgb(char* hexCode, int rgb[]) {
    if (strlen(hexCode) != 7) {
        printf("[ERROR] Invalid hex color code: '%s'\n", hexCode);
        exit(1);
    }
    rgb[0] = hexCharToInt(hexCode[1]) * 16 + hexCharToInt(hexCode[2]); //red value
    rgb[1] = hexCharToInt(hexCode[3]) * 16 + hexCharToInt(hexCode[4]); //green value
    rgb[2] = hexCharToInt(hexCode[5]) * 16 + hexCharToInt(hexCode[6]); //blue value
}

//function to convert RGB values to hex color code
void rgbToHex(int rgb[], char* hexCode) {
    sprintf(hexCode, "#%02x%02x%02x", rgb[0], rgb[1], rgb[2]);
}

int main() {
    char colorCode[8]; //hex color code string (including hash character)
    int rgb[3]; //RGB color values

    printf("Enter a hex color code (e.g., #FF0000): ");
    scanf("%s", colorCode);

    if (colorCode[0] != '#') {
        printf("[ERROR] Invalid hex color code format: '%s'\n", colorCode);
        exit(1);
    }

    hexToRgb(colorCode, rgb);
    printf("RGB color values: (%d, %d, %d)\n", rgb[0], rgb[1], rgb[2]);

    rgbToHex(rgb, colorCode);
    printf("Hex color code: %s\n", colorCode);

    return 0;
}