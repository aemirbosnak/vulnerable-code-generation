//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 6

struct color {
    char name[20];
    int rgb[3];
};

struct color colors[MAX_COLORS] = {
    {"red", {255, 0, 0}},
    {"green", {0, 255, 0}},
    {"blue", {0, 0, 255}},
    {"yellow", {255, 255, 0}},
    {"cyan", {0, 255, 255}},
    {"magenta", {255, 0, 255}}
};

int get_color_index(char *name) {
    for (int i = 0; i < MAX_COLORS; i++) {
        if (strcmp(colors[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void print_colors() {
    printf("Available colors:\n");
    for (int i = 0; i < MAX_COLORS; i++) {
        printf("%s\n", colors[i].name);
    }
}

int main() {
    char input[100];
    int color_index;

    printf("Enter a color name: ");
    scanf("%s", input);

    color_index = get_color_index(input);

    if (color_index == -1) {
        printf("Invalid color name\n");
    } else {
        printf("RGB values for %s:\n", colors[color_index].name);
        printf("R: %d\n", colors[color_index].rgb[0]);
        printf("G: %d\n", colors[color_index].rgb[1]);
        printf("B: %d\n", colors[color_index].rgb[2]);
    }

    return 0;
}