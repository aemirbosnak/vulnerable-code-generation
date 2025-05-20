//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert hexadecimal to RGB
void hexToRgb(char* hex, int* r, int* g, int* b) {
    char red[7] = {0};
    char green[7] = {0};
    char blue[7] = {0};

    strncpy(red, hex, 2);
    strncpy(green, hex + 2, 2);
    strncpy(blue, hex + 4, 2);

    *r = atoi(red);
    *g = atoi(green);
    *b = atoi(blue);
}

// Function to convert RGB to hexadecimal
void rgbToHex(int r, int g, int b, char* hex) {
    sprintf(hex, "#%02X%02X%02X", r, g, b);
}

// Function to validate hexadecimal input
int isHex(char* hex) {
    int len = strlen(hex);

    if (len!= 6 && len!= 8) {
        return 0;
    }

    for (int i = 0; i < len; i++) {
        if (!isxdigit(hex[i])) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char input[100];
    char output[9];
    int r, g, b;

    // Get user input
    printf("Enter a color code (hexadecimal or RGB): ");
    scanf("%s", input);

    // Convert input to uppercase
    for (int i = 0; i < strlen(input); i++) {
        input[i] = toupper(input[i]);
    }

    // Check if input is in hexadecimal format
    if (input[0] == '#') {
        // Convert hexadecimal to RGB
        if (isHex(input)) {
            hexToRgb(input, &r, &g, &b);
            rgbToHex(r, g, b, output);
            printf("RGB: %s\n", output);
        } else {
            printf("Invalid hexadecimal input.\n");
        }
    } else {
        // Convert RGB to hexadecimal
        if (sscanf(input, "%d,%d,%d", &r, &g, &b) == 3) {
            rgbToHex(r, g, b, output);
            printf("Hexadecimal: %s\n", output);
        } else {
            printf("Invalid RGB input.\n");
        }
    }

    return 0;
}