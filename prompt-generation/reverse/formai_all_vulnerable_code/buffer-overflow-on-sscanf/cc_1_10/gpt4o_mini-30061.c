//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: romantic
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

// Function declarations
Image* load_image(const char *filename);
void save_image(const char *filename, Image *img);
void apply_sepia(Image *img);
void free_image(Image *img);
void display_image_info(Image *img);

void express_romance() {
    printf("\nIn the world of pixels and colors, ");
    printf("this tender program awakens the heart with warm sepia tones.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_image.ppm> <output_image.ppm>\n", argv[0]);
        return 1;
    }

    express_romance();

    Image *image = load_image(argv[1]);
    if (image == NULL) {
        printf("Failed to load image.\n");
        return 1;
    }

    display_image_info(image);
    apply_sepia(image);
    save_image(argv[2], image);
    free_image(image);

    printf("The image has been tenderly transformed into a sepia masterpiece. " 
           "Open it and let love wash over you.\n");
    return 0;
}

Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return NULL;
    }

    // Read the PPM header
    char buffer[32];
    fgets(buffer, sizeof(buffer), file); // Read the magic number
    if (strcmp(buffer, "P6\n") != 0) {
        fclose(file);
        return NULL;
    }

    // Skip comments and read width and height
    int width, height, max_color;
    while (fgets(buffer, sizeof(buffer), file)[0] == '#');
    sscanf(buffer, "%d %d", &width, &height);
    fgets(buffer, sizeof(buffer), file); // Read max color

    if (sscanf(buffer, "%d", &max_color) != 1 || max_color != 255) {
        fclose(file);
        return NULL;
    }

    // Allocate pixel array
    Image *img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = malloc(width * height * sizeof(Pixel));

    // Read pixel data
    fread(img->data, sizeof(Pixel), width * height, file);
    fclose(file);
    return img;
}

void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) return;

    // Write the PPM header
    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void apply_sepia(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        uint8_t original_r = img->data[i].r;
        uint8_t original_g = img->data[i].g;
        uint8_t original_b = img->data[i].b;

        img->data[i].r = (uint8_t) fmin(255, (original_r * 0.393) + (original_g * 0.769) + (original_b * 0.189));
        img->data[i].g = (uint8_t) fmin(255, (original_r * 0.349) + (original_g * 0.686) + (original_b * 0.168));
        img->data[i].b = (uint8_t) fmin(255, (original_r * 0.272) + (original_g * 0.534) + (original_b * 0.131));
    }
}

void free_image(Image *img) {
    free(img->data);
    free(img);
}

void display_image_info(Image *img) {
    printf("Loading an enchanting image...\n");
    printf("Width: %d pixels, Height: %d pixels\n", img->width, img->height);
}