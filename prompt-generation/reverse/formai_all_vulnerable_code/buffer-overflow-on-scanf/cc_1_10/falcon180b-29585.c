//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char hex[8];
    int decimal;
} Color;

Color hexToDecimal(char* hex) {
    Color result;
    result.hex[0] = hex[0];
    result.hex[1] = hex[1];
    result.hex[2] = hex[2];
    result.hex[3] = hex[3];
    result.hex[4] = hex[4];
    result.hex[5] = hex[5];
    result.hex[6] = '\0';
    result.decimal = strtol(result.hex, NULL, 16);
    return result;
}

Color* decimalToHex(int decimal) {
    Color* result = malloc(sizeof(Color));
    sprintf(result->hex, "%06X", decimal);
    result->decimal = decimal;
    return result;
}

void printColor(Color color) {
    printf("%s (%d)\n", color.hex, color.decimal);
}

int main() {
    char input[10];
    Color color;

    // Convert hex to decimal
    printf("Enter a hex color code: ");
    scanf("%s", input);
    color = hexToDecimal(input);
    printColor(color);

    // Convert decimal to hex
    int decimal = 16777215; // Example decimal value
    Color* hexColor = decimalToHex(decimal);
    printColor(*hexColor);

    return 0;
}