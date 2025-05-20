//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COLOR_CODE_LENGTH 7

typedef struct Color {
    int r;
    int g;
    int b;
} Color;

Color hexToRgb(char* hexColor) {
    Color rgbColor;
    int R, V;

    if (sscanf(hexColor, "#%x%x%x", &R, &V, &V) != 3) {
        printf("Invalid Color Code: %s\n", hexColor);
        exit(EXIT_FAILURE);
    }

    rgbColor.r = R * 17;
    rgbColor.g = V * 17;
    rgbColor.b = V * 17;

    if (rgbColor.r > 255) rgbColor.r %= 256;
    if (rgbColor.g > 255) rgbColor.g %= 256;
    if (rgbColor.b > 255) rgbColor.b %= 256;

    return rgbColor;
}

void printColor(Color color) {
    printf("Color: R(%d) G(%d) B(%d)\n", color.r, color.g, color.b);
}

int main() {
    char inputColorCode[MAX_COLOR_CODE_LENGTH + 1];

    printf("Color Code Converter v1.0\n");
    printf("---------------------------\n");

    while (1) {
        printf("\nEnter a color code (in hexadecimal format, prefixed with '#'): ");
        scanf("%s", inputColorCode);

        Color result = hexToRgb(inputColorCode);
        printColor(result);

        printf("\nDo you want to convert another color? (Y/N): ");
        char response;
        scanf(" %c", &response);

        if (response != 'Y' && response != 'y') break;
    }

    return 0;
}