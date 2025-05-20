//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct {
    char name[MAX_LENGTH];
    char hex[MAX_LENGTH];
    char decimal[MAX_LENGTH];
    char binary[MAX_LENGTH];
} color_t;

color_t colors[] = {
    { "red", "FF0000", "16711680", "11111111" },
    { "green", "00FF00", "65280", "11111100" },
    { "blue", "0000FF", "255", "11111111" },
    { "yellow", "FFFF00", "16776960", "1111111110000000" },
    { "purple", "800080", "8388736", "11110000" },
    { "orange", "FFA500", "16753920", "1111111110001000" },
    { "pink", "FF69B4", "16711936", "1111111110001010" },
    { "cyan", "00FFFF", "65280", "11111100" }
};

int num_colors = sizeof(colors) / sizeof(color_t);

void print_color(color_t color) {
    printf("Name: %s\n", color.name);
    printf("Hex: %s\n", color.hex);
    printf("Decimal: %s\n", color.decimal);
    printf("Binary: %s\n", color.binary);
    printf("\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <color name>\n", argv[0]);
        exit(1);
    }

    color_t *color = NULL;
    for (int i = 0; i < num_colors; i++) {
        if (strcmp(colors[i].name, argv[1]) == 0) {
            color = &colors[i];
            break;
        }
    }

    if (color == NULL) {
        printf("Invalid color name.\n");
        exit(1);
    }

    print_color(*color);

    return 0;
}