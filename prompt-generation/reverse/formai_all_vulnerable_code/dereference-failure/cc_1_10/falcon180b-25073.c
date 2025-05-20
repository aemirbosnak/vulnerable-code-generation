//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LENGTH 50

typedef struct {
    char *name;
    int hex_value;
} Color;

Color *initialize_colors() {
    Color *colors = (Color *) malloc(sizeof(Color) * 256);
    int i;
    for (i = 0; i < 256; i++) {
        sprintf(colors[i].name, "#%02X%02X%02X", (i >> 16) & 0xFF, (i >> 8) & 0xFF, i & 0xFF);
        colors[i].hex_value = i;
    }
    return colors;
}

void print_colors(Color *colors) {
    int i;
    for (i = 0; i < 256; i++) {
        printf("%s (%d)\n", colors[i].name, colors[i].hex_value);
    }
}

Color *search_color(Color *colors, char *name) {
    int i;
    for (i = 0; i < 256; i++) {
        if (strcmp(colors[i].name, name) == 0) {
            return &colors[i];
        }
    }
    return NULL;
}

int main() {
    Color *colors = initialize_colors();
    char input[MAX_COLOR_NAME_LENGTH];
    while (1) {
        printf("Enter a color name or 'q' to quit: ");
        scanf("%s", input);
        if (strcmp(input, "q") == 0) {
            break;
        }
        Color *color = search_color(colors, input);
        if (color == NULL) {
            printf("Color not found.\n");
        } else {
            printf("Hex value: %06X\n", color->hex_value);
        }
    }
    free(colors);
    return 0;
}