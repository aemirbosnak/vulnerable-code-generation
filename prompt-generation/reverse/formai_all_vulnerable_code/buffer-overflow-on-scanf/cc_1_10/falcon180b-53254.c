//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COLOR_NAMES 256

typedef struct {
    char *name;
    char *hex;
} Color;

Color colors[MAX_COLOR_NAMES];
int num_colors;

void add_color(char *name, char *hex) {
    Color color = {name, hex};
    colors[num_colors++] = color;
}

int main() {
    add_color("red", "#FF0000");
    add_color("blue", "#0000FF");
    add_color("green", "#00FF00");
    add_color("yellow", "#FFFF00");
    add_color("orange", "#FFA500");
    add_color("purple", "#800080");
    add_color("cyan", "#00FFFF");
    add_color("grey", "#808080");
    add_color("white", "#FFFFFF");
    add_color("black", "#000000");
    num_colors = 10;

    char input[100];
    while (1) {
        printf("Enter a color name or hex code: ");
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) {
            break;
        }

        Color *color = NULL;
        for (int i = 0; i < num_colors; i++) {
            if (strcmp(input, colors[i].name) == 0) {
                color = &colors[i];
                break;
            }
        }

        if (color == NULL) {
            printf("Invalid color.\n");
            continue;
        }

        printf("Name: %s\n", color->name);
        printf("Hex code: %s\n", color->hex);
        printf("\n");
    }

    return 0;
}