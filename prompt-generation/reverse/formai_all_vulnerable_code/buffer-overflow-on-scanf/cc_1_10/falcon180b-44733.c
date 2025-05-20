//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 256

typedef struct {
    char name[20];
    int value;
} Color;

Color colors[] = {
    {"red", 0xFF0000},
    {"green", 0x00FF00},
    {"blue", 0x0000FF},
    {"yellow", 0xFFFF00},
    {"cyan", 0x00FFFF},
    {"magenta", 0xFF00FF},
    {"black", 0x000000},
    {"white", 0xFFFFFF}
};

int main() {
    char input[10];
    int i, numColors = sizeof(colors) / sizeof(Color);
    Color color;

    printf("Enter the color name (or type 'list' to see available colors): ");
    scanf("%s", input);

    if (strcmp(input, "list") == 0) {
        printf("Available colors:\n");
        for (i = 0; i < numColors; i++) {
            printf("%s (%06X)\n", colors[i].name, colors[i].value);
        }
        return 0;
    }

    for (i = 0; i < numColors; i++) {
        if (strcmp(input, colors[i].name) == 0) {
            color = colors[i];
            break;
        }
    }

    if (i == numColors) {
        printf("Invalid color name\n");
        return 1;
    }

    printf("Color value: %06X\n", color.value);

    return 0;
}