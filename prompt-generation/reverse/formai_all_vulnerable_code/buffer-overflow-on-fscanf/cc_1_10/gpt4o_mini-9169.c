//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *data;
} Image;

// Function declarations
Image* load_image(const char *filename);
void save_image(const char *filename, Image *img);
void free_image(Image *img);
Image* flip_image(Image *img);
Image* change_brightness(Image *img, int value);
Image* change_contrast(Image *img, float factor);
void print_usage(const char *prog_name);

int main(int argc, char *argv[]) {
    if (argc < 4) {
        print_usage(argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    const char *operation = argv[3];
    Image *img = load_image(input_file);
    if (!img) {
        fprintf(stderr, "Error loading image.\n");
        return 1;
    }

    Image *result_img = NULL;

    if (strcmp(operation, "flip") == 0) {
        result_img = flip_image(img);
    } else if (strcmp(operation, "brightness") == 0) {
        if (argc != 5) {
            print_usage(argv[0]);
            free_image(img);
            return 1;
        }
        int brightness_value = atoi(argv[4]);
        result_img = change_brightness(img, brightness_value);
    } else if (strcmp(operation, "contrast") == 0) {
        if (argc != 5) {
            print_usage(argv[0]);
            free_image(img);
            return 1;
        }
        float contrast_factor = atof(argv[4]);
        result_img = change_contrast(img, contrast_factor);
    } else {
        fprintf(stderr, "Unknown operation: %s\n", operation);
        free_image(img);
        return 1;
    }

    save_image(output_file, result_img);

    free_image(img);
    free_image(result_img);
    return 0;
}

Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) return NULL;

    char header[3];
    fscanf(file, "%s", header);
    if (strcmp(header, "P6") != 0) {
        fclose(file);
        return NULL;
    }

    Image *img = malloc(sizeof(Image));
    fscanf(file, "%d %d", &img->width, &img->height);
    int max_val;
    fscanf(file, "%d", &max_val);
    fgetc(file); // Consume newline character

    img->data = malloc(img->width * img->height * sizeof(Pixel));
    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    return img;
}

void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void free_image(Image *img) {
    if (img) {
        free(img->data);
        free(img);
    }
}

Image* flip_image(Image *img) {
    Image *flipped = malloc(sizeof(Image));
    flipped->width = img->width;
    flipped->height = img->height;
    flipped->data = malloc(img->width * img->height * sizeof(Pixel));

    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            flipped->data[i * img->width + (img->width - j - 1)] = img->data[i * img->width + j];
        }
    }
    return flipped;
}

Image* change_brightness(Image *img, int value) {
    Image *brightened = malloc(sizeof(Image));
    brightened->width = img->width;
    brightened->height = img->height;
    brightened->data = malloc(img->width * img->height * sizeof(Pixel));

    for (int i = 0; i < img->width * img->height; i++) {
        brightened->data[i].red = (unsigned char) fmin(255, fmax(0, img->data[i].red + value));
        brightened->data[i].green = (unsigned char) fmin(255, fmax(0, img->data[i].green + value));
        brightened->data[i].blue = (unsigned char) fmin(255, fmax(0, img->data[i].blue + value));
    }
    return brightened;
}

Image* change_contrast(Image *img, float factor) {
    Image *contrasted = malloc(sizeof(Image));
    contrasted->width = img->width;
    contrasted->height = img->height;
    contrasted->data = malloc(img->width * img->height * sizeof(Pixel));

    for (int i = 0; i < img->width * img->height; i++) {
        contrasted->data[i].red = (unsigned char) fmin(255, fmax(0, ((img->data[i].red - 128) * factor) + 128));
        contrasted->data[i].green = (unsigned char) fmin(255, fmax(0, ((img->data[i].green - 128) * factor) + 128));
        contrasted->data[i].blue = (unsigned char) fmin(255, fmax(0, ((img->data[i].blue - 128) * factor) + 128));
    }
    return contrasted;
}

void print_usage(const char *prog_name) {
    printf("Usage: %s <input_file> <output_file> <operation> [options]\n", prog_name);
    printf("Operations:\n");
    printf("  flip\n");
    printf("  brightness <value>\n");
    printf("  contrast <factor>\n");
}