//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 16

typedef struct {
    char name[8];
    int value;
} Color;

Color colors[MAX_COLORS] = {
    {"BLACK", 0},
    {"RED", 1},
    {"GREEN", 2},
    {"YELLOW", 3},
    {"BLUE", 4},
    {"MAGENTA", 5},
    {"CYAN", 6},
    {"WHITE", 7},
    {"GRAY", 8},
    {"LIGHT_RED", 9},
    {"LIGHT_GREEN", 10},
    {"LIGHT_YELLOW", 11},
    {"LIGHT_BLUE", 12},
    {"LIGHT_MAGENTA", 13},
    {"LIGHT_CYAN", 14},
    {"LIGHT_WHITE", 15}
};

int main() {
    char input[256];
    Color *color;

    printf("Enter a color name or value (0-15): ");
    fgets(input, sizeof(input), stdin);

    if (sscanf(input, "%d", &color->value)!= 1) {
        for (int i = 0; i < MAX_COLORS; i++) {
            if (strcmp(colors[i].name, input) == 0) {
                color = &colors[i];
                break;
            }
        }
    }

    printf("RGB value: %d, %d, %d\n", (color->value >> 16) & 0xFF, (color->value >> 8) & 0xFF, color->value & 0xFF);

    return 0;
}