//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LENGTH 20
#define MAX_COLOR_CODE_LENGTH 8

typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    char code[MAX_COLOR_CODE_LENGTH];
} Color;

Color colors[] = {
    {"white", "0"},
    {"black", "1"},
    {"red", "2"},
    {"green", "3"},
    {"yellow", "4"},
    {"blue", "5"},
    {"magenta", "6"},
    {"cyan", "7"},
    {"gray", "8"},
    {"light_red", "9"},
    {"light_green", "10"},
    {"light_yellow", "11"},
    {"light_blue", "12"},
    {"light_magenta", "13"},
    {"light_cyan", "14"},
    {"light_gray", "15"}
};

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <color_name> <color_code>\n", argv[0]);
        return 1;
    }

    char *color_name = argv[1];
    char *color_code = argv[2];

    Color *color = NULL;
    for (int i = 0; i < sizeof(colors)/sizeof(Color); i++) {
        if (strcmp(color_name, colors[i].name) == 0) {
            color = &colors[i];
            break;
        }
    }

    if (color == NULL) {
        printf("Invalid color name\n");
        return 1;
    }

    if (strcmp(color_code, color->code)!= 0) {
        printf("Invalid color code\n");
        return 1;
    }

    printf("Color name: %s\n", color_name);
    printf("Color code: %s\n", color_code);

    return 0;
}