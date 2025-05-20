//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_FILENAME 256
#define MAX_SIZE 1000
#define MAGIC_NUMBER "P6"

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *data;
} Image;

void paranoid_memory_check(void *ptr) {
    if (!ptr) {
        fprintf(stderr, "Potential memory corruption detected! Exiting...\n");
        exit(EXIT_FAILURE);
    }
}

Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    paranoid_memory_check(file);
    
    char magic[3];
    int max_color;

    fgets(magic, sizeof(magic), file);
    if (strcmp(magic, MAGIC_NUMBER) != 0) {
        fprintf(stderr, "Not a valid PPM file!\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    Image *img = (Image*)malloc(sizeof(Image));
    paranoid_memory_check(img);

    fscanf(file, "%d %d\n%d\n", &img->width, &img->height, &max_color);
    
    img->data = (Pixel*)malloc(img->width * img->height * sizeof(Pixel));
    paranoid_memory_check(img->data);

    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    
    return img;
}

void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    paranoid_memory_check(file);

    fprintf(file, "%s\n%d %d\n255\n", MAGIC_NUMBER, img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void apply_grayscale(Image *img) {
    for (int i = 0; i < img->width * img->height; ++i) {
        unsigned char gray = (unsigned char)(0.3 * img->data[i].r + 0.59 * img->data[i].g + 0.11 * img->data[i].b);
        img->data[i].r = gray;
        img->data[i].g = gray;
        img->data[i].b = gray;
    }
}

void apply_inversion(Image *img) {
    for (int i = 0; i < img->width * img->height; ++i) {
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

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm> <operation>\n", argv[0]);
        fprintf(stderr, "Operations: grayscale, invert\n");
        exit(EXIT_FAILURE);
    }
    
    Image *img = load_image(argv[1]);
    
    if (strcmp(argv[3], "grayscale") == 0) {
        apply_grayscale(img);
    } else if (strcmp(argv[3], "invert") == 0) {
        apply_inversion(img);
    } else {
        fprintf(stderr, "Unknown operation: %s\n", argv[3]);
        free_image(img);
        exit(EXIT_FAILURE);
    }
    
    save_image(argv[2], img);
    free_image(img);
    
    printf("Image processed and saved as %s\n", argv[2]);

    return EXIT_SUCCESS;
}