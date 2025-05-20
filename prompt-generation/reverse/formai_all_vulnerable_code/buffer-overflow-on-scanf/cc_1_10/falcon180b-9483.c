//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 7

// Function to convert RGB color code to hexadecimal format
void rgbToHex(int r, int g, int b, char* hex) {
    sprintf(hex, "#%02X%02X%02X", r, g, b);
}

// Function to convert hexadecimal color code to RGB format
void hexToRgb(char* hex, int* r, int* g, int* b) {
    if (strlen(hex)!= MAX_CODE_LENGTH) {
        *r = *g = *b = 0;
        return;
    }

    int value;
    sscanf(hex, "#%02x%02x%02x", &value, &value, &value);

    *r = value >> 16;
    *g = value >> 8 & 0xFF;
    *b = value & 0xFF;
}

// Function to validate hexadecimal color code
int isValidHex(char* hex) {
    if (strlen(hex)!= MAX_CODE_LENGTH) {
        return 0;
    }

    for (int i = 0; i < strlen(hex); i++) {
        if (!isxdigit(hex[i])) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char input[MAX_CODE_LENGTH + 1];
    char output[MAX_CODE_LENGTH + 1];

    printf("Enter a color code (RGB or hexadecimal): ");
    scanf("%s", input);

    if (isValidHex(input)) {
        rgbToHex(0, 0, 0, output);
    } else {
        int r, g, b;
        hexToRgb(input, &r, &g, &b);
        rgbToHex(r, g, b, output);
    }

    printf("Converted color code: %s\n", output);

    return 0;
}