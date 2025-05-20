//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: light-weight
#include <stdio.h>
#include <string.h>

#define COLOR_COUNT 16

const char *colors[COLOR_COUNT] = {
    "Black",
    "Red",
    "Green",
    "Yellow",
    "Blue",
    "Magenta",
    "Cyan",
    "White",
    "Gray",
    "Bright Red",
    "Bright Green",
    "Bright Yellow",
    "Bright Blue",
    "Bright Magenta",
    "Bright Cyan",
    "Bright White"
};

const int color_codes[COLOR_COUNT] = {
    0,
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9,
    10,
    11,
    12,
    13,
    14,
    15
};

int main() {
    char input[10];
    int color_code;

    printf("Enter a color code: ");
    scanf("%s", input);

    color_code = atoi(input);

    if (color_code < 0 || color_code >= COLOR_COUNT) {
        printf("Invalid color code.\n");
        return 1;
    }

    printf("The color is %s.\n", colors[color_code]);

    return 0;
}