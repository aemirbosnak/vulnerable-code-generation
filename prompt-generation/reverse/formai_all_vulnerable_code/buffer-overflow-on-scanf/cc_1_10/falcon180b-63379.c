//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 256

typedef struct {
    char name[20];
    int rgb[3];
} Color;

Color colors[MAX_COLORS];
int num_colors = 0;

void add_color(char *name, int r, int g, int b) {
    if (num_colors >= MAX_COLORS) {
        printf("Error: Too many colors defined.\n");
        exit(1);
    }

    strcpy(colors[num_colors].name, name);
    colors[num_colors].rgb[0] = r;
    colors[num_colors].rgb[1] = g;
    colors[num_colors].rgb[2] = b;

    num_colors++;
}

int main() {
    // Define some colors
    add_color("red", 255, 0, 0);
    add_color("green", 0, 255, 0);
    add_color("blue", 0, 0, 255);

    // Convert a color name to RGB values
    char color_name[20];
    printf("Enter a color name: ");
    scanf("%s", color_name);

    Color *color = NULL;
    for (int i = 0; i < num_colors; i++) {
        if (strcmp(colors[i].name, color_name) == 0) {
            color = &colors[i];
            break;
        }
    }

    if (color == NULL) {
        printf("Error: Color not found.\n");
        exit(1);
    }

    printf("RGB values for %s: %d, %d, %d\n", color->name, color->rgb[0], color->rgb[1], color->rgb[2]);

    return 0;
}