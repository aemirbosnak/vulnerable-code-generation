//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold the image data
typedef struct {
    int width;
    int height;
    unsigned char *data; // RGB data
} Image;

// Function prototypes
Image* load_image(const char *filename);
void save_image(const char *filename, const Image *img);
void invert_colors(Image *img);
void free_image(Image *img);
void print_usage(const char *prog_name);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    Image *img = load_image(argv[1]);
    if (!img) {
        fprintf(stderr, "Error loading image %s.\n", argv[1]);
        return EXIT_FAILURE;
    }

    invert_colors(img);

    save_image(argv[2], img);
    free_image(img);

    printf("Image processing completed! Saved as %s\n", argv[2]);
    return EXIT_SUCCESS;
}

// Function to load an image from a PPM file
Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    char format[3];
    fscanf(file, "%s", format);
    if (strcmp(format, "P6") != 0) {
        fprintf(stderr, "Unsupported PPM format: %s\n", format);
        fclose(file);
        return NULL;
    }

    Image *img = (Image *)malloc(sizeof(Image));
    if (!img) {
        perror("Failed to allocate memory for image");
        fclose(file);
        return NULL;
    }

    fscanf(file, "%d %d", &img->width, &img->height);
    int max_color_value;
    fscanf(file, "%d", &max_color_value);
    fgetc(file); // Skip the newline

    img->data = (unsigned char *)malloc(img->width * img->height * 3);
    if (!img->data) {
        perror("Failed to allocate memory for image data");
        free(img);
        fclose(file);
        return NULL;
    }

    fread(img->data, 1, img->width * img->height * 3, file);
    fclose(file);
    return img;
}

// Function to save an image to a PPM file
void save_image(const char *filename, const Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file for writing");
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, 1, img->width * img->height * 3, file);
    fclose(file);
}

// Function to invert colors of the image
void invert_colors(Image *img) {
    for (int i = 0; i < img->width * img->height * 3; i++) {
        img->data[i] = 255 - img->data[i];
    }
}

// Function to free the memory used by the image
void free_image(Image *img) {
    if (img) {
        free(img->data);
        free(img);
    }
}

// Function to print usage instructions
void print_usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <input.ppm> <output.ppm>\n", prog_name);
}