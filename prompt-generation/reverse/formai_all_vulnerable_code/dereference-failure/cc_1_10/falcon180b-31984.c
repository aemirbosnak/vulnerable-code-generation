//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LENGTH 64
#define MAX_COLOR_CODE_LENGTH 8

typedef struct {
    char *name;
    char code[MAX_COLOR_CODE_LENGTH];
} Color;

Color *load_colors() {
    Color *colors = (Color *) malloc(sizeof(Color) * 3);
    colors[0].name = "red";
    strcpy(colors[0].code, "#FF0000");
    colors[1].name = "green";
    strcpy(colors[1].code, "#00FF00");
    colors[2].name = "blue";
    strcpy(colors[2].code, "#0000FF");
    return colors;
}

void print_colors(Color *colors) {
    int i;
    for (i = 0; i < 3; i++) {
        printf("%s - %s\n", colors[i].name, colors[i].code);
    }
}

Color *search_color(Color *colors, char *name) {
    int i;
    for (i = 0; i < 3; i++) {
        if (strcmp(colors[i].name, name) == 0) {
            return &colors[i];
        }
    }
    return NULL;
}

int main() {
    Color *colors = load_colors();
    print_colors(colors);

    char color_name[MAX_COLOR_NAME_LENGTH];
    printf("Enter a color name: ");
    scanf("%s", color_name);

    Color *selected_color = search_color(colors, color_name);

    if (selected_color!= NULL) {
        printf("The code for %s is: %s\n", selected_color->name, selected_color->code);
    } else {
        printf("Color not found.\n");
    }

    free(colors);
    return 0;
}