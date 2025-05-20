//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 16

typedef struct {
    char *name;
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
    {"Gray", 128, 128, 128},
    {"DarkGray", 64, 64, 64},
    {"LightGray", 192, 192, 192},
    {"LightRed", 255, 128, 128},
    {"LightGreen", 128, 255, 128},
    {"LightBlue", 128, 128, 255},
    {"LightYellow", 255, 255, 128}
};

char *get_color_name(int color_code) {
    for (int i = 0; i < MAX_COLORS; i++) {
        if (colors[i].red == color_code) {
            return colors[i].name;
        }
    }
    return "Invalid color code";
}

int main() {
    char input[100];
    printf("Enter a color code: ");
    scanf("%s", input);

    int color_code = strtol(input, NULL, 16);
    if (color_code == 0) {
        printf("Invalid color code\n");
        return 1;
    }

    char *color_name = get_color_name(color_code);
    printf("Color name: %s\n", color_name);
    printf("RGB values: %d, %d, %d\n", colors[color_code].red, colors[color_code].green, colors[color_code].blue);

    return 0;
}