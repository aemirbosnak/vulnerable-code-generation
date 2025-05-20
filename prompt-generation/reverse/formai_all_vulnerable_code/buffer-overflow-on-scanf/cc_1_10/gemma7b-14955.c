//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 16

typedef struct Color {
    int r;
    int g;
    int b;
} Color;

Color convert_color(char color_code) {
    Color color;

    switch (color_code) {
        case 'r':
            color.r = 255;
            color.g = 0;
            color.b = 0;
            break;
        case 'g':
            color.r = 0;
            color.g = 255;
            color.b = 0;
            break;
        case 'b':
            color.r = 0;
            color.g = 0;
            color.b = 255;
            break;
        case 'y':
            color.r = 255;
            color.g = 255;
            color.b = 0;
            break;
        case 'm':
            color.r = 0;
            color.g = 255;
            color.b = 255;
            break;
        case 'c':
            color.r = 255;
            color.g = 255;
            color.b = 255;
            break;
        default:
            printf("Invalid color code.\n");
            exit(1);
    }

    return color;
}

int main() {
    char color_code;

    printf("Enter a color code: ");
    scanf("%c", &color_code);

    Color color = convert_color(color_code);

    printf("Red: %d\n", color.r);
    printf("Green: %d\n", color.g);
    printf("Blue: %d\n", color.b);

    return 0;
}