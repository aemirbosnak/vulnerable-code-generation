//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

#define RED (1 << 5)
#define GREEN (1 << 3)
#define BLUE (1 << 1)

int main() {
    byte color[3] = {0};
    byte out[3] = {0};
    char dec2hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    printf("Enter 3 values from 0-255, separated by spaces: ");
    scanf("%hhu %hhu %hhu", &color[0], &color[1], &color[2]);

    // Hex conversion
    for (int i = 0; i < 3; i++) {
        out[i] = (dec2hex[color[i] / 16] << 4) | dec2hex[color[i] % 16];
    }

    printf("Equivalent hex color: #%02X%02X%02X\n", out[0], out[1], out[2]);

    // Binary conversion
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 8; j++) {
            out[i] |= (color[i] & (1 << j)) >> j;
            out[i] <<= 1;
        }
    }

    printf("Equivalent binary color: ");
    for (int i = 0; i < 3; i++) {
        for (int j = 7; j >= 0; j--) {
            printf("%d", (out[i] >> j) & 1);
        }
        if (i < 2) printf(" ");
    }
    printf("\n");

    // Magic trick
    color[0] ^= RED | BLUE;
    color[1] ^= GREEN;
    color[2] ^= RED;

    printf("Magic trick result: %02X%02X%02X\n", color[0], color[1], color[2]);

    return 0;
}