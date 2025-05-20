//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 1000
#define HEIGHT 1000
#define MAX_COLORS 256

typedef struct {
    int r;
    int g;
    int b;
} Color;

Color* generate_palette(int num_colors) {
    Color* palette = malloc(sizeof(Color) * num_colors);

    for (int i = 0; i < num_colors; i++) {
        palette[i].r = rand() % 256;
        palette[i].g = rand() % 256;
        palette[i].b = rand() % 256;
    }

    return palette;
}

void generate_image(Color* palette, int width, int height, FILE* output) {
    fprintf(output, "P6\n%d %d\n%d\n", width, height, 255);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = rand() % MAX_COLORS;
            fprintf(output, "%d %d %d ", palette[index].r, palette[index].g, palette[index].b);
        }
        fprintf(output, "\n");
    }
}

int main() {
    srand(time(NULL));

    Color* palette = generate_palette(MAX_COLORS);
    FILE* output = fopen("image.png", "wb");

    if (output == NULL) {
        printf("Error: Could not open output file.\n");
        return 1;
    }

    generate_image(palette, WIDTH, HEIGHT, output);

    fclose(output);

    printf("Image generated successfully!\n");

    return 0;
}