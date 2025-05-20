//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 256

struct color {
    char name[20];
    int red;
    int green;
    int blue;
};

int main() {
    struct color colors[MAX_COLORS];
    int num_colors = 0;

    printf("Enter color names and their RGB values (in the format name:red:green:blue):\n");
    while (num_colors < MAX_COLORS && scanf(" %19s:%d:%d:%d", colors[num_colors].name, &colors[num_colors].red, &colors[num_colors].green, &colors[num_colors].blue) == 4) {
        num_colors++;
    }

    printf("\nEnter a color name to convert:\n");
    scanf(" %s", colors[0].name);

    int red, green, blue;
    if (strcmp(colors[0].name, "red") == 0) {
        red = 255;
        green = 0;
        blue = 0;
    } else if (strcmp(colors[0].name, "green") == 0) {
        red = 0;
        green = 255;
        blue = 0;
    } else if (strcmp(colors[0].name, "blue") == 0) {
        red = 0;
        green = 0;
        blue = 255;
    } else {
        for (int i = 0; i < num_colors; i++) {
            if (strcmp(colors[i].name, colors[0].name) == 0) {
                red = colors[i].red;
                green = colors[i].green;
                blue = colors[i].blue;
                break;
            }
        }
    }

    printf("\nRGB values for %s:\n", colors[0].name);
    printf("Red: %d\nGreen: %d\nBlue: %d\n", red, green, blue);

    return 0;
}