//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Linus Torvalds
// Linus Torvalds-style C Basic Image Processing

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Image structure
typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Load an image from a file
Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen");
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    // Read header
    if (fscanf(fp, "P5 %d %d 255", &image->width, &image->height) != 2) {
        perror("fscanf");
        fclose(fp);
        free(image);
        return NULL;
    }

    // Allocate memory for data
    image->data = malloc(image->width * image->height);
    if (!image->data) {
        perror("malloc");
        fclose(fp);
        free(image);
        return NULL;
    }

    // Read data
    if (fread(image->data, 1, image->width * image->height, fp) != image->width * image->height) {
        perror("fread");
        fclose(fp);
        free(image->data);
        free(image);
        return NULL;
    }

    fclose(fp);
    return image;
}

// Save an image to a file
void save_image(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("fopen");
        return;
    }

    // Write header
    fprintf(fp, "P5 %d %d 255\n", image->width, image->height);

    // Write data
    fwrite(image->data, 1, image->width * image->height, fp);

    fclose(fp);
}

// Flip an image horizontally
void flip_horizontal(Image *image) {
    int i, j;
    unsigned char tmp;

    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width / 2; j++) {
            tmp = image->data[i * image->width + j];
            image->data[i * image->width + j] = image->data[i * image->width + image->width - j - 1];
            image->data[i * image->width + image->width - j - 1] = tmp;
        }
    }
}

// Flip an image vertically
void flip_vertical(Image *image) {
    int i, j;
    unsigned char tmp;

    for (i = 0; i < image->height / 2; i++) {
        for (j = 0; j < image->width; j++) {
            tmp = image->data[i * image->width + j];
            image->data[i * image->width + j] = image->data[(image->height - i - 1) * image->width + j];
            image->data[(image->height - i - 1) * image->width + j] = tmp;
        }
    }
}

// Change the brightness of an image
void change_brightness(Image *image, int brightness) {
    int i;

    for (i = 0; i < image->width * image->height; i++) {
        image->data[i] = image->data[i] + brightness;
        if (image->data[i] > 255) {
            image->data[i] = 255;
        } else if (image->data[i] < 0) {
            image->data[i] = 0;
        }
    }
}

// Change the contrast of an image
void change_contrast(Image *image, float contrast) {
    int i;

    for (i = 0; i < image->width * image->height; i++) {
        image->data[i] = (image->data[i] - 128) * contrast + 128;
        if (image->data[i] > 255) {
            image->data[i] = 255;
        } else if (image->data[i] < 0) {
            image->data[i] = 0;
        }
    }
}

// Main function
int main(int argc, char **argv) {
    Image *image;

    // Check arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
        return 1;
    }

    // Load image
    image = load_image(argv[1]);
    if (!image) {
        return 1;
    }

    // Flip image horizontally
    flip_horizontal(image);

    // Flip image vertically
    flip_vertical(image);

    // Change brightness
    change_brightness(image, 50);

    // Change contrast
    change_contrast(image, 1.5);

    // Save image
    save_image("output.pgm", image);

    // Free image
    free(image->data);
    free(image);

    return 0;
}