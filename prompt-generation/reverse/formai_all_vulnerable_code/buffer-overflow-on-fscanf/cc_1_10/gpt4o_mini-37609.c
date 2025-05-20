//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *data;
} Image;

// Function to load the image
Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "My love, I cannot find thee!\n");
        return NULL;
    }
    
    // Read the header (P3 format)
    char format[3];
    fscanf(file, "%2s", format);
    if (strcmp(format, "P3") != 0) {
        fclose(file);
        fprintf(stderr, "Ah, but I dream of P3!\n");
        return NULL;
    }

    int width, height, max_color;
    fscanf(file, "%d %d %d", &width, &height, &max_color);
    
    Image *img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = malloc(width * height * sizeof(Pixel));
    
    // Read pixel data
    for (int i = 0; i < width * height; i++) {
        fscanf(file, "%hhu %hhu %hhu", &img->data[i].r, &img->data[i].g, &img->data[i].b);
    }

    fclose(file);
    return img;
}

// Function to save the image
void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Oh, cruel fate! I cannot save our love!\n");
        return;
    }
    
    fprintf(file, "P3\n%d %d\n255\n", img->width, img->height);
    for (int i = 0; i < img->width * img->height; i++) {
        fprintf(file, "%d %d %d\n", img->data[i].r, img->data[i].g, img->data[i].b);
    }

    fclose(file);
    printf("Hark! Our love is saved to %s!\n", filename);
}

// Function to apply grayscale filter
void apply_grayscale(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        uint8_t gray = (img->data[i].r + img->data[i].g + img->data[i].b) / 3;
        img->data[i].r = gray;
        img->data[i].g = gray;
        img->data[i].b = gray;
    }
    printf("Alas! Our image is now but a shadow in shades of gray...\n");
}

// Function to free the image
void free_image(Image *img) {
    free(img->data);
    free(img);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Oh, Montague! Wherefore art thou, input and output images?\n");
        return 1;
    }

    Image *img = load_image(argv[1]);
    if (!img) return 1;

    apply_grayscale(img);
    save_image(argv[2], img);
    
    free_image(img);
    return 0;
}