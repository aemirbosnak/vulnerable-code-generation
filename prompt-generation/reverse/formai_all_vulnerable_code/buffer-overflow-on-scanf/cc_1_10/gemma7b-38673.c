//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 10

typedef struct Color {
    char name[20];
    int red;
    int green;
    int blue;
} Color;

Color colors[MAX_COLORS] = {
    {"Red", 255, 0, 0},
    {"Green", 0, 255, 0},
    {"Blue", 0, 0, 255},
    {"Yellow", 255, 255, 0},
    {"Orange", 255, 165, 0},
    {"Purple", 165, 0, 255},
    {"Pink", 255, 192, 203},
    {"Gray", 128, 128, 128},
    {"Black", 0, 0, 0},
    {"White", 255, 255, 255}
};

int main() {
    char color_name[20];
    int red, green, blue;

    printf("Enter the name of a color: ");
    scanf("%s", color_name);

    for (int i = 0; i < MAX_COLORS; i++) {
        if (strcmp(colors[i].name, color_name) == 0) {
            red = colors[i].red;
            green = colors[i].green;
            blue = colors[i].blue;
            break;
        }
    }

    if (red == -1) {
        printf("Error: Color not found.\n");
    } else {
        printf("Red: %d\n", red);
        printf("Green: %d\n", green);
        printf("Blue: %d\n", blue);
    }

    return 0;
}