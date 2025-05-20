//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: peaceful
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
    char input[100];
    int i, j;

    printf("Enter a color name or value: ");
    scanf("%s", input);

    i = strtol(input, NULL, 10);
    if (i >= 0 && i <= 15) {
        printf("Color name: %s\n", colors[i].name);
        printf("Color value: %d\n", colors[i].value);
    } else {
        for (j = 0; j < MAX_COLORS; j++) {
            if (strcmp(input, colors[j].name) == 0) {
                printf("Color value: %d\n", colors[j].value);
                break;
            }
        }
    }

    return 0;
}