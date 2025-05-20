//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 16

typedef struct {
    char name[20];
    int value;
} Color;

Color colors[MAX_COLORS] = {
    {"black", 0},
    {"white", 7},
    {"red", 1},
    {"green", 2},
    {"yellow", 3},
    {"blue", 4},
    {"magenta", 5},
    {"cyan", 6},
    {"gray", 8},
    {"light_red", 9},
    {"light_green", 10},
    {"light_yellow", 11},
    {"light_blue", 12},
    {"light_magenta", 13},
    {"light_cyan", 14},
    {"light_gray", 15}
};

int main() {
    char input[50];
    int i, count = 0;

    printf("Enter a color code (e.g. #FF0000): ");
    scanf("%s", input);

    if (strlen(input)!= 7 || input[0]!= '#') {
        printf("Invalid color code.\n");
        return 1;
    }

    for (i = 1; i < strlen(input); i++) {
        if (!isxdigit(input[i])) {
            printf("Invalid color code.\n");
            return 1;
        }
    }

    int red = strtol(input + 1, NULL, 16);
    int green = strtol(input + 3, NULL, 16);
    int blue = strtol(input + 5, NULL, 16);

    int value = (red << 16) | (green << 8) | blue;

    printf("Color code: #%06X\n", value);

    for (i = 0; i < MAX_COLORS; i++) {
        if (colors[i].value == value) {
            printf("Color name: %s\n", colors[i].name);
            count++;
            break;
        }
    }

    if (!count) {
        printf("No matching color found.\n");
    }

    return 0;
}