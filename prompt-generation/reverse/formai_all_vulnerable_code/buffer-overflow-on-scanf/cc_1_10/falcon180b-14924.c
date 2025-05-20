//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CODE_LENGTH 7
#define HEX_DIGITS "0123456789ABCDEF"

typedef struct {
    char *name;
    int value;
} ColorCode;

ColorCode color_codes[] = {
    {"Black", 0},
    {"Maroon", 1},
    {"Green", 2},
    {"Olive", 3},
    {"Navy", 4},
    {"Purple", 5},
    {"Teal", 6},
    {"Silver", 7},
    {"Gray", 8},
    {"Red", 9},
    {"Lime", 10},
    {"Yellow", 11},
    {"Blue", 12},
    {"Fuchsia", 13},
    {"Aqua", 14},
    {"White", 15}
};

int main() {
    int i, j;
    char input[MAX_CODE_LENGTH];
    ColorCode *result;

    printf("Enter a color code (RGB or name): ");
    scanf("%s", input);

    if (strlen(input) == 6 && input[0] == '#') {
        // Convert RGB code to name
        int r = input[1] - '0';
        int g = input[2] - '0';
        int b = input[3] - '0';

        int value = (r << 10) | (g << 5) | b;

        for (i = 0; i < sizeof(color_codes)/sizeof(ColorCode); i++) {
            if (color_codes[i].value == value) {
                printf("Color name: %s\n", color_codes[i].name);
                return 0;
            }
        }
    } else if (strlen(input) > 0 && input[0]!= '#') {
        // Convert name to RGB code
        for (i = 0; i < sizeof(color_codes)/sizeof(ColorCode); i++) {
            if (strcmp(input, color_codes[i].name) == 0) {
                printf("RGB code: #%06X\n", color_codes[i].value);
                return 0;
            }
        }
    } else {
        printf("Invalid input.\n");
        return 1;
    }

    return 0;
}