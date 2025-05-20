//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

Image* load_ppm(const char *filename);
void save_ppm(const char *filename, Image *image);
void free_image(Image *image);
void invert_colors(Image *image);
void grayscale(Image *image);
void display_image_info(Image *image);

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <input.ppm> <output.ppm>\n", argv[0]);
        return 1;
    }

    Image *image = load_ppm(argv[1]);
    if (!image) {
        fprintf(stderr, "Error loading image.\n");
        return 1;
    }

    display_image_info(image);

    // Invert colors
    invert_colors(image);
    save_ppm(argv[2], image);

    // Grayscale image
    grayscale(image);
    save_ppm("grayscale_output.ppm", image);

    free_image(image);
    return 0;
}

Image* load_ppm(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    char header[3];
    fscanf(file, "%s", header);
    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Unsupported PPM format\n");
        fclose(file);
        return NULL;
    }

    int width, height, max_color;
    fscanf(file, "%d %d %d", &width, &height, &max_color);
    fgetc(file); // Skip the newline

    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * sizeof(Pixel));
    
    fread(image->data, sizeof(Pixel), width * height, file);
    fclose(file);
    
    return image;
}

void save_ppm(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Failed to open file for writing");
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->data, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
}

void invert_colors(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i].r = 255 - image->data[i].r;
        image->data[i].g = 255 - image->data[i].g;
        image->data[i].b = 255 - image->data[i].b;
    }
}

void grayscale(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        uint8_t gray = (image->data[i].r + image->data[i].g + image->data[i].b) / 3;
        image->data[i].r = gray;
        image->data[i].g = gray;
        image->data[i].b = gray;
    }
}

void display_image_info(Image *image) {
    printf("Image Width: %d\n", image->width);
    printf("Image Height: %d\n", image->height);
    printf("Total Pixels: %d\n", image->width * image->height);
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}