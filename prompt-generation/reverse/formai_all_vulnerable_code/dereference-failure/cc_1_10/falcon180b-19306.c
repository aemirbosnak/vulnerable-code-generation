//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 10000

typedef struct {
    char *name;
    int value;
} color_t;

color_t colors[] = {
    {"black", 0},
    {"white", 1},
    {"red", 2},
    {"green", 3},
    {"blue", 4},
    {"yellow", 5},
    {"cyan", 6},
    {"magenta", 7},
    {"gray", 8},
    {"light_red", 9},
    {"light_green", 10},
    {"light_blue", 11},
    {"light_yellow", 12},
    {"light_cyan", 13},
    {"light_magenta", 14},
    {"orange", 15},
    {NULL, -1}
};

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("Usage: %s <color_name>\n", argv[0]);
        return 1;
    }

    char *color_name = argv[1];
    int i = 0;
    while (colors[i].name!= NULL) {
        if (strcmp(color_name, colors[i].name) == 0) {
            printf("Color code for %s: %d\n", color_name, colors[i].value);
            return 0;
        }
        i++;
    }

    printf("Invalid color name: %s\n", color_name);
    return 1;
}