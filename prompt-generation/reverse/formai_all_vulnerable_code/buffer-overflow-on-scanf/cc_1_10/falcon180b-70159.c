//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 16

typedef struct {
    char name[20];
    int red;
    int green;
    int blue;
} Color;

Color colors[MAX_COLORS] = {
    {"black", 0, 0, 0},
    {"white", 255, 255, 255},
    {"red", 255, 0, 0},
    {"green", 0, 255, 0},
    {"blue", 0, 0, 255},
    {"yellow", 255, 255, 0},
    {"magenta", 255, 0, 255},
    {"cyan", 0, 255, 255},
    {"gray", 128, 128, 128},
    {"lightgray", 192, 192, 192},
    {"darkgray", 64, 64, 64},
    {"lightred", 255, 128, 128},
    {"lightgreen", 128, 255, 128},
    {"lightblue", 128, 128, 255},
    {"pink", 255, 192, 203}
};

int main() {
    int i, j, choice, found = 0;
    char color_name[20];

    printf("Color Code Converter\n");
    printf("Enter 1 to convert from color name to code\n");
    printf("Enter 2 to convert from code to color name\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter color name: ");
        scanf("%s", color_name);

        for (i = 0; i < MAX_COLORS; i++) {
            if (strcmp(color_name, colors[i].name) == 0) {
                printf("Color code for %s: %d,%d,%d\n", colors[i].name, colors[i].red, colors[i].green, colors[i].blue);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Color not found\n");
        }
    } else if (choice == 2) {
        printf("Enter color code (format: R,G,B): ");
        scanf("%d,%d,%d", &colors[MAX_COLORS-1].red, &colors[MAX_COLORS-1].green, &colors[MAX_COLORS-1].blue);
        strcpy(colors[MAX_COLORS-1].name, "custom");
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}