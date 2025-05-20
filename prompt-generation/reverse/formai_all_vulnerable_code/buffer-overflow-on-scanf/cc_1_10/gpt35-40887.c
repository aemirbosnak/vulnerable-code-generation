//FormAI DATASET v1.0 Category: Color Code Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Convert hexadecimal to decimal
int hexToDec(char hex[]) {
    int len = strlen(hex);
    int base = 1;
    int dec = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            dec += (hex[i] - 48) * base;
            base *= 16;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            dec += (hex[i] - 55) * base;
            base *= 16;
        }
    }
    return dec;
}

// Convert decimal to hexadecimal
char *decToHex(int dec) {
    static char hex[4];
    sprintf(hex, "%X", dec);
    return hex;
}

int main() {
    char input[7];
    printf("Enter a RGB color code (example: #FF0000): ");
    scanf("%s", input);

    // Remove the # symbol if it exists
    if (input[0] == '#') {
        memmove(&input[0], &input[1], strlen(input));
    }

    // Extract the red, green, and blue values
    char red[3] = {input[0], input[1], '\0'};
    char green[3] = {input[2], input[3], '\0'};
    char blue[3] = {input[4], input[5], '\0'};

    // Convert hexadecimal to decimal
    int r = hexToDec(red);
    int g = hexToDec(green);
    int b = hexToDec(blue);

    // Convert decimal to percentage
    float rPct = (float)r / 255 * 100;
    float gPct = (float)g / 255 * 100;
    float bPct = (float)b / 255 * 100;

    printf("RGB: %d, %d, %d\n", r, g, b);
    printf("Percentage: %.2f%%, %.2f%%, %.2f%%\n", rPct, gPct, bPct);

    // Convert decimal to hexadecimal
    char *rHex = decToHex(r);
    char *gHex = decToHex(g);
    char *bHex = decToHex(b);

    printf("Hexadecimal: #%s%s%s\n", rHex, gHex, bHex);

    return 0;
}