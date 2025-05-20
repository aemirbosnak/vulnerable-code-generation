//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLORS 16
#define MAX_COLORS_PER_LINE 8

typedef struct {
    char name[20];
    char hex[9];
    int r;
    int g;
    int b;
} color_t;

color_t colors[MAX_COLORS] = {
    {"black", "#000000", 0, 0, 0},
    {"white", "#FFFFFF", 255, 255, 255},
    {"red", "#FF0000", 255, 0, 0},
    {"green", "#00FF00", 0, 255, 0},
    {"blue", "#0000FF", 0, 0, 255},
    {"cyan", "#00FFFF", 0, 255, 255},
    {"magenta", "#FF00FF", 255, 0, 255},
    {"yellow", "#FFFF00", 255, 255, 0},
    {"gray", "#808080", 128, 128, 128},
    {"darkred", "#8B0000", 139, 0, 0},
    {"darkgreen", "#006400", 0, 100, 0},
    {"darkblue", "#00008B", 0, 0, 139},
    {"darkcyan", "#008B8B", 0, 139, 139},
    {"darkmagenta", "#8B008B", 139, 0, 139},
    {"darkyellow", "#8B8B00", 139, 139, 0},
    {"darkgray", "#A9A9A9", 169, 169, 169}
};

void print_color(color_t c) {
    printf("%s (%s, %d, %d, %d)\n", c.name, c.hex, c.r, c.g, c.b);
}

void print_colors(int num_colors) {
    int i;
    for (i = 0; i < num_colors && i < MAX_COLORS; i++) {
        print_color(colors[i]);
    }
}

int main() {
    int num_colors = 0;
    while (num_colors < MAX_COLORS) {
        char input[80];
        printf("Enter a color name or press Enter to finish: ");
        scanf("%s", input);
        if (strcmp(input, "") == 0) {
            break;
        }
        int i;
        for (i = 0; i < MAX_COLORS; i++) {
            if (strcmp(input, colors[i].name) == 0) {
                print_color(colors[i]);
                num_colors++;
                break;
            }
        }
        if (i == MAX_COLORS) {
            printf("Color not found.\n");
        }
    }
    print_colors(num_colors);
    return 0;
}