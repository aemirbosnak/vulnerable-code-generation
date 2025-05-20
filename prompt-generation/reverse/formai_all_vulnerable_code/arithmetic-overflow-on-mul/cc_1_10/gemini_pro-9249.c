//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: excited
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

int main() {
    // Read the image from a file
    FILE *image_file = fopen("image.ppm", "rb");
    if (image_file == NULL) {
        printf("Error opening the image file.\n");
        return EXIT_FAILURE;
    }

    // Read the header information from the image file
    char header[256];
    fscanf(image_file, "%s\n", header);
    int width, height;
    fscanf(image_file, "%d %d\n", &width, &height);
    int max_color_value;
    fscanf(image_file, "%d\n", &max_color_value);

    // Allocate memory for the image data
    pixel *image_data = malloc(width * height * sizeof(pixel));
    if (image_data == NULL) {
        printf("Error allocating memory for the image data.\n");
        return EXIT_FAILURE;
    }

    // Read the image data from the file
    fread(image_data, sizeof(pixel), width * height, image_file);
    fclose(image_file);

    // Flip the image vertically
    for (int i = 0; i < width * height / 2; i++) {
        pixel temp = image_data[i];
        image_data[i] = image_data[width * height - i - 1];
        image_data[width * height - i - 1] = temp;
    }

    // Change the brightness and contrast of the image
    int brightness = 50;
    int contrast = 100;
    for (int i = 0; i < width * height; i++) {
        image_data[i].red = (image_data[i].red + brightness) * contrast / 100;
        image_data[i].green = (image_data[i].green + brightness) * contrast / 100;
        image_data[i].blue = (image_data[i].blue + brightness) * contrast / 100;
    }

    // Write the modified image data to a new file
    FILE *new_image_file = fopen("new_image.ppm", "wb");
    if (new_image_file == NULL) {
        printf("Error opening the new image file.\n");
        return EXIT_FAILURE;
    }

    // Write the header information to the new image file
    fprintf(new_image_file, "%s\n", header);
    fprintf(new_image_file, "%d %d\n", width, height);
    fprintf(new_image_file, "%d\n", max_color_value);

    // Write the image data to the new image file
    fwrite(image_data, sizeof(pixel), width * height, new_image_file);
    fclose(new_image_file);

    // Free the memory allocated for the image data
    free(image_data);

    return EXIT_SUCCESS;
}