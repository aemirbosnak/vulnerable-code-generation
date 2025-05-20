//FormAI DATASET v1.0 Category: Image Steganography ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Set the maximum size of the image
#define MAX_SIZE 256

// Define a structure to hold the image data
typedef struct {
    int width;
    int height;
    int data[MAX_SIZE][MAX_SIZE];
} Image;

// Function to read in an image from a file
void read_image(Image *image, char *file_name) {
    FILE *file_ptr;
    int i, j;

    file_ptr = fopen(file_name, "r");
    if (file_ptr == NULL) {
        printf("Failed to open file %s\n", file_name);
        exit(1);
    }

    // Get the dimensions of the image
    fscanf(file_ptr, "%d %d", &(image->width), &(image->height));

    // Read in the image data
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            fscanf(file_ptr, "%d", &(image->data[i][j]));
        }
    }

    fclose(file_ptr);
}

// Function to write an image to a file
void write_image(Image *image, char *file_name) {
    FILE *file_ptr;
    int i, j;

    file_ptr = fopen(file_name, "w");
    if (file_ptr == NULL) {
        printf("Failed to open file %s\n", file_name);
        exit(1);
    }

    // Output the dimensions of the image
    fprintf(file_ptr, "%d %d\n", image->width, image->height);

    // Output the image data
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            fprintf(file_ptr, "%d ", image->data[i][j]);
        }
        fprintf(file_ptr, "\n");
    }

    fclose(file_ptr);
}

// Function to encode a message in an image
void encode(Image *image, char *message) {
    int i, j, k = 0, bit_count = 0;
    bool done = false;

    // Loop through the pixels of the image
    for (i = 0; i < image->height && !done; i++) {
        for (j = 0; j < image->width && !done; j++) {
            // Get the current pixel value
            int pixel_value = image->data[i][j];

            // Get the bit to encode
            int bit_to_encode = (message[k] >> bit_count) & 1;

            // Set the least significant bit of the pixel value to the bit to encode
            pixel_value = (pixel_value & 0xfe) | bit_to_encode;

            // Write the new pixel value to the image data
            image->data[i][j] = pixel_value;

            // Increment the bit count
            bit_count++;

            // If we encoded all of the bits in this byte, go to the next byte
            if (bit_count == 8) {
                bit_count = 0;
                k++;
            }

            // If we encoded the final byte, we're done
            if (message[k] == '\0') {
                done = true;
                break;
            }
        }
    }
}

// Function to decode a message from an image
void decode(Image *image, char *message, int max_len) {
    int i, j, k = 0, bit_count = 0;
    bool done = false;

    // Loop through the pixels of the image
    for (i = 0; i < image->height && !done; i++) {
        for (j = 0; j < image->width && !done; j++) {
            // Get the current pixel value
            int pixel_value = image->data[i][j];

            // Extract the least significant bit
            int bit_extracted = pixel_value & 1;

            // Add the bit to the message
            message[k] |= (bit_extracted << bit_count);

            // Increment the bit count
            bit_count++;

            // If we extracted all of the bits in this byte, go to the next byte
            if (bit_count == 8) {
                bit_count = 0;
                k++;
            }

            // If we decoded the null terminator, we're done
            if (k == max_len || message[k] == '\0') {
                done = true;
                break;
            }
        }
    }
}

int main() {
    Image image;
    char message[] = "Hello, world!";
    char decoded_message[100];
    int max_len = 100;

    // Read in the image from the file
    read_image(&image, "image.txt");

    // Encode the message in the image
    encode(&image, message);

    // Write the modified image back to the file
    write_image(&image, "encoded_image.txt");

    // Read in the encoded image from the file
    read_image(&image, "encoded_image.txt");

    // Decode the message from the image
    decode(&image, decoded_message, max_len);

    // Print the original and decoded messages
    printf("Original message: %s\n", message);
    printf("Decoded message: %s\n", decoded_message);

    return 0;
}