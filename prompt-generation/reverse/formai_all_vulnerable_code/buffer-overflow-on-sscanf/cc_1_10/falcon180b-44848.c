//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

typedef struct {
    char *name;
    int value;
} Color;

Color colors[] = {
    {"black", 0},
    {"white", 1},
    {"red", 2},
    {"green", 3},
    {"blue", 4},
    {"yellow", 5},
    {"magenta", 6},
    {"cyan", 7},
    {"gray", 8},
    {"darkgray", 9},
    {"lightgray", 10},
    {"lightred", 11},
    {"lightgreen", 12},
    {"lightblue", 13},
    {"lightyellow", 14},
    {"lightmagenta", 15},
    {"lightcyan", 16},
    {"white", 17}
};

int main() {
    char line[MAX_LINE_LENGTH];
    char color_name[MAX_LINE_LENGTH];
    int color_value = 0;

    printf("Enter a color name: ");
    fgets(line, MAX_LINE_LENGTH, stdin);

    // Remove newline character
    line[strcspn(line, "\n")] = '\0';

    sscanf(line, "%s", color_name);

    // Search for color in list
    for (int i = 0; i < sizeof(colors) / sizeof(Color); i++) {
        if (strcmp(color_name, colors[i].name) == 0) {
            color_value = colors[i].value;
            break;
        }
    }

    printf("The color code for %s is: %d\n", color_name, color_value);

    return 0;
}