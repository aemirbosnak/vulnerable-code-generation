//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LENGTH 1000

struct color {
    char name[MAX_LENGTH];
    int hex;
    int rgb[3];
};

void print_colors(struct color colors[], int num_colors) {
    printf("Color Name\tHex Code\tRGB\n");
    for (int i = 0; i < num_colors; i++) {
        printf("%s\t%d\t{ %d, %d, %d }\n", colors[i].name, colors[i].hex, colors[i].rgb[0], colors[i].rgb[1], colors[i].rgb[2]);
    }
}

int main() {
    int num_colors;
    scanf("%d", &num_colors);

    struct color colors[num_colors];

    for (int i = 0; i < num_colors; i++) {
        scanf("%s", colors[i].name);
        colors[i].hex = 0;
        for (int j = 0; j < 3; j++) {
            scanf("%d", &colors[i].rgb[j]);
        }
    }

    for (int i = 0; i < num_colors; i++) {
        int r = colors[i].rgb[0];
        int g = colors[i].rgb[1];
        int b = colors[i].rgb[2];
        int max = r;
        if (g > max) {
            max = g;
        }
        if (b > max) {
            max = b;
        }
        int min = r;
        if (g < min) {
            min = g;
        }
        if (b < min) {
            min = b;
        }
        colors[i].hex = ((max * 65536) + (min * 256)) + (max * 16);
    }

    print_colors(colors, num_colors);

    return 0;
}