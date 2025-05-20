//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LENGTH 20
#define MAX_COLOR_CODE_LENGTH 7

typedef struct {
    char *name;
    char code[MAX_COLOR_CODE_LENGTH];
} Color;

Color colors[] = {
    {"Black", "\033[30m"},
    {"Red", "\033[31m"},
    {"Green", "\033[32m"},
    {"Yellow", "\033[33m"},
    {"Blue", "\033[34m"},
    {"Magenta", "\033[35m"},
    {"Cyan", "\033[36m"},
    {"White", "\033[37m"},
    {"Reset", "\033[0m"}
};

int num_colors = sizeof(colors) / sizeof(Color);

void print_color(Color color) {
    printf("%s%s", color.code, "Hello, World!");
}

int main() {
    char color_name[MAX_COLOR_NAME_LENGTH];

    printf("Enter a color name: ");
    scanf("%s", color_name);

    Color *color = NULL;
    for (int i = 0; i < num_colors; i++) {
        if (strcmp(color_name, colors[i].name) == 0) {
            color = &colors[i];
            break;
        }
    }

    if (color == NULL) {
        printf("Invalid color name\n");
        return 1;
    }

    print_color(*color);

    return 0;
}