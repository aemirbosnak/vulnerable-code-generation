//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 7
#define COLOR_NAMES_COUNT 16

typedef struct {
    char *name;
    char code[MAX_CODE_LENGTH];
} Color;

Color colors[COLOR_NAMES_COUNT] = {
    {"Black", "#000000"},
    {"White", "#FFFFFF"},
    {"Red", "#FF0000"},
    {"Green", "#00FF00"},
    {"Blue", "#0000FF"},
    {"Yellow", "#FFFF00"},
    {"Cyan", "#00FFFF"},
    {"Magenta", "#FF00FF"},
    {"Silver", "#C0C0C0"},
    {"Gray", "#808080"},
    {"Maroon", "#800000"},
    {"Olive", "#808000"},
    {"Lime", "#00FF00"},
    {"Aqua", "#00FFFF"},
    {"Teal", "#008080"},
    {"Navy", "#000080"}
};

int main() {
    char input[100];
    int i, j, input_length, code_length;
    Color *selected_color;

    printf("Enter a color name or code: ");
    scanf("%s", input);
    input_length = strlen(input);

    for (i = 0; i < COLOR_NAMES_COUNT; i++) {
        if (strcasecmp(input, colors[i].name) == 0) {
            printf("Code for %s: %s\n", input, colors[i].code);
            return 0;
        }
    }

    for (i = 0; i < COLOR_NAMES_COUNT; i++) {
        if (input_length == strlen(colors[i].code) && strcasecmp(input, colors[i].code) == 0) {
            printf("Name for %s: %s\n", input, colors[i].name);
            return 0;
        }
    }

    printf("Invalid color name or code.\n");
    return 1;
}