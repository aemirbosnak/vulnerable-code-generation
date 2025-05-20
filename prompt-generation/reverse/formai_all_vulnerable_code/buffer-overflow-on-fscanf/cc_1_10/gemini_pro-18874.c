//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

// Simple image processing functions
void flip_image(unsigned char *image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            unsigned char temp = image[i * width + j];
            image[i * width + j] = image[i * width + width - j - 1];
            image[i * width + width - j - 1] = temp;
        }
    }
}

void change_brightness(unsigned char *image, int width, int height, int brightness) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int new_value = (int)image[i * width + j] + brightness;
            if (new_value < 0) new_value = 0;
            if (new_value > 255) new_value = 255;
            image[i * width + j] = (unsigned char)new_value;
        }
    }
}

void change_contrast(unsigned char *image, int width, int height, int contrast) {
    float factor = (259.0f * (contrast + 255.0f)) / (255.0f * (259.0f - contrast));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int new_value = factor * (image[i * width + j] - 128) + 128;
            if (new_value < 0) new_value = 0;
            if (new_value > 255) new_value = 255;
            image[i * width + j] = (unsigned char)new_value;
        }
    }
}

// Main function
int main(int argc, char **argv) {
    // Check if the user has provided enough arguments
    if (argc < 5) {
        printf("Usage: %s <input_image> <output_image> <task> <value>\n", argv[0]);
        printf("Tasks:\n");
        printf("  - flip: flips the image horizontally\n");
        printf("  - brightness: changes the brightness of the image (value between -128 and 128)\n");
        printf("  - contrast: changes the contrast of the image (value between -100 and 100)\n");
        return 1;
    }

    // Get the input and output image filenames
    char *input_image_filename = argv[1];
    char *output_image_filename = argv[2];

    // Get the task and value
    char *task = argv[3];
    int value = atoi(argv[4]);

    // Read the input image
    FILE *input_image_file = fopen(input_image_filename, "rb");
    if (input_image_file == NULL) {
        printf("Error: could not open input image file %s\n", input_image_filename);
        return 1;
    }

    // Get the image dimensions
    int width, height;
    fscanf(input_image_file, "%d %d", &width, &height);

    // Allocate memory for the image data
    unsigned char *image = (unsigned char *)malloc(width * height * sizeof(unsigned char));
    if (image == NULL) {
        printf("Error: could not allocate memory for image data\n");
        return 1;
    }

    // Read the image data
    fread(image, sizeof(unsigned char), width * height, input_image_file);
    fclose(input_image_file);

    // Perform the image processing task
    if (strcmp(task, "flip") == 0) {
        flip_image(image, width, height);
    } else if (strcmp(task, "brightness") == 0) {
        change_brightness(image, width, height, value);
    } else if (strcmp(task, "contrast") == 0) {
        change_contrast(image, width, height, value);
    } else {
        printf("Error: invalid task %s\n", task);
        return 1;
    }

    // Write the output image
    FILE *output_image_file = fopen(output_image_filename, "wb");
    if (output_image_file == NULL) {
        printf("Error: could not open output image file %s\n", output_image_filename);
        return 1;
    }

    // Write the image dimensions
    fprintf(output_image_file, "%d %d\n", width, height);

    // Write the image data
    fwrite(image, sizeof(unsigned char), width * height, output_image_file);
    fclose(output_image_file);

    // Free the memory allocated for the image data
    free(image);

    return 0;
}