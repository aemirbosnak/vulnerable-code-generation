//FormAI DATASET v1.0 Category: Color Code Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hexToDec(char hexVal[]) {
    int len = strlen(hexVal);
    int base = 1;
    int decVal = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (hexVal[i] >= '0' && hexVal[i] <= '9') {
            decVal += (hexVal[i] - 48) * base;
            base *= 16;
        }
        else if (hexVal[i] >= 'a' && hexVal[i] <= 'f') {
            decVal += (hexVal[i] - 87) * base;
            base *= 16;
        }
        else if (hexVal[i] >= 'A' && hexVal[i] <= 'F') {
            decVal += (hexVal[i] - 55) * base;
            base *= 16;
        }
    }
    return decVal;
}

void convertToRGB(char colorCode[]) {
    int len = strlen(colorCode);
    char red[3] = { colorCode[1], colorCode[2], '\0' };
    char green[3] = { colorCode[3], colorCode[4], '\0' };
    char blue[3] = { colorCode[5], colorCode[6], '\0' };
    int r = hexToDec(red);
    int g = hexToDec(green);
    int b = hexToDec(blue);
    printf("RGB Color Code: (%d, %d, %d)\n", r, g, b);
}

void convertToCMYK(char colorCode[]) {
    int len = strlen(colorCode);
    char red[3] = { colorCode[1], colorCode[2], '\0' };
    char green[3] = { colorCode[3], colorCode[4], '\0' };
    char blue[3] = { colorCode[5], colorCode[6], '\0' };
    int r = hexToDec(red);
    int g = hexToDec(green);
    int b = hexToDec(blue);
    double c, m, y, k;
    c = 1 - (r / 255.0);
    m = 1 - (g / 255.0);
    y = 1 - (b / 255.0);
    k = c < m ? (c < y ? c : y) : (m < y ? m : y);
    c = (c - k) / (1 - k);
    m = (m - k) / (1 - k);
    y = (y - k) / (1 - k);
    k = k * 100;
    c = c * 100;
    m = m * 100;
    y = y * 100;
    printf("CMYK Color Code: (%.1f%%, %.1f%%, %.1f%%, %.1f%%)\n", c, m, y, k);
}

int main() {
    char colorCode[8];
    printf("Enter C Color Code: ");
    scanf("%s", colorCode);
    if (colorCode[0] == '#' && strlen(colorCode) == 7) {
        convertToRGB(colorCode);
        convertToCMYK(colorCode);
    }
    else {
        printf("Invalid C Color Code!\n");
    }
    return 0;
}