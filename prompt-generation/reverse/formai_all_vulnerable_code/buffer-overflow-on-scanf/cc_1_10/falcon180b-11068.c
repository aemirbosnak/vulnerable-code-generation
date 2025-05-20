//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 16
#define MAX_COLOR_NAME_LENGTH 20

// Define color names and their corresponding values
struct color {
    char name[MAX_COLOR_NAME_LENGTH];
    int value;
};

struct color colors[MAX_COLORS] = {
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

int main() {
    char color_name[MAX_COLOR_NAME_LENGTH];
    int color_value;

    // Get the color name from user input
    printf("Enter a color name: ");
    scanf("%s", color_name);

    // Search for the color name in the color table
    for (int i = 0; i < MAX_COLORS; i++) {
        if (strcmp(color_name, colors[i].name) == 0) {
            color_value = colors[i].value;
            break;
        }
    }

    // Print the color value in hexadecimal format
    printf("The color value for \"%s\" is #%02x\n", color_name, color_value);

    return 0;
}