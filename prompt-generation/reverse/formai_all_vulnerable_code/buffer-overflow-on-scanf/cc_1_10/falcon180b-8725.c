//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 256

typedef struct {
    char name[20];
    int red, green, blue;
} Color;

Color colors[MAX_COLORS];
int num_colors = 0;

void add_color(char *name, int red, int green, int blue) {
    if (num_colors >= MAX_COLORS) {
        fprintf(stderr, "Error: Too many colors defined.\n");
        exit(1);
    }
    strcpy(colors[num_colors].name, name);
    colors[num_colors].red = red;
    colors[num_colors].green = green;
    colors[num_colors].blue = blue;
    num_colors++;
}

int main() {
    add_color("red", 255, 0, 0);
    add_color("green", 0, 255, 0);
    add_color("blue", 0, 0, 255);
    add_color("yellow", 255, 255, 0);
    add_color("purple", 128, 0, 128);
    add_color("cyan", 0, 255, 255);
    add_color("orange", 255, 128, 0);
    add_color("gray", 128, 128, 128);
    add_color("white", 255, 255, 255);
    add_color("black", 0, 0, 0);

    int choice, red, green, blue;
    char color_name[20];

    printf("Enter the name of the color you want to convert:\n");
    scanf("%s", color_name);

    for (int i = 0; i < num_colors; i++) {
        if (strcmp(colors[i].name, color_name) == 0) {
            printf("The RGB values for %s are:\n", color_name);
            printf("Red: %d\n", colors[i].red);
            printf("Green: %d\n", colors[i].green);
            printf("Blue: %d\n", colors[i].blue);
            break;
        }
    }

    return 0;
}