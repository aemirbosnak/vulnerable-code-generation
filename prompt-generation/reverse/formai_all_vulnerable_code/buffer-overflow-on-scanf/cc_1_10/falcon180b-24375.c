//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 16

typedef struct {
    char *name;
    unsigned char r, g, b;
} Color;

Color colors[MAX_COLORS] = {
    {"black", 0, 0, 0},
    {"white", 255, 255, 255},
    {"red", 255, 0, 0},
    {"green", 0, 255, 0},
    {"blue", 0, 0, 255},
    {"yellow", 255, 255, 0},
    {"cyan", 0, 255, 255},
    {"magenta", 255, 0, 255},
    {"gray", 128, 128, 128},
    {"light_gray", 192, 192, 192},
    {"dark_gray", 64, 64, 64},
    {"pink", 255, 192, 203},
    {"purple", 128, 0, 128},
    {"orange", 255, 128, 0},
    {"brown", 128, 64, 0}
};

int main() {
    char input[100];
    char *color_name;
    int i;

    printf("Enter a color name: ");
    scanf("%s", input);

    color_name = strtok(input, ",");
    for (i = 0; i < MAX_COLORS; i++) {
        if (strcmp(color_name, colors[i].name) == 0) {
            printf("RGB: %d, %d, %d\n", colors[i].r, colors[i].g, colors[i].b);
            printf("Hex: %06X\n", (colors[i].r << 16) | (colors[i].g << 8) | colors[i].b);
            printf("HSL: %d, %d, %d\n", 0, 0, 0); // TODO: implement HSL conversion
            printf("\n");
            return 0;
        }
    }

    printf("Invalid color name.\n");
    return 1;
}