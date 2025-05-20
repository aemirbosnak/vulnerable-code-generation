//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 16

typedef struct {
    char name[10];
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

int getColorValue(char *color) {
    int i;
    for(i=0; i<MAX_COLORS; i++) {
        if(strcmp(color, colors[i].name) == 0) {
            return colors[i].value;
        }
    }
    return -1; // color not found
}

int main() {
    char input[100];
    int value;

    printf("Enter a color name: ");
    scanf("%s", input);

    value = getColorValue(input);

    if(value == -1) {
        printf("Color not found.\n");
    } else {
        printf("Color value: %d\n", value);
    }

    return 0;
}