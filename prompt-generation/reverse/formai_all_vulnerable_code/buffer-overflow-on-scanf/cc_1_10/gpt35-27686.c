//FormAI DATASET v1.0 Category: Color Code Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to convert hexadecimal to decimal
int hexToDecimal(char hex[]) {
    int length = strlen(hex);
    int base = 1;
    int decimal = 0;
    for (int i = length - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - 48) * base;
            base *= 16;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 55) * base;
            base *= 16;
        }
    }
    return decimal;
}

//function to convert decimal to binary
void decimalToBinary(int decimal, char binary[]) {
    int k = 7;
    while (decimal > 0) {
        binary[k--] = decimal % 2 + '0';
        decimal = decimal / 2;
    }
    for (int i = 0; i <= k; i++) {
        binary[i] = '0';
    }
    binary[8] = '\0';
}

//function to convert RGB color code to hexadecimal
char* rgbToHex(int r, int g, int b) {
    char* hex = (char*)calloc(7, sizeof(char));
    sprintf(hex, "#%02X%02X%02X", r, g, b);
    return hex;
}

//function to convert hexadecimal color code to RGB
void hexToRgb(char hex[], int* r, int* g, int* b) {
    if (strlen(hex) == 7 && hex[0] == '#') {
        char rHex[3] = { hex[1], hex[2], '\0' };
        char gHex[3] = { hex[3], hex[4], '\0' };
        char bHex[3] = { hex[5], hex[6], '\0' };
        *r = hexToDecimal(rHex);
        *g = hexToDecimal(gHex);
        *b = hexToDecimal(bHex);
    }
}

int main() {
    char input[20];
    printf("Enter color code (RGB/hexadecimal): ");
    scanf("%s", input);

    int r, g, b;
    char hex[7];
    if (strlen(input) == 7 && input[0] == '#') {
        hexToRgb(input, &r, &g, &b);
        printf("RGB color code is: %d, %d, %d\n", r, g, b);
    }
    else if (strcmp(input, "RGB") == 0) {
        printf("Enter values for red, green and blue (0-255):\n");
        scanf("%d%d%d", &r, &g, &b);
        sprintf(hex, "%s", rgbToHex(r, g, b));
        printf("Hexadecimal color code is: %s\n", hex);
    }
    else {
        printf("Invalid input!\n");
    }

    return 0;
}