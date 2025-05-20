//Code Llama-13B DATASET v1.0 Category: Image Steganography ; Style: ultraprecise
// Image Steganography Program in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the pixel values
typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

// Function to hide data in an image
void hide_data(unsigned char *image_data, unsigned char *data, int data_size, int image_size) {
    // Loop through each pixel in the image
    for (int i = 0; i < image_size; i++) {
        // Check if the current pixel is a pixel with data
        if (image_data[i] == 0) {
            // Replace the pixel value with the first byte of the data
            image_data[i] = data[0];
            // Decrement the data size
            data_size--;
            // Increment the data pointer
            data++;
        }
    }
}

// Function to extract data from an image
void extract_data(unsigned char *image_data, unsigned char *data, int data_size, int image_size) {
    // Loop through each pixel in the image
    for (int i = 0; i < image_size; i++) {
        // Check if the current pixel is a pixel with data
        if (image_data[i] != 0) {
            // Replace the pixel value with the first byte of the data
            data[0] = image_data[i];
            // Decrement the data size
            data_size--;
            // Increment the data pointer
            data++;
        }
    }
}

int main() {
    // Read the image data
    FILE *fp = fopen("image.bmp", "rb");
    fseek(fp, 54, SEEK_SET);
    unsigned char *image_data = malloc(100 * 100 * 3);
    fread(image_data, 1, 100 * 100 * 3, fp);
    fclose(fp);

    // Hide data in the image
    unsigned char data[] = "Hello World!";
    int data_size = strlen(data);
    hide_data(image_data, data, data_size, 100 * 100);

    // Write the modified image data to a new file
    fp = fopen("image_modified.bmp", "wb");
    fwrite(image_data, 1, 100 * 100 * 3, fp);
    fclose(fp);

    // Read the modified image data
    fp = fopen("image_modified.bmp", "rb");
    fseek(fp, 54, SEEK_SET);
    unsigned char *modified_image_data = malloc(100 * 100 * 3);
    fread(modified_image_data, 1, 100 * 100 * 3, fp);
    fclose(fp);

    // Extract data from the modified image
    unsigned char extracted_data[data_size];
    extract_data(modified_image_data, extracted_data, data_size, 100 * 100);

    // Print the extracted data
    printf("Extracted data: %s\n", extracted_data);

    return 0;
}