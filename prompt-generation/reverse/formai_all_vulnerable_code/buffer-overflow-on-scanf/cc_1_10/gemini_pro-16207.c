//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COLOR_NAME_MAX_LENGTH 256

typedef struct {
    char name[COLOR_NAME_MAX_LENGTH];
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Color;

Color colors[] = {
    {"Red", 255, 0, 0},
    {"Green", 0, 255, 0},
    {"Blue", 0, 0, 255},
    {"Yellow", 255, 255, 0},
    {"Magenta", 255, 0, 255},
    {"Cyan", 0, 255, 255},
    {"White", 255, 255, 255},
    {"Black", 0, 0, 0},
    {"Gray", 128, 128, 128},
    {"Orange", 255, 165, 0},
    {"Purple", 128, 0, 128},
    {"Brown", 165, 42, 42},
    {"Pink", 255, 192, 203},
    {"Turquoise", 64, 224, 208},
    {"Gold", 255, 215, 0},
    {"Silver", 192, 192, 192},
    {"Bronze", 205, 127, 50},
    {"Copper", 192, 128, 64},
    {"Emerald", 0, 128, 0},
    {"Sapphire", 0, 128, 128},
    {"Ruby", 255, 0, 0},
    {"Amethyst", 128, 0, 128},
    {"Topaz", 255, 215, 0},
    {"Diamond", 240, 240, 240},
    {"Pearl", 255, 255, 240},
    {"Ivory", 255, 255, 224},
    {"Beige", 245, 245, 220},
    {"Khaki", 240, 230, 140},
    {"Olive", 128, 128, 0},
    {"Chartreuse", 128, 255, 0},
    {"Lime", 0, 255, 0},
    {"Forest Green", 0, 128, 0},
    {"Dark Green", 0, 100, 0},
    {"Sea Green", 46, 139, 87},
    {"Turquoise", 0, 255, 255},
    {"Light Blue", 173, 216, 230},
    {"Royal Blue", 0, 102, 204},
    {"Navy Blue", 0, 0, 128},
    {"Midnight Blue", 25, 25, 112},
    {"Indigo", 75, 0, 130},
    {"Violet", 148, 0, 211},
    {"Plum", 221, 160, 221},
    {"Lavender", 230, 230, 250},
    {"Magenta", 255, 0, 255},
    {"Fuchsia", 255, 0, 255},
    {"Crimson", 220, 20, 60},
    {"Maroon", 128, 0, 0},
    {"Chocolate", 210, 105, 30},
    {"Tan", 210, 180, 140},
    {"Yellow", 255, 255, 0},
    {"Gold", 255, 215, 0},
    {"Orange", 255, 165, 0},
    {"Peach", 255, 218, 185},
    {"Apricot", 255, 215, 181},
    {"Salmon", 250, 128, 114},
    {"Coral", 255, 127, 80},
    {"Red", 255, 0, 0}
};

int main(void) {
    char color_name[COLOR_NAME_MAX_LENGTH];
    int i;

    printf("Enter a color name: ");
    scanf("%s", color_name);

    for (i = 0; i < sizeof(colors) / sizeof(Color); i++) {
        if (strcmp(color_name, colors[i].name) == 0) {
            printf("Red: %u\n", colors[i].red);
            printf("Green: %u\n", colors[i].green);
            printf("Blue: %u\n", colors[i].blue);
            break;
        }
    }

    if (i == sizeof(colors) / sizeof(Color)) {
        printf("Color not found.\n");
    }

    return 0;
}