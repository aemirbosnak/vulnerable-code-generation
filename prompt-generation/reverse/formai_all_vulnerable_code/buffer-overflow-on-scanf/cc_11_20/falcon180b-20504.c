//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 16

typedef struct {
    char name[7];
    int value;
} Color;

Color colors[MAX_COLORS] = {
    {"black", 0},
    {"white", 7},
    {"red", 1},
    {"green", 2},
    {"blue", 4},
    {"yellow", 6},
    {"magenta", 5},
    {"cyan", 3},
    {"gray", 8},
    {"darkgray", 8},
    {"lightred", 9},
    {"lightgreen", 10},
    {"lightblue", 12},
    {"lightyellow", 14},
    {"lightmagenta", 13},
    {"lightcyan", 11}
};

int main() {
    char input[100];
    int color_index = -1;

    printf("Enter a color name (or hex value): ");
    scanf("%s", input);

    // Check if input is a valid color name
    for (int i = 0; i < MAX_COLORS; i++) {
        if (strcmp(input, colors[i].name) == 0) {
            color_index = i;
            break;
        }
    }

    // If input is not a valid color name, check if it's a hex value
    if (color_index == -1) {
        if (strlen(input) == 7 && input[0] == '#') {
            int value = 0;
            for (int i = 1; i < 7; i++) {
                if (input[i] >= '0' && input[i] <= '9') {
                    value = value * 16 + input[i] - '0';
                } else if (input[i] >= 'A' && input[i] <= 'F') {
                    value = value * 16 + input[i] - 'A' + 10;
                } else {
                    printf("Invalid hex value\n");
                    return 1;
                }
            }
            for (int i = 0; i < MAX_COLORS; i++) {
                if (colors[i].value == value) {
                    color_index = i;
                    break;
                }
            }
        } else {
            printf("Invalid input\n");
            return 1;
        }
    }

    if (color_index == -1) {
        printf("Invalid color\n");
        return 1;
    }

    printf("Color code: %s\n", colors[color_index].name);
    printf("Color value: %d\n", colors[color_index].value);

    return 0;
}