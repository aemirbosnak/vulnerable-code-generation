//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAMES 100
#define MAX_COLOR_CODE_LENGTH 7

typedef struct {
    char *name;
    char code[MAX_COLOR_CODE_LENGTH];
} Color;

Color colors[MAX_COLOR_NAMES];
int num_colors = 0;

void add_color(char *name, char *code) {
    if (num_colors >= MAX_COLOR_NAMES) {
        printf("Error: Maximum number of colors reached.\n");
        return;
    }

    strcpy(colors[num_colors].name, name);
    strcpy(colors[num_colors].code, code);

    num_colors++;
}

int main() {
    add_color("red", "#FF0000");
    add_color("green", "#00FF00");
    add_color("blue", "#0000FF");

    char input[MAX_COLOR_CODE_LENGTH];
    while (1) {
        printf("Enter a color code: ");
        scanf("%s", input);

        int i;
        for (i = 0; i < num_colors; i++) {
            if (strcmp(input, colors[i].code) == 0) {
                printf("Color name: %s\n", colors[i].name);
                break;
            }
        }

        if (i == num_colors) {
            printf("Color not found.\n");
        }
    }

    return 0;
}