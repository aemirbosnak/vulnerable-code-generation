//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_COLORS 16

typedef struct {
    char name[10];
    int value;
} Color;

Color colors[MAX_COLORS] = {
    {"BLACK", 0},
    {"WHITE", 7},
    {"RED", 1},
    {"YELLOW", 2},
    {"BLUE", 4},
    {"GREEN", 2},
    {"CYAN", 6},
    {"MAGENTA", 5},
    {"DARK_GRAY", 8},
    {"LIGHT_GRAY", 7},
    {"LIGHT_RED", 9},
    {"LIGHT_YELLOW", 11},
    {"LIGHT_BLUE", 12},
    {"LIGHT_GREEN", 10},
    {"LIGHT_CYAN", 14},
    {"LIGHT_MAGENTA", 13}
};

int main() {
    char input_color[20];
    char output_color[20];
    int input_color_value;
    int output_color_value;

    printf("Enter the input color (e.g. RED): ");
    scanf("%s", input_color);

    printf("Enter the output color format (e.g. RGB): ");
    scanf("%s", output_color);

    for (int i = 0; i < MAX_COLORS; i++) {
        if (strcmp(input_color, colors[i].name) == 0) {
            input_color_value = colors[i].value;
            break;
        }
    }

    if (strcmp(output_color, "RGB") == 0) {
        output_color_value = (input_color_value >> 4) & 0x0F;
        output_color_value += (input_color_value & 0x0F) << 4;
        printf("The %s color in RGB format is %d\n", input_color, output_color_value);
    } else if (strcmp(output_color, "HEX") == 0) {
        printf("The %s color in HEX format is %X\n", input_color, input_color_value);
    } else {
        printf("Invalid output color format\n");
    }

    return 0;
}