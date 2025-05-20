//FormAI DATASET v1.0 Category: Color Code Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to convert hexadecimal to decimal */
int hexToDec(char hex[]) {
    int len = strlen(hex);
    int base = 1;
    int dec = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            dec += (hex[i] - 48) * base;
            base *= 16;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            dec += (hex[i] - 87) * base;
            base *= 16;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            dec += (hex[i] - 55) * base;
            base *= 16;
        }
    }
    return dec;
}

/* Function to convert RGB values to hexadecimal */
int rgbToHex(int r, int g, int b) {
    int hex = (r << 16) | (g << 8) | b;
    return hex;
}

int main() {
    int r, g, b;
    printf("Enter the RGB values (0-255):\n");
    printf("Red: ");
    scanf("%d", &r);
    printf("Green: ");
    scanf("%d", &g);
    printf("Blue: ");
    scanf("%d", &b);
    printf("The RGB values are: (%d, %d, %d)\n", r, g, b);

    int hex = rgbToHex(r, g, b);
    printf("The hexadecimal value is: #%06X\n", hex);

    char hexString[7];
    sprintf(hexString, "#%06X", hex);
    printf("The equivalent color code is: %s\n", hexString);

    /* Convert hexadecimal to RGB */
    char hexValue[7];
    printf("\nEnter a hexadecimal color code: ");
    scanf("%s", hexValue);
    int red = hexToDec((char[]){hexValue[1], hexValue[2], '\0'});
    int green = hexToDec((char[]){hexValue[3], hexValue[4], '\0'});
    int blue = hexToDec((char[]){hexValue[5], hexValue[6], '\0'});
    printf("The equivalent RGB values are: (%d, %d, %d)\n", red, green, blue);

    return 0;
}