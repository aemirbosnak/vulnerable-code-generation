//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 256
#define MAX_COLOR_NAME_LENGTH 32

typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    int hex_value;
} Color;

Color colors[MAX_COLORS];

int main() {
    int num_colors = 0;
    FILE *colors_file = fopen("colors.txt", "r");

    if (colors_file == NULL) {
        printf("Error: could not open colors file\n");
        return 1;
    }

    while (fscanf(colors_file, "%s %X", colors[num_colors].name, &colors[num_colors].hex_value) == 2) {
        num_colors++;
    }

    fclose(colors_file);

    printf("Enter a color name or hex value:\n");
    char input[MAX_COLOR_NAME_LENGTH];
    scanf("%s", input);

    int hex_value = 0;
    if (input[0] == '#') {
        hex_value = strtol(input + 1, NULL, 16);
    } else {
        for (int i = 0; i < num_colors; i++) {
            if (strcmp(input, colors[i].name) == 0) {
                hex_value = colors[i].hex_value;
                break;
            }
        }
    }

    if (hex_value == 0) {
        printf("Invalid color name or hex value\n");
        return 1;
    }

    printf("Hex value: %X\n", hex_value);
    printf("RGB value: %d, %d, %d\n", (hex_value >> 16) & 0xFF, (hex_value >> 8) & 0xFF, hex_value & 0xFF);

    return 0;
}