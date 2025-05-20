//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    Pixel *data;
    int width;
    int height;
} Image;

// Function declarations
Image *load_ppm(const char *filename);
void save_ppm(const char *filename, const Image *img);
void adjust_brightness(Image *img, int factor);
void free_image(Image *img);
void print_usage(const char *prog_name);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage(argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    int brightness_factor = atoi(argv[3]);

    Image *img = load_ppm(input_file);
    if (!img) {
        fprintf(stderr, "Could not load image: %s\n", input_file);
        return 1;
    }

    adjust_brightness(img, brightness_factor);
    save_ppm(output_file, img);
    free_image(img);

    return 0;
}

Image *load_ppm(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Cannot open file");
        return NULL;
    }

    char header[3];
    fscanf(file, "%s", header);
    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Unsupported PPM format. Only P6 is supported.\n");
        fclose(file);
        return NULL;
    }

    int width, height, maxval;
    fscanf(file, "%d %d %d", &width, &height, &maxval);
    fgetc(file); // Skip the newline character

    Image *img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = malloc(width * height * sizeof(Pixel));

    fread(img->data, sizeof(Pixel), width * height, file);
    fclose(file);

    return img;
}

void save_ppm(const char *filename, const Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Cannot open file");
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void adjust_brightness(Image *img, int factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (img->data[i].r + factor > 255) ? 255 : (img->data[i].r + factor < 0) ? 0 : img->data[i].r + factor;
        img->data[i].g = (img->data[i].g + factor > 255) ? 255 : (img->data[i].g + factor < 0) ? 0 : img->data[i].g + factor;
        img->data[i].b = (img->data[i].b + factor > 255) ? 255 : (img->data[i].b + factor < 0) ? 0 : img->data[i].b + factor;
    }
}

void free_image(Image *img) {
    if (img) {
        free(img->data);
        free(img);
    }
}

void print_usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <input.ppm> <output.ppm> <brightness_factor>\n", prog_name);
}