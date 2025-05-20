//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Function to convert color code from hex to decimal
int hexToDecimal(char hexCode[]) {
    int decimalValue = 0, base = 0;
    int len = strlen(hexCode);
    for (int i = len - 1; i >= 0; i--) {
        if (hexCode[i] >= '0' && hexCode[i] <= '9') {
            decimalValue += hexCode[i] - '0';
        } else if (hexCode[i] >= 'A' && hexCode[i] <= 'F') {
            decimalValue += hexCode[i] - 'A' + 10;
        } else if (hexCode[i] >= 'a' && hexCode[i] <= 'f') {
            decimalValue += hexCode[i] - 'a' + 10;
        } else {
            return -1;
        }
        base *= 16;
    }
    return decimalValue;
}

//Function to convert decimal to color code
void decimalToColorCode(int decimalValue, char colorCode[]) {
    char hexCode[7];
    int len = 0;
    while (decimalValue > 0) {
        int rem = decimalValue % 16;
        if (rem < 10) {
            hexCode[len++] = rem + '0';
        } else {
            hexCode[len++] = rem + 'A' - 10;
        }
        decimalValue /= 16;
    }
    for (int i = 0; i < 6; i++) {
        colorCode[i] = hexCode[i];
    }
    colorCode[6] = '\0';
}

int main() {
    char colorCode[7];
    int decimalValue;
    printf("Enter the color code in hexadecimal format: ");
    scanf("%s", colorCode);
    decimalValue = hexToDecimal(colorCode);
    if (decimalValue == -1) {
        printf("Invalid color code\n");
    } else {
        decimalToColorCode(decimalValue, colorCode);
        printf("The color code in decimal format is: %s\n", colorCode);
    }
    return 0;
}