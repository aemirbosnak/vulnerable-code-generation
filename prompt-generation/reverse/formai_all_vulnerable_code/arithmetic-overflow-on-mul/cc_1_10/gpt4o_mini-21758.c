//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *pixels;
} Image;

Image* load_ppm(const char *filename);
void save_ppm(const char *filename, Image *image);
void free_image(Image *image);
void convert_to_grayscale(Image *image);

int main() {
    const char *input_file = "input.ppm";
    const char *output_file = "output.ppm";

    Image *image = load_ppm(input_file);
    if (!image) {
        fprintf(stderr, "Error loading image from %s\n", input_file);
        return 1;
    }

    convert_to_grayscale(image);
    
    save_ppm(output_file, image);
    printf("Image processed and saved as %s\n", output_file);

    free_image(image);
    return 0;
}

Image* load_ppm(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }

    char format[3];
    fscanf(file, "%2s", format);
    if (strcmp(format, "P3") != 0) {
        fprintf(stderr, "Unsupported file format.\n");
        fclose(file);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        fclose(file);
        perror("Memory allocation failed");
        return NULL;
    }

    fscanf(file, "%d %d", &image->width, &image->height);
    int maxval;
    fscanf(file, "%d", &maxval);

    image->pixels = malloc(image->width * image->height * sizeof(Pixel));
    if (!image->pixels) {
        fclose(file);
        free(image);
        perror("Memory allocation for pixels failed");
        return NULL;
    }

    for (int i = 0; i < image->width * image->height; ++i) {
        fscanf(file, "%hhu %hhu %hhu", &image->pixels[i].r, &image->pixels[i].g, &image->pixels[i].b);
    }

    fclose(file);
    return image;
}

void save_ppm(const char *filename, Image *image) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Unable to open file for writing");
        return;
    }

    fprintf(file, "P3\n");
    fprintf(file, "%d %d\n", image->width, image->height);
    fprintf(file, "255\n");

    for (int i = 0; i < image->width * image->height; ++i) {
        fprintf(file, "%hhu %hhu %hhu\n", image->pixels[i].r, image->pixels[i].g, image->pixels[i].b);
    }

    fclose(file);
}

void free_image(Image *image) {
    if (image) {
        free(image->pixels);
        free(image);
    }
}

void convert_to_grayscale(Image *image) {
    for (int i = 0; i < image->width * image->height; ++i) {
        unsigned char gray = (image->pixels[i].r + image->pixels[i].g + image->pixels[i].b) / 3;
        image->pixels[i].r = gray;
        image->pixels[i].g = gray;
        image->pixels[i].b = gray;
    }
}