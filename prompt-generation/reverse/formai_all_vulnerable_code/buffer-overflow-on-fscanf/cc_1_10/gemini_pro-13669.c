//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image *image_new(int width, int height) {
    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        return NULL;
    }

    image->width = width;
    image->height = height;
    image->data = malloc(width * height * 3);
    if (image->data == NULL) {
        free(image);
        return NULL;
    }

    return image;
}

void image_delete(Image *image) {
    if (image != NULL) {
        free(image->data);
        free(image);
    }
}

int image_load(Image *image, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        return -1;
    }

    // Read the header
    char header[3];
    if (fread(header, 1, 3, file) != 3) {
        fclose(file);
        return -1;
    }

    // Check if the header is valid
    if (strncmp(header, "P6", 2) != 0) {
        fclose(file);
        return -1;
    }

    // Read the width and height
    int width, height;
    if (fscanf(file, "%d %d", &width, &height) != 2) {
        fclose(file);
        return -1;
    }

    // Read the maximum color value
    int max_color;
    if (fscanf(file, "%d", &max_color) != 1) {
        fclose(file);
        return -1;
    }

    // Check if the maximum color value is valid
    if (max_color != 255) {
        fclose(file);
        return -1;
    }

    // Read the image data
    if (fread(image->data, 1, width * height * 3, file) != width * height * 3) {
        fclose(file);
        return -1;
    }

    fclose(file);

    image->width = width;
    image->height = height;

    return 0;
}

int image_save(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        return -1;
    }

    // Write the header
    fprintf(file, "P6\n");

    // Write the width and height
    fprintf(file, "%d %d\n", image->width, image->height);

    // Write the maximum color value
    fprintf(file, "255\n");

    // Write the image data
    fwrite(image->data, 1, image->width * image->height * 3, file);

    fclose(file);

    return 0;
}

void image_invert(Image *image) {
    for (int i = 0; i < image->width * image->height * 3; i++) {
        image->data[i] = 255 - image->data[i];
    }
}

void image_grayscale(Image *image) {
    for (int i = 0; i < image->width * image->height * 3; i += 3) {
        int gray = (image->data[i] + image->data[i + 1] + image->data[i + 2]) / 3;
        image->data[i] = gray;
        image->data[i + 1] = gray;
        image->data[i + 2] = gray;
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <image file>\n", argv[0]);
        return 1;
    }

    // Load the image
    Image *image = image_new(MAX_IMAGE_SIZE, MAX_IMAGE_SIZE);
    if (image == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for image.\n");
        return 1;
    }

    if (image_load(image, argv[1]) != 0) {
        fprintf(stderr, "Error: Could not load image %s.\n", argv[1]);
        image_delete(image);
        return 1;
    }

    // Invert the image
    image_invert(image);

    // Save the image
    if (image_save(image, "inverted.ppm") != 0) {
        fprintf(stderr, "Error: Could not save image inverted.ppm.\n");
        image_delete(image);
        return 1;
    }

    // Grayscale the image
    image_grayscale(image);

    // Save the image
    if (image_save(image, "grayscale.ppm") != 0) {
        fprintf(stderr, "Error: Could not save image grayscale.ppm.\n");
        image_delete(image);
        return 1;
    }

    // Delete the image
    image_delete(image);

    return 0;
}