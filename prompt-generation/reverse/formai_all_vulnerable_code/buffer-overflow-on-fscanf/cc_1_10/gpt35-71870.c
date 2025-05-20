//FormAI DATASET v1.0 Category: Image Editor ; Style: genious
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int r, g, b;
} Pixel;

void grayscale(Pixel* image, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        int average = (image[i].r + image[i].g + image[i].b) / 3;
        image[i].r = average;
        image[i].g = average;
        image[i].b = average;
    }
}

void invert_colors(Pixel* image, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        image[i].r = 255 - image[i].r;
        image[i].g = 255 - image[i].g;
        image[i].b = 255 - image[i].b;
    }
}

void apply_filter(Pixel* image, int width, int height, int filter[3][3]) {
    Pixel* temp_image = malloc(sizeof(Pixel) * width * height);
    for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < width - 1; j++) {
            int red = 0, green = 0, blue = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    int index = (i + k) * width + (j + l);
                    red += image[index].r * filter[k + 1][l + 1];
                    green += image[index].g * filter[k + 1][l + 1];
                    blue += image[index].b * filter[k + 1][l + 1];
                }
            }
            temp_image[i * width + j].r = red;
            temp_image[i * width + j].g = green;
            temp_image[i * width + j].b = blue;
        }
    }
    for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < width - 1; j++) {
            image[i * width + j] = temp_image[i * width + j];
        }
    }
    free(temp_image);
}

int main() {
    FILE* image_file = fopen("image.ppm", "r");
    char format[4];
    int width, height, max_value;
    fscanf(image_file, "%s %d %d %d", format, &width, &height, &max_value);
    Pixel* image = malloc(sizeof(Pixel) * width * height);
    for (int i = 0; i < width * height; i++) {
        fscanf(image_file, "%d %d %d", &image[i].r, &image[i].g, &image[i].b);
    }
    fclose(image_file);

    grayscale(image, width, height);
    apply_filter(image, width, height, (int[3][3]){{0, -1, 0}, {-1, 5, -1}, {0, -1, 0}});
    invert_colors(image, width, height);

    FILE* output_file = fopen("output.ppm", "w");
    fprintf(output_file, "%s\n%d %d\n%d\n", format, width, height, max_value);
    for (int i = 0; i < width * height; i++) {
        fprintf(output_file, "%d %d %d ", image[i].r, image[i].g, image[i].b);
    }
    fclose(output_file);

    free(image);
    return 0;
}