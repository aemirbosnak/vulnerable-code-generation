//FormAI DATASET v1.0 Category: Image Editor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pixel {
    int r, g, b;
};

struct Image {
    int width, height;
    struct Pixel *pixels;
};

// Create new image
struct Image* create_image(int w, int h) {
    struct Image *image = (struct Image*)malloc(sizeof(struct Image));
    image->width = w;
    image->height = h;
    image->pixels = (struct Pixel*)malloc(sizeof(struct Pixel)*w*h);
    memset(image->pixels, 0, sizeof(struct Pixel)*w*h);
    return image;
}

// Load image from file
struct Image* load_image(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open file!\n");
        exit(1);
    }
    int w, h;
    fscanf(file, "%d %d", &w, &h);
    struct Image *image = create_image(w, h);
    for (int i = 0; i < w*h; i++) {
        fscanf(file, "%d %d %d", &image->pixels[i].r, &image->pixels[i].g, &image->pixels[i].b);
    }
    fclose(file);
    return image;
}

// Save image to file
void save_image(struct Image *image, char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Failed to open file!\n");
        exit(1);
    }
    fprintf(file, "%d %d\n", image->width, image->height);
    for (int i = 0; i < image->width*image->height; i++) {
        fprintf(file, "%d %d %d\n", image->pixels[i].r, image->pixels[i].g, image->pixels[i].b);
    }
    fclose(file);
}

// Get pixel at x, y
struct Pixel get_pixel(struct Image *image, int x, int y) {
    return image->pixels[y*image->width+x];
}

// Set pixel at x, y
void set_pixel(struct Image *image, int x, int y, struct Pixel p) {
    image->pixels[y*image->width+x] = p;
}

// Invert colors of image
void invert_colors(struct Image *image) {
    for (int i = 0; i < image->width*image->height; i++) {
        image->pixels[i].r = 255 - image->pixels[i].r;
        image->pixels[i].g = 255 - image->pixels[i].g;
        image->pixels[i].b = 255 - image->pixels[i].b;
    }
}

int main() {
    struct Image *image = load_image("example_image.txt");
    invert_colors(image);
    save_image(image, "inverted_image.txt");
    printf("Image converted successfully!\n");
    return 0;
}