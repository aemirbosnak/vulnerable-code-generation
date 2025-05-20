//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LENGTH 64

struct Color {
    char name[MAX_COLOR_NAME_LENGTH];
    int red;
    int green;
    int blue;
};

int main() {
    struct Color colors[] = {
        {"red", 255, 0, 0},
        {"green", 0, 255, 0},
        {"blue", 0, 0, 255},
        {"yellow", 255, 255, 0},
        {"magenta", 255, 0, 255},
        {"cyan", 0, 255, 255},
        {"white", 255, 255, 255},
        {"black", 0, 0, 0}
    };

    int num_colors = sizeof(colors) / sizeof(struct Color);

    char input_color[MAX_COLOR_NAME_LENGTH];
    printf("Enter a color name: ");
    scanf("%s", input_color);

    struct Color *selected_color = NULL;
    for (int i = 0; i < num_colors; i++) {
        if (strcmp(colors[i].name, input_color) == 0) {
            selected_color = &colors[i];
            break;
        }
    }

    if (selected_color == NULL) {
        printf("Invalid color name\n");
        return 1;
    }

    printf("Selected color: %s\n", selected_color->name);
    printf("RGB values: (%d, %d, %d)\n", selected_color->red, selected_color->green, selected_color->blue);
    printf("Hexadecimal value: #%06X\n", selected_color->red * 65536 + selected_color->green * 256 + selected_color->blue);

    return 0;
}