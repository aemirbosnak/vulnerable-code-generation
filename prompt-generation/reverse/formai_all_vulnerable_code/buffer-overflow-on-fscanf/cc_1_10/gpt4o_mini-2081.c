//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024 * 1024 // Maximum image size (1MB)

// Structure to represent an image
typedef struct {
    int width;
    int height;
    unsigned char *data; // Grayscale image data
} Image;

// Function to load an image
Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }

    // Read header
    char header[3];
    fscanf(file, "%2s", header);
    if (strcmp(header, "P5") != 0) {
        fprintf(stderr, "Unsupported image format\n");
        fclose(file);
        return NULL;
    }

    Image *img = malloc(sizeof(Image));
    fscanf(file, "%d %d", &img->width, &img->height);
    fgetc(file); // Consume the newline character
    img->data = malloc(img->width * img->height);

    fread(img->data, 1, img->width * img->height, file);
    fclose(file);
    return img;
}

// Function to save an image
void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open file");
        return;
    }
    fprintf(file, "P5\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, 1, img->width * img->height, file);
    fclose(file);
}

// Function to convert the image to grayscale (functionality included for completeness)
void convert_to_grayscale(Image *img) {
    // Assuming img->data is already in grayscale. 
    // This function is a placeholder.
}

// Function to free an image's memory
void free_image(Image *img) {
    if (img) {
        free(img->data);
        free(img);
    }
}

// Command handler to apply a command to the image
void handle_command(Image *img, const char *command, const char *output_filename) {
    if (strcmp(command, "grayscale") == 0) {
        convert_to_grayscale(img);
        save_image(output_filename, img);
        printf("Converted to grayscale and saved as %s\n", output_filename);
    } else {
        fprintf(stderr, "Unknown command: %s\n", command);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input_image> <command> <output_image>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *command = argv[2];
    const char *output_file = argv[3];

    Image *img = load_image(input_file);
    if (!img) {
        return EXIT_FAILURE;
    }

    handle_command(img, command, output_file);
    free_image(img);
    return EXIT_SUCCESS;
}