//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LENGTH 32
#define MAX_COLOR_CODE_LENGTH 8
#define MAX_COLOR_VALUE_LENGTH 16

typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    char code[MAX_COLOR_CODE_LENGTH];
    char value[MAX_COLOR_VALUE_LENGTH];
} Color;

Color colors[3] = {
    {"red", "#FF0000", "255,0,0"},
    {"green", "#00FF00", "0,255,0"},
    {"blue", "#0000FF", "0,0,255"}
};

int main() {
    int num_colors = sizeof(colors) / sizeof(Color);
    char input_color_code[MAX_COLOR_CODE_LENGTH];
    int i;

    printf("Enter a color code (or type 'list' to see available colors):\n");
    scanf("%s", input_color_code);

    if (strcmp(input_color_code, "list") == 0) {
        for (i = 0; i < num_colors; i++) {
            printf("%s: %s (%s)\n", colors[i].name, colors[i].code, colors[i].value);
        }
    } else {
        int found_color = 0;

        for (i = 0; i < num_colors; i++) {
            if (strcmp(input_color_code, colors[i].code) == 0) {
                printf("%s: %s (%s)\n", colors[i].name, colors[i].code, colors[i].value);
                found_color = 1;
                break;
            }
        }

        if (!found_color) {
            printf("Invalid color code.\n");
        }
    }

    return 0;
}