//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 10

typedef struct Color {
    unsigned char r, g, b;
} Color;

Color hexToRgb(char *hexColor) {
    Color color;
    unsigned int r, g, b, i;

    if (strlen(hexColor) != 7) {
        printf("Invalid hex color format!\n");
        exit(1);
    }

    for (i = 0; i < 3; i++) {
        if (sscanf(hexColor + i * 2, "%2x", &r) != 1) {
            printf("Invalid hex color format!\n");
            exit(1);
        }
        switch (i) {
            case 0:
                color.r = r;
                break;
            case 1:
                color.g = r;
                break;
            case 2:
                color.b = r;
                break;
        }

        hexColor += 2;
    }

    return color;
}

void printColor(Color color) {
    printf("RGB(%u, %u, %u)\n", color.r, color.g, color.b);
}

int main() {
    Color color;
    char hexColor[SIZE];

    printf("Enter a hex color value: ");
    scanf("%s", hexColor);

    color = hexToRgb(hexColor);
    printColor(color);

    return 0;
}