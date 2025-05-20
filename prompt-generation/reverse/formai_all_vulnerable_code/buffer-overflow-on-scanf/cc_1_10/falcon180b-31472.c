//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 16

typedef struct {
    char name[20];
    char hex[8];
    int r, g, b;
} Color;

Color colors[MAX_COLORS] = {
    {"Black", "#000000", 0, 0, 0},
    {"White", "#FFFFFF", 255, 255, 255},
    {"Red", "#FF0000", 255, 0, 0},
    {"Green", "#00FF00", 0, 255, 0},
    {"Blue", "#0000FF", 0, 0, 255},
    {"Yellow", "#FFFF00", 255, 255, 0},
    {"Cyan", "#00FFFF", 0, 255, 255},
    {"Magenta", "#FF00FF", 255, 0, 255},
    {"Gray", "#808080", 128, 128, 128},
    {"DarkRed", "#8B0000", 139, 0, 0},
    {"DarkGreen", "#006400", 0, 100, 0},
    {"DarkBlue", "#00008B", 0, 0, 139},
    {"DarkYellow", "#8B8B00", 139, 139, 0},
    {"DarkCyan", "#008B8B", 0, 139, 139},
    {"DarkMagenta", "#8B008B", 139, 0, 139}
};

int main() {
    int choice, i;
    char input[20];

    printf("Color Code Converter\n");
    printf("---------------------\n");

    for (i = 0; i < MAX_COLORS; i++) {
        printf("%d. %s\n", i + 1, colors[i].name);
    }

    printf("\nEnter the number of the color you want to convert: ");
    scanf("%d", &choice);

    printf("Enter the color in hexadecimal format: ");
    scanf("%s", input);

    if (choice < 1 || choice > MAX_COLORS) {
        printf("Invalid color choice.\n");
        return 1;
    }

    printf("The color %s in hexadecimal format is:\n", input);
    printf("RGB: (%d, %d, %d)\n", colors[choice - 1].r, colors[choice - 1].g, colors[choice - 1].b);
    printf("Hexadecimal: %s\n", colors[choice - 1].hex);

    return 0;
}