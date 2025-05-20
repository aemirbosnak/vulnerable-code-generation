//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel* pixels;
} Image;

// Function prototypes
Image* load_ppm(const char* filename);
void save_ppm(const char* filename, Image* img);
Image* invert_colors(Image* img);
void free_image(Image* img);

// Load the PPM image
Image* load_ppm(const char* filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }

    char header[3];
    fscanf(fp, "%s", header);
    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Unsupported format: %s\n", header);
        fclose(fp);
        return NULL;
    }

    Image* img = malloc(sizeof(Image));
    fscanf(fp, "%d %d", &img->width, &img->height);
    int max_val;
    fscanf(fp, "%d", &max_val);
    fgetc(fp);  // consume the newline character after max_val

    img->pixels = malloc(img->width * img->height * sizeof(Pixel));
    fread(img->pixels, sizeof(Pixel), img->width * img->height, fp);
    fclose(fp);
    return img;
}

// Save the PPM image
void save_ppm(const char* filename, Image* img) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error writing file: %s\n", filename);
        return;
    }

    fprintf(fp, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->pixels, sizeof(Pixel), img->width * img->height, fp);
    fclose(fp);
}

// Invert the image colors
Image* invert_colors(Image* img) {
    Image* new_img = malloc(sizeof(Image));
    new_img->width = img->width;
    new_img->height = img->height;
    new_img->pixels = malloc(img->width * img->height * sizeof(Pixel));
    
    for (int i = 0; i < img->width * img->height; i++) {
        new_img->pixels[i].r = 255 - img->pixels[i].r;
        new_img->pixels[i].g = 255 - img->pixels[i].g;
        new_img->pixels[i].b = 255 - img->pixels[i].b;
    }
    
    return new_img;
}

// Free the memory allocated for the image
void free_image(Image* img) {
    if (img) {
        free(img->pixels);
        free(img);
    }
}

// Main function
int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Load the PPM image
    Image* img = load_ppm(argv[1]);
    if (img == NULL) {
        return EXIT_FAILURE;
    }

    // Invert the colors
    Image* inverted_img = invert_colors(img);

    // Save the inverted image
    save_ppm(argv[2], inverted_img);

    // Clean up
    free_image(img);
    free_image(inverted_img);

    printf("Inversion complete! Saved to: %s\n", argv[2]);

    return EXIT_SUCCESS;
}