//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define MAX_COLOR_NAMES 16

typedef struct {
    char name[MAX_COLOR_NAMES];
    char hex[8];
} Color;

Color colors[MAX_COLOR_NAMES] = {
    {"black", "#000000"},
    {"white", "#FFFFFF"},
    {"red", "#FF0000"},
    {"green", "#00FF00"},
    {"blue", "#0000FF"},
    {"yellow", "#FFFF00"},
    {"cyan", "#00FFFF"},
    {"magenta", "#FF00FF"},
    {"gray", "#808080"},
    {"darkgray", "#A9A9A9"},
    {"lightgray", "#D3D3D3"},
    {"orange", "#FFA500"},
    {"pink", "#FFC0CB"},
    {"purple", "#800080"},
    {"brown", "#A52A2A"}
};

int main(int argc, char *argv[]) {
    char line[MAX_LINE_LENGTH];
    char *color_name;
    Color *color;
    int i;

    if (argc < 2) {
        printf("Usage: %s <color_name>\n", argv[0]);
        return 1;
    }

    color_name = argv[1];
    color = NULL;

    for (i = 0; i < MAX_COLOR_NAMES; i++) {
        if (strcmp(colors[i].name, color_name) == 0) {
            color = &colors[i];
            break;
        }
    }

    if (color == NULL) {
        printf("Invalid color name: %s\n", color_name);
        return 1;
    }

    printf("Color code for %s:\n", color_name);
    printf("RGB: %s\n", color->hex);

    return 0;
}