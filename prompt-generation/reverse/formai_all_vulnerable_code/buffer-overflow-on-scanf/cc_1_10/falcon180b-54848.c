//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_COLORS 1000

typedef struct {
    char name[20];
    int red;
    int green;
    int blue;
} Color;

Color colors[MAX_COLORS] = {
    {"Black", 0, 0, 0},
    {"White", 255, 255, 255},
    {"Red", 255, 0, 0},
    {"Green", 0, 255, 0},
    {"Blue", 0, 0, 255},
    {"Yellow", 255, 255, 0},
    {"Cyan", 0, 255, 255},
    {"Magenta", 255, 0, 255},
    {"Gray", 128, 128, 128},
    {"LightGray", 192, 192, 192}
};

int main() {
    int num_colors = 10;
    int i, j;
    char color_name[20];
    int red, green, blue;
    int closest_distance = 1000;
    int closest_index = -1;

    printf("Enter the name of the color you want to convert: ");
    scanf("%s", color_name);

    // Find the color in the color table
    for (i = 0; i < num_colors; i++) {
        if (strcmp(color_name, colors[i].name) == 0) {
            printf("The RGB values for %s are: %d, %d, %d\n", color_name, colors[i].red, colors[i].green, colors[i].blue);
            return 0;
        }
    }

    // Color not found, try to find the closest match
    for (i = 0; i < num_colors; i++) {
        red = abs(colors[i].red - 128);
        green = abs(colors[i].green - 128);
        blue = abs(colors[i].blue - 128);
        if (red + green + blue < closest_distance) {
            closest_distance = red + green + blue;
            closest_index = i;
        }
    }

    printf("The closest match for %s is: %s\n", color_name, colors[closest_index].name);
    printf("The RGB values for %s are: %d, %d, %d\n", colors[closest_index].name, colors[closest_index].red, colors[closest_index].green, colors[closest_index].blue);

    return 0;
}