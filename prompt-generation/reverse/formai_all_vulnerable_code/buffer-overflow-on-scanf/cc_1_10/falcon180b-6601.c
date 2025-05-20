//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LENGTH 80
#define MAX_NUM_COLORS 256

typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    int red;
    int green;
    int blue;
} Color;

Color colors[MAX_NUM_COLORS];
int num_colors;

void add_color(char *name, int red, int green, int blue) {
    if (num_colors >= MAX_NUM_COLORS) {
        printf("Error: too many colors\n");
        exit(1);
    }
    strcpy(colors[num_colors].name, name);
    colors[num_colors].red = red;
    colors[num_colors].green = green;
    colors[num_colors].blue = blue;
    num_colors++;
}

void print_colors() {
    printf("Color Name\tRed\tGreen\tBlue\n");
    for (int i = 0; i < num_colors; i++) {
        printf("%s\t%d\t%d\t%d\n", colors[i].name, colors[i].red, colors[i].green, colors[i].blue);
    }
}

void convert_color(char *color_name, int *red, int *green, int *blue) {
    for (int i = 0; i < num_colors; i++) {
        if (strcmp(color_name, colors[i].name) == 0) {
            *red = colors[i].red;
            *green = colors[i].green;
            *blue = colors[i].blue;
            return;
        }
    }
    printf("Error: color '%s' not found\n", color_name);
    exit(1);
}

int main() {
    add_color("red", 255, 0, 0);
    add_color("green", 0, 255, 0);
    add_color("blue", 0, 0, 255);
    add_color("yellow", 255, 255, 0);
    add_color("cyan", 0, 255, 255);
    add_color("magenta", 255, 0, 255);
    add_color("white", 255, 255, 255);
    add_color("black", 0, 0, 0);
    print_colors();
    char color_name[MAX_COLOR_NAME_LENGTH];
    int red, green, blue;
    while (1) {
        printf("Enter color name: ");
        scanf("%s", color_name);
        convert_color(color_name, &red, &green, &blue);
        printf("Color '%s' is (%d, %d, %d)\n", color_name, red, green, blue);
    }
    return 0;
}