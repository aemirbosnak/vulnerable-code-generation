//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 16

typedef struct {
    char *name;
    int value;
} Color;

Color colors[MAX_COLORS] = {
    {"black", 0},
    {"red", 1},
    {"green", 2},
    {"yellow", 3},
    {"blue", 4},
    {"magenta", 5},
    {"cyan", 6},
    {"white", 7},
    {"gray", 8},
    {"light_red", 9},
    {"light_green", 10},
    {"light_yellow", 11},
    {"light_blue", 12},
    {"light_magenta", 13},
    {"light_cyan", 14},
    {"light_white", 15}
};

int get_color_value(char *color_name) {
    int i;
    for (i = 0; i < MAX_COLORS; i++) {
        if (strcmp(color_name, colors[i].name) == 0) {
            return colors[i].value;
        }
    }
    return -1;
}

void print_color_table() {
    printf("Color Name\tValue\n");
    printf("--------------------\n");
    int i;
    for (i = 0; i < MAX_COLORS; i++) {
        printf("%-15s\t%d\n", colors[i].name, colors[i].value);
    }
}

int main() {
    char color_name[20];
    int color_value;

    printf("Welcome to the Color Code Converter!\n");
    printf("Please enter a color name (e.g. red, green, blue): ");
    scanf("%s", color_name);

    color_value = get_color_value(color_name);

    if (color_value == -1) {
        printf("Invalid color name. Please try again.\n");
    } else {
        printf("The color code for %s is %d.\n", color_name, color_value);
    }

    return 0;
}