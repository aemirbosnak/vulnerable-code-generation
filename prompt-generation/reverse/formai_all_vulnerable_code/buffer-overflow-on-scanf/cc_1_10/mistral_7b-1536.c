//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

// Function to convert RGB to Hexadecimal
void rgbToHex(int r, int g, int b, char hex[7]) {
    int values[SIZE];
    int index;

    values[0] = r;
    values[1] = g;
    values[2] = b;

    for (index = 0; index < SIZE; index++) {
        int digit1 = values[index] / 16;
        int digit2 = values[index] % 16;

        if (digit1 > 9)
            hex[index * 2] = digit1 + 55;
        else
            hex[index * 2] = digit1 + 48;

        if (digit2 > 9)
            hex[index * 2 + 1] = digit2 + 55;
        else
            hex[index * 2 + 1] = digit2 + 48;
    }
    hex[SIZE * 2] = '\0';
}

// Function to convert Hexadecimal to RGB
void hexToRgb(char hex[3], int rgb[SIZE]) {
    int r, g, b;
    int index;

    for (index = 0; index < SIZE; index++) {
        if (hex[index * 2] >= '0' && hex[index * 2] <= '9') {
            rgb[index] = (hex[index * 2] - '0') * 16;
        } else if (hex[index * 2] >= 'A' && hex[index * 2] <= 'F') {
            rgb[index] = (hex[index * 2] - 'A' + 10) * 16;
        }

        if (index == 0) {
            r = rgb[index];
        } else {
            switch (hex[index * 2 + 1]) {
                case '0':
                    g = rgb[index] << 4;
                    break;
                case '1':
                    g = rgb[index] << 3;
                    break;
                case '2':
                    g = rgb[index] << 2;
                    break;
                case '3':
                    g = rgb[index] << 1;
                    break;
                case '4':
                    g = rgb[index] << 0;
                    break;
                default:
                    g = rgb[index];
            }

            rgb[index] = r + g;
        }
    }
}

int main() {
    int r, g, b;
    char hex[7];

    printf("Enter RGB values (R G B): ");
    scanf("%d%d%d", &r, &g, &b);

    rgbToHex(r, g, b, hex);
    printf("Hexadecimal equivalent: %s\n", hex);

    printf("Enter Hexadecimal values (HH HH HH): ");
    scanf("%s", hex);

    int rgb[SIZE];
    hexToRgb(hex, rgb);
    printf("RGB equivalent: R(%d), G(%d), B(%d)\n", rgb[0], rgb[1], rgb[2]);

    return 0;
}