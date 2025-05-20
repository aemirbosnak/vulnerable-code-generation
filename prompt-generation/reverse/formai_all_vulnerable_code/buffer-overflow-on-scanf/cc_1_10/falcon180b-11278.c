//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 256

typedef struct {
    char *name;
    int r;
    int g;
    int b;
} Color;

int main() {
    Color colors[MAX_COLORS];
    int num_colors = 0;

    colors[num_colors++] = (Color) { "red", 255, 0, 0 };
    colors[num_colors++] = (Color) { "green", 0, 255, 0 };
    colors[num_colors++] = (Color) { "blue", 0, 0, 255 };
    colors[num_colors++] = (Color) { "yellow", 255, 255, 0 };
    colors[num_colors++] = (Color) { "purple", 128, 0, 128 };
    colors[num_colors++] = (Color) { "orange", 255, 128, 0 };
    colors[num_colors++] = (Color) { "black", 0, 0, 0 };
    colors[num_colors++] = (Color) { "white", 255, 255, 255 };
    colors[num_colors++] = (Color) { "gray", 128, 128, 128 };

    // Add more colors here

    char input[100];
    int i;

    printf("Enter a color name or RGB value (in hex format): ");
    scanf("%s", input);

    if (input[0] == '#') {
        int r, g, b;
        sscanf(input, "#%02x%02x%02x", &r, &g, &b);

        for (i = 0; i < num_colors; i++) {
            if (colors[i].r == r && colors[i].g == g && colors[i].b == b) {
                printf("RGB value: #%02x%02x%02x\n", r, g, b);
                printf("Color name: %s\n", colors[i].name);
                break;
            }
        }

        if (i == num_colors) {
            printf("Invalid color\n");
        }
    } else {
        for (i = 0; i < num_colors; i++) {
            if (strcmp(input, colors[i].name) == 0) {
                printf("RGB value: #%02x%02x%02x\n", colors[i].r, colors[i].g, colors[i].b);
                break;
            }
        }

        if (i == num_colors) {
            printf("Invalid color\n");
        }
    }

    return 0;
}