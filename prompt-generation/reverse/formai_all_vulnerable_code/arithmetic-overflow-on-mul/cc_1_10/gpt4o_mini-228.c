//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

Image *load_ppm(const char *filename);
void save_ppm(const char *filename, const Image *img);
void invert_image(Image *img);
void free_image(Image *img);
void print_usage(const char *program_name);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    const char *operation = argv[3];

    Image *img = load_ppm(input_file);
    if (!img) {
        fprintf(stderr, "Error loading image: %s\n", input_file);
        return EXIT_FAILURE;
    }

    if (strcmp(operation, "invert") == 0) {
        invert_image(img);
    } else {
        fprintf(stderr, "Unknown operation: %s\n", operation);
        free_image(img);
        return EXIT_FAILURE;
    }

    save_ppm(output_file, img);
    free_image(img);
    return EXIT_SUCCESS;
}

Image *load_ppm(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        return NULL;
    }

    char format[3];
    fscanf(file, "%2s", format);
    if (strcmp(format, "P6") != 0) {
        fprintf(stderr, "Unsupported PPM format: %s\n", format);
        fclose(file);
        return NULL;
    }

    Image *img = malloc(sizeof(Image));
    fscanf(file, "%d %d", &img->width, &img->height);
    
    int maxval;
    fscanf(file, "%d", &maxval);
    fgetc(file);  // consume the newline after maxval

    img->data = malloc(img->width * img->height * sizeof(Pixel));
    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    return img;
}

void save_ppm(const char *filename, const Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Could not open file for writing");
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void invert_image(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = 255 - img->data[i].r;
        img->data[i].g = 255 - img->data[i].g;
        img->data[i].b = 255 - img->data[i].b;
    }
}

void free_image(Image *img) {
    if (img) {
        free(img->data);
        free(img);
    }
}

void print_usage(const char *program_name) {
    fprintf(stderr, "Usage: %s <input.ppm> <output.ppm> <operation>\n", program_name);
    fprintf(stderr, "Operation: invert\n");
}