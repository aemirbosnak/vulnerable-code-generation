//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

// A simple struct to represent an image
struct image {
    int width;
    int height;
    int *data;
};

// Read an image from a file
struct image *read_image(const char *filename) {
    // Open the file
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("fopen");
        return NULL;
    }

    // Read the header
    int width, height;
    if (fscanf(file, "P3\n%d %d\n255\n", &width, &height) != 3) {
        perror("fscanf");
        fclose(file);
        return NULL;
    }

    // Allocate memory for the image
    struct image *image = malloc(sizeof(struct image));
    if (!image) {
        perror("malloc");
        fclose(file);
        return NULL;
    }

    image->width = width;
    image->height = height;
    image->data = malloc(width * height * sizeof(int));
    if (!image->data) {
        perror("malloc");
        free(image);
        fclose(file);
        return NULL;
    }

    // Read the pixel data
    for (int i = 0; i < width * height; i++) {
        if (fscanf(file, "%d", &image->data[i]) != 1) {
            perror("fscanf");
            free(image->data);
            free(image);
            fclose(file);
            return NULL;
        }
    }

    // Close the file
    fclose(file);

    return image;
}

// Write an image to a file
void write_image(const char *filename, struct image *image) {
    // Open the file
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("fopen");
        return;
    }

    // Write the header
    fprintf(file, "P3\n%d %d\n255\n", image->width, image->height);

    // Write the pixel data
    for (int i = 0; i < image->width * image->height; i++) {
        fprintf(file, "%d ", image->data[i]);
    }

    // Close the file
    fclose(file);
}

// Flip an image horizontally
void flip_horizontal(struct image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width / 2; j++) {
            int temp = image->data[i * image->width + j];
            image->data[i * image->width + j] = image->data[i * image->width + image->width - 1 - j];
            image->data[i * image->width + image->width - 1 - j] = temp;
        }
    }
}

// Flip an image vertically
void flip_vertical(struct image *image) {
    for (int i = 0; i < image->height / 2; i++) {
        for (int j = 0; j < image->width; j++) {
            int temp = image->data[i * image->width + j];
            image->data[i * image->width + j] = image->data[(image->height - 1 - i) * image->width + j];
            image->data[(image->height - 1 - i) * image->width + j] = temp;
        }
    }
}

// Change the brightness of an image
void change_brightness(struct image *image, int brightness) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i] += brightness;
        if (image->data[i] < 0) {
            image->data[i] = 0;
        } else if (image->data[i] > 255) {
            image->data[i] = 255;
        }
    }
}

// Change the contrast of an image
void change_contrast(struct image *image, int contrast) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i] = image->data[i] * contrast / 100;
        if (image->data[i] < 0) {
            image->data[i] = 0;
        } else if (image->data[i] > 255) {
            image->data[i] = 255;
        }
    }
}


int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input image> <output image>\n", argv[0]);
        return 1;
    }

    // Read the input image
    struct image *input_image = read_image(argv[1]);
    if (!input_image) {
        return 1;
    }

    // Flip the image horizontally
    flip_horizontal(input_image);

    // Flip the image vertically
    flip_vertical(input_image);

    // Change the brightness of the image
    change_brightness(input_image, 50);

    // Change the contrast of the image
    change_contrast(input_image, 150);

    // Write the output image
    write_image(argv[2], input_image);

    // Free the input image
    free(input_image->data);
    free(input_image);

    return 0;
}