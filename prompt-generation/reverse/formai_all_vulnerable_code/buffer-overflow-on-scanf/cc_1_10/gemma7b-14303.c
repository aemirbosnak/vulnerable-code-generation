//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>

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
    {"Pink", 255, 165, 255},
    {"Gray", 128, 128, 128},
    {"Black", 0, 0, 0},
    {"White", 255, 255, 255}
};

int main() {
    int color_index;
    char color_name[20];

    printf("Enter the name of the color: ");
    scanf("%s", color_name);

    color_index = find_color(color_name);

    if (color_index != -1) {
        printf("The color index is: %d", color_index);
    } else {
        printf("The color name is not found.");
    }

    return 0;
}

int find_color(char *color_name) {
    int i;

    for (i = 0; i < MAX_COLORS; i++) {
        if (strcmp(colors[i].name, color_name) == 0) {
            return i;
        }
    }

    return -1;
}