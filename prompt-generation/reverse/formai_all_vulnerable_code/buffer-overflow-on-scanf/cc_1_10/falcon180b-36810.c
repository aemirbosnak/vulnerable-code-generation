//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 256
#define COLOR_NAME_LENGTH 8

typedef struct {
    char name[COLOR_NAME_LENGTH];
    int value;
} Color;

Color colors[MAX_COLORS];
int num_colors = 0;

void add_color(char* name, int value) {
    if (num_colors >= MAX_COLORS) {
        printf("Error: Too many colors.\n");
        exit(1);
    }

    strncpy(colors[num_colors].name, name, COLOR_NAME_LENGTH);
    colors[num_colors].value = value;
    num_colors++;
}

int main() {
    add_color("red", 0xFF0000);
    add_color("green", 0x00FF00);
    add_color("blue", 0x0000FF);

    char input[COLOR_NAME_LENGTH];
    while (1) {
        printf("Enter a color name: ");
        scanf("%s", input);

        int i;
        for (i = 0; i < num_colors; i++) {
            if (strcmp(colors[i].name, input) == 0) {
                printf("%s: #%06X\n", colors[i].name, colors[i].value);
                break;
            }
        }

        if (i == num_colors) {
            printf("Color not found.\n");
        }
    }

    return 0;
}