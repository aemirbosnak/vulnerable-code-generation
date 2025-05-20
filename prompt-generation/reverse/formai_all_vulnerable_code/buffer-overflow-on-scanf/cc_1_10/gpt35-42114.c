//FormAI DATASET v1.0 Category: Color Code Converter ; Style: optimized
#include <stdio.h>

int hexToDec(char hexVal[]) {
    int len = strlen(hexVal);
    int base = 1;
    int decVal = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (hexVal[i] >= '0' && hexVal[i] <= '9') {
            decVal += (hexVal[i] - 48) * base;
            base *= 16;
        } else if (hexVal[i] >= 'a' && hexVal[i] <= 'f') {
            decVal += (hexVal[i] - 87) * base;
            base *= 16;
        } else if (hexVal[i] >= 'A' && hexVal[i] <= 'F') {
            decVal += (hexVal[i] - 55) * base;
            base *= 16;
        }
    }

    return decVal;
}

void decToRGB(int decVal) {
    int r = (decVal >> 16) & 0xFF;
    int g = (decVal >> 8) & 0xFF;
    int b = decVal & 0xFF;

    printf("RGB Value: (%d,%d,%d)\n", r, g, b);
}

void decToHex(int decVal) {
    char hexVal[7];
    sprintf(hexVal, "#%02X%02X%02X", (decVal >> 16) & 0xFF, (decVal >> 8) & 0xFF, decVal & 0xFF);
    printf("Hex Value: %s\n", hexVal);
}

int main() {
    char hexVal[7];
    printf("Enter hex code value: ");
    scanf("%s", hexVal);

    if (hexVal[0] == '#') {
        int decVal = hexToDec(hexVal + 1);
        decToRGB(decVal);
    } else {
        int decVal = hexToDec(hexVal);
        decToHex(decVal);
    }

    return 0;
}