//MISTRAL-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 50
#define HEIGHT 5

typedef struct {
    unsigned char r, g, b;
} pixel;

void romeo_juliet_ascii(pixel color) {
    char symbols[][WIDTH] = {
        "ROMEO:", ".......", "..:....", ".:.o.o.", "...:..", "..:.o.:..", ":o...o:", ".......",
        "JULIET:", "......:.", "..:..:..", ".:.....:", "..:.o.o.", "......:.", "....:..:", "......:"
    };

    int intensity = (color.r + color.g + color.b) / 3;

    int row = intensity / (WIDTH / HEIGHT);
    int col = (color.r * 30 / 255 + color.g * 50 / 255 + color.b * 70 / 255) % WIDTH;

    printf("%s%s\n", symbols[row], &symbols[row][col]);
}

int main() {
    FILE *image_file = fopen("image.pgm", "rb");
    if (!image_file) {
        perror("Error opening image file");
        return 1;
    }

    char header[10];
    fgets(header, sizeof(header), image_file);

    int width, height, max_intensity;
    sscanf(header, "%s %d %d %d", header, &width, &height, &max_intensity);

    if (width != WIDTH || height != HEIGHT) {
        fprintf(stderr, "Image size mismatch\n");
        fclose(image_file);
        return 1;
    }

    pixel *pixels = malloc(width * height * sizeof(pixel));
    fread(pixels, sizeof(pixel), width * height, image_file);

    for (int i = 0; i < width * height; ++i) {
        romeo_juliet_ascii(pixels[i]);
    }

    free(pixels);
    fclose(image_file);

    return 0;
}