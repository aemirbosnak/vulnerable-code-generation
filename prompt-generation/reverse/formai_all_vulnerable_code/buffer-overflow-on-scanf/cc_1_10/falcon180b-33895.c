//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_COLORS 256
#define MAX_PALETTES 16
#define MAX_COLORS_IN_PALETTE 16

typedef struct {
    int red;
    int green;
    int blue;
} Color;

typedef struct {
    Color colors[MAX_COLORS_IN_PALETTE];
    int num_colors;
} Palette;

Palette generate_palette(int num_colors) {
    Palette palette;
    palette.num_colors = num_colors;

    srand(time(NULL));

    for (int i = 0; i < num_colors; i++) {
        palette.colors[i].red = rand() % 256;
        palette.colors[i].green = rand() % 256;
        palette.colors[i].blue = rand() % 256;
    }

    return palette;
}

void print_palette(Palette palette) {
    for (int i = 0; i < palette.num_colors; i++) {
        printf("%d %d %d\n", palette.colors[i].red, palette.colors[i].green, palette.colors[i].blue);
    }
}

int main() {
    int num_colors;
    printf("Enter the number of colors in the palette: ");
    scanf("%d", &num_colors);

    Palette palette = generate_palette(num_colors);
    print_palette(palette);

    return 0;
}