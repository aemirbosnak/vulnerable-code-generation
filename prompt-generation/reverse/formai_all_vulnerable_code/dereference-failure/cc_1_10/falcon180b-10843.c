//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 16

typedef struct {
    char name[32];
    int red;
    int green;
    int blue;
} Color;

Color colors[MAX_COLORS] = {
    {"Black", 0, 0, 0},
    {"White", 255, 255, 255},
    {"Red", 255, 0, 0},
    {"Green", 0, 255, 0},
    {"Blue", 0, 0, 255},
    {"Yellow", 255, 255, 0},
    {"Cyan", 0, 255, 255},
    {"Magenta", 255, 0, 255},
    {"Orange", 255, 128, 0},
    {"Pink", 255, 192, 203},
    {"Gray", 128, 128, 128},
    {"LightGray", 192, 192, 192},
    {"DarkGray", 64, 64, 64},
    {"LightBlue", 173, 216, 230},
    {"LightGreen", 144, 238, 144},
    {"LightYellow", 255, 255, 224}
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <color_name>\n", argv[0]);
        return 1;
    }

    Color *color = NULL;
    for (int i = 0; i < MAX_COLORS; i++) {
        if (strcmp(colors[i].name, argv[1]) == 0) {
            color = &colors[i];
            break;
        }
    }

    if (color == NULL) {
        printf("Invalid color name.\n");
        return 1;
    }

    printf("Name: %s\n", color->name);
    printf("RGB: %d, %d, %d\n", color->red, color->green, color->blue);
    printf("Hex: #%02X%02X%02X\n", color->red, color->green, color->blue);
    printf("HSL: %d, %d, %d\n", color->red / 255.0, color->green / 255.0, color->blue / 255.0);

    return 0;
}