//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void flip_image(char *filename);
void change_brightness_contrast(char *filename, int brightness, float contrast);

int main(void) {
    char filename[100];
    int choice, brightness;
    float contrast;

    printf("Enter the filename of the image: ");
    scanf("%s", filename);

    printf("\nWhat would you like to do with the image?\n");
    printf("[1] Flip the image\n");
    printf("[2] Change the brightness and contrast\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            flip_image(filename);
            break;
        case 2:
            printf("Enter the brightness value (-255 to 255): ");
            scanf("%d", &brightness);
            printf("Enter the contrast value (0.0 to 2.0): ");
            scanf("%f", &contrast);
            change_brightness_contrast(filename, brightness, contrast);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}

void flip_image(char *filename) {
    FILE *fp_read, *fp_write;
    unsigned char header[54];
    unsigned char *image_data, *flipped_data;
    unsigned int width, height, padding, image_size;

    // Open the input file
    fp_read = fopen(filename, "rb");
    if (fp_read == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Read the header
    fread(header, sizeof(unsigned char), 54, fp_read);

    // Extract image dimensions
    width = *(int*)&header[18];
    height = *(int*)&header[22];

    // Calculate padding
    padding = (4 - (width * 3) % 4) % 4;

    // Calculate image size
    image_size = (width * 3 + padding) * height;

    // Allocate memory for image data
    image_data = (unsigned char*) malloc(image_size);
    flipped_data = (unsigned char*) malloc(image_size);

    // Read the image data from the file
    fread(image_data, sizeof(unsigned char), image_size, fp_read);

    // Close the input file
    fclose(fp_read);

    // Flip the image
    unsigned int i, j, index;
    for (i = 0; i < height; ++i) {
        for (j = 0; j < width; ++j) {
            index = (i * width + j) * 3;
            flipped_data[(height - i - 1) * (width * 3 + padding) + index] = image_data[i * (width * 3 + padding) + j * 3];
            flipped_data[(height - i - 1) * (width * 3 + padding) + index + 1] = image_data[i * (width * 3 + padding) + j * 3 + 1];
            flipped_data[(height - i - 1) * (width * 3 + padding) + index + 2] = image_data[i * (width * 3 + padding) + j * 3 + 2];
        }
    }

    // Open the output file
    fp_write = fopen("flipped.bmp", "wb");
    if (fp_write == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Write the header
    fwrite(header, sizeof(unsigned char), 54, fp_write);

    // Write the flipped image data
    fwrite(flipped_data, sizeof(unsigned char), image_size, fp_write);

    // Close the output file
    fclose(fp_write);

    // Free memory
    free(image_data);
    free(flipped_data);

    printf("Image has been flipped and saved to flipped.bmp\n");
}

void change_brightness_contrast(char *filename, int brightness, float contrast) {
    FILE *fp_read, *fp_write;
    unsigned char header[54];
    unsigned char *image_data, *adjusted_data;
    unsigned int width, height, padding, image_size;

    // Open the input file
    fp_read = fopen(filename, "rb");
    if (fp_read == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Read the header
    fread(header, sizeof(unsigned char), 54, fp_read);

    // Extract image dimensions
    width = *(int*)&header[18];
    height = *(int*)&header[22];

    // Calculate padding
    padding = (4 - (width * 3) % 4) % 4;

    // Calculate image size
    image_size = (width * 3 + padding) * height;

    // Allocate memory for image data
    image_data = (unsigned char*) malloc(image_size);
    adjusted_data = (unsigned char*) malloc(image_size);

    // Read the image data from the file
    fread(image_data, sizeof(unsigned char), image_size, fp_read);

    // Close the input file
    fclose(fp_read);

    // Adjust the brightness and contrast
    unsigned int i, j, index;
    float pixel_value;
    for (i = 0; i < height; ++i) {
        for (j = 0; j < width; ++j) {
            index = (i * width + j) * 3;
            pixel_value = image_data[index] * contrast + brightness;
            if (pixel_value > 255) {
                pixel_value = 255;
            } else if (pixel_value < 0) {
                pixel_value = 0;
            }
            adjusted_data[index] = (unsigned char) pixel_value;
            pixel_value = image_data[index + 1] * contrast + brightness;
            if (pixel_value > 255) {
                pixel_value = 255;
            } else if (pixel_value < 0) {
                pixel_value = 0;
            }
            adjusted_data[index + 1] = (unsigned char) pixel_value;
            pixel_value = image_data[index + 2] * contrast + brightness;
            if (pixel_value > 255) {
                pixel_value = 255;
            } else if (pixel_value < 0) {
                pixel_value = 0;
            }
            adjusted_data[index + 2] = (unsigned char) pixel_value;
        }
    }

    // Open the output file
    fp_write = fopen("adjusted.bmp", "wb");
    if (fp_write == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Write the header
    fwrite(header, sizeof(unsigned char), 54, fp_write);

    // Write the adjusted image data
    fwrite(adjusted_data, sizeof(unsigned char), image_size, fp_write);

    // Close the output file
    fclose(fp_write);

    // Free memory
    free(image_data);
    free(adjusted_data);

    printf("Image has been adjusted and saved to adjusted.bmp\n");
}