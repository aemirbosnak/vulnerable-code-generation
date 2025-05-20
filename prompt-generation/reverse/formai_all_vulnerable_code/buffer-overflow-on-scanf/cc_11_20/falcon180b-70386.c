//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 1000

struct Color {
    char name[20];
    int r, g, b;
};

int main() {
    int num_colors;
    struct Color colors[MAX_COLORS];
    char input[100];

    printf("Enter the number of colors you want to convert (up to %d): ", MAX_COLORS);
    scanf("%d", &num_colors);

    printf("Enter the colors in the format 'name:r,g,b' (e.g.'red:255,0,0'):\n");
    for (int i = 0; i < num_colors; i++) {
        scanf("%s", input);
        int j = 0;
        while (input[j]!= ':') {
            colors[i].name[j] = input[j];
            j++;
        }
        colors[i].name[j] = '\0';
        j++;
        colors[i].r = atoi(input+j);
        while (input[j]!= ',') {
            j++;
        }
        j++;
        colors[i].g = atoi(input+j);
        while (input[j]!= ',') {
            j++;
        }
        j++;
        colors[i].b = atoi(input+j);
    }

    printf("\nColor Code Converter\n");
    printf("Enter the color you want to convert: ");
    char color_name[20];
    scanf("%s", color_name);

    int color_index = -1;
    for (int i = 0; i < num_colors; i++) {
        if (strcmp(colors[i].name, color_name) == 0) {
            color_index = i;
            break;
        }
    }

    if (color_index == -1) {
        printf("Color not found.\n");
        return 1;
    }

    printf("Enter the format you want to convert to (RGB, RGBA, HEX, HEXA): ");
    char format[10];
    scanf("%s", format);

    switch (format[0]) {
        case 'R':
        case 'r':
            printf("RGB: %d, %d, %d\n", colors[color_index].r, colors[color_index].g, colors[color_index].b);
            break;
        case 'G':
        case 'g':
            printf("RGBA: %d, %d, %d, %d\n", colors[color_index].r, colors[color_index].g, colors[color_index].b, 255);
            break;
        case 'H':
        case 'h':
            printf("HEX: #%02X%02X%02X\n", colors[color_index].r, colors[color_index].g, colors[color_index].b);
            break;
        case 'A':
        case 'a':
            printf("HEXA: #%02X%02X%02X%02X\n", colors[color_index].r, colors[color_index].g, colors[color_index].b, 255);
            break;
        default:
            printf("Invalid format.\n");
            return 1;
    }

    return 0;
}