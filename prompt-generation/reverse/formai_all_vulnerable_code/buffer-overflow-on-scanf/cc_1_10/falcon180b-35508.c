//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert hexadecimal to RGB color code
void hexToRGB(char *hex, int *r, int *g, int *b) {
    if (strlen(hex)!= 7) {
        printf("Invalid hexadecimal code\n");
        exit(1);
    }
    char hexDigit;
    int i = 0;
    *r = 0;
    *g = 0;
    *b = 0;
    for (i = 0; i < 6; i++) {
        hexDigit = hex[i];
        if (isdigit(hexDigit)) {
            *r = *r * 16 + hexDigit - '0';
        } else {
            *r = *r * 16 + hexDigit - 'A' + 10;
        }
    }
    *b = *r;
    *g = *b;
}

// Function to convert RGB color code to hexadecimal
void RGBToHex(int r, int g, int b, char *hex) {
    sprintf(hex, "#%02X%02X%02X", r, g, b);
}

// Function to convert color code from one format to another
void convertColor(char *input, char *output) {
    int r, g, b;
    if (strlen(input) == 7) {
        if (input[0] == '#') {
            hexToRGB(input, &r, &g, &b);
            RGBToHex(r, g, b, output);
        } else {
            hexToRGB(input, &r, &g, &b);
            sprintf(output, "#%02X%02X%02X", r, g, b);
        }
    } else if (strlen(input) == 9) {
        if (input[0] == '#') {
            sscanf(input, "#%02X%02X%02X", &r, &g, &b);
            sprintf(output, "#%02X%02X%02X", r, g, b);
        } else {
            sscanf(input, "%02X%02X%02X", &r, &g, &b);
            sprintf(output, "#%02X%02X%02X", r, g, b);
        }
    } else {
        printf("Invalid color code\n");
        exit(1);
    }
}

int main() {
    char input[20], output[20];
    printf("Enter a color code (in hexadecimal or RGB format): ");
    scanf("%s", input);
    convertColor(input, output);
    printf("Color code in hexadecimal format: %s\n", output);
    return 0;
}