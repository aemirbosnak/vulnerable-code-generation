//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 1000
#define MAX_COLOR_NAME_LENGTH 20

typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    int red;
    int green;
    int blue;
} Color;

Color colors[MAX_COLORS];
int num_colors = 0;

void add_color(char* name, int red, int green, int blue) {
    if (num_colors >= MAX_COLORS) {
        printf("Error: too many colors defined.\n");
        exit(1);
    }
    strcpy(colors[num_colors].name, name);
    colors[num_colors].red = red;
    colors[num_colors].green = green;
    colors[num_colors].blue = blue;
    num_colors++;
}

void print_colors() {
    printf("Available colors:\n");
    for (int i = 0; i < num_colors; i++) {
        printf("%s (%d, %d, %d)\n", colors[i].name, colors[i].red, colors[i].green, colors[i].blue);
    }
}

int main() {
    add_color("red", 255, 0, 0);
    add_color("green", 0, 255, 0);
    add_color("blue", 0, 0, 255);
    add_color("yellow", 255, 255, 0);
    add_color("cyan", 0, 255, 255);
    add_color("magenta", 255, 0, 255);
    add_color("black", 0, 0, 0);
    add_color("white", 255, 255, 255);

    print_colors();

    char input[MAX_COLOR_NAME_LENGTH];
    printf("Enter a color name: ");
    scanf("%s", input);

    int index = -1;
    for (int i = 0; i < num_colors; i++) {
        if (strcmp(colors[i].name, input) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: color not found.\n");
        return 1;
    }

    printf("RGB values for %s: (%d, %d, %d)\n", colors[index].name, colors[index].red, colors[index].green, colors[index].blue);

    return 0;
}