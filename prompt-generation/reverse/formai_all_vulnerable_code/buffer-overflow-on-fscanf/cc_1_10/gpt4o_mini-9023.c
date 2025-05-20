//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *pixels;
} Image;

void load_image(const char* filename, Image* img) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }
    
    // Simple PPM format (P6)
    char header[3];
    fscanf(file, "%s\n", header);
    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Unsupported file format\n");
        exit(1);
    }
    
    fscanf(file, "%d %d\n255\n", &(img->width), &(img->height));
    img->pixels = malloc(sizeof(Pixel) * img->width * img->height);
    
    if (!img->pixels) {
        perror("Failed to allocate memory for image");
        exit(1);
    }
    
    fread(img->pixels, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void save_image(const char* filename, const Image* img) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }
    
    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->pixels, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void apply_grayscale(Image* img) {
    for (int i = 0; i < img->width * img->height; i++) {
        uint8_t gray = (uint8_t)(0.299 * img->pixels[i].r + 0.587 * img->pixels[i].g + 0.114 * img->pixels[i].b);
        img->pixels[i].r = img->pixels[i].g = img->pixels[i].b = gray;
    }
}

void apply_sepia(Image* img) {
    for (int i = 0; i < img->width * img->height; i++) {
        uint8_t tr = (uint8_t)(0.393 * img->pixels[i].r + 0.769 * img->pixels[i].g + 0.189 * img->pixels[i].b);
        uint8_t tg = (uint8_t)(0.349 * img->pixels[i].r + 0.686 * img->pixels[i].g + 0.168 * img->pixels[i].b);
        uint8_t tb = (uint8_t)(0.272 * img->pixels[i].r + 0.534 * img->pixels[i].g + 0.131 * img->pixels[i].b);
        
        img->pixels[i].r = (tr > 255) ? 255 : tr;
        img->pixels[i].g = (tg > 255) ? 255 : tg;
        img->pixels[i].b = (tb > 255) ? 255 : tb;
    }
}

void free_image(Image* img) {
    free(img->pixels);
    img->pixels = NULL;
}

int main() {
    Image img;
    const char *input_file = "input.ppm";
    const char *output_file_gray = "output_gray.ppm";
    const char *output_file_sepia = "output_sepia.ppm";
    
    load_image(input_file, &img);
    
    Image img_gray = img; // Copy for grayscale
    apply_grayscale(&img_gray);
    save_image(output_file_gray, &img_gray);
    
    Image img_sepia = img; // Copy for sepia
    apply_sepia(&img_sepia);
    save_image(output_file_sepia, &img_sepia);
    
    printf("Finished processing images: %s, %s\n", output_file_gray, output_file_sepia);
    
    // Clean-up
    free_image(&img);
    
    return 0;
}