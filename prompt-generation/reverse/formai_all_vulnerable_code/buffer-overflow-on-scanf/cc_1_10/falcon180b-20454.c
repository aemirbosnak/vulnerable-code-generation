//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: real-life
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
    int choice;
    char input[100];

    printf("Welcome to the Color Code Converter!\n");
    printf("Please enter a color code (e.g. #FF0000 for red): ");
    scanf("%s", input);

    if (strlen(input) == 7 && input[0] == '#') {
        int r, g, b;
        sscanf(input, "#%02X%02X%02X", &r, &g, &b);
        printf("The color code %s corresponds to the color ", input);
        for (choice = 0; choice < MAX_COLORS; choice++) {
            if (colors[choice].value == (r << 16) | (g << 8) | b) {
                printf("%s.\n", colors[choice].name);
                break;
            }
        }
    } else {
        printf("Invalid color code.\n");
    }

    return 0;
}