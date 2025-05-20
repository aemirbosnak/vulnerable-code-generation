//FormAI DATASET v1.0 Category: Image Steganography ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char magic_number[3]; // Magic number identifying the file as a PPM image
    int width; // Width of the image
    int height; // Height of the image
    int max_color_value; // Max color value of the pixels
    unsigned char* pixels; // The array of pixel values
} PPM_Image;

// Function to read a PPM image and return a pointer to the image
PPM_Image* read_ppm_image(char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    // Read the header of the PPM image
    PPM_Image* image = (PPM_Image*) malloc(sizeof(PPM_Image));
    fscanf(fp, "%s\n%d %d\n%d\n", image->magic_number, &image->width, &image->height, &image->max_color_value);

    // Allocate memory for the pixels array
    image->pixels = (unsigned char*) malloc(sizeof(unsigned char) * image->width * image->height * 3);

    // Read the pixel data into the pixels array
    fread(image->pixels, sizeof(unsigned char), image->width * image->height * 3, fp);

    // Close the file and return the image pointer
    fclose(fp);
    return image;
}

// Function to write a PPM image to a file
void write_ppm_image(PPM_Image* image, char* filename) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    // Write the header of the PPM image
    fprintf(fp, "%s\n%d %d\n%d\n", image->magic_number, image->width, image->height, image->max_color_value);

    // Write the pixel data to the file
    fwrite(image->pixels, sizeof(unsigned char), image->width * image->height * 3, fp);

    // Close the file
    fclose(fp);
}

// Function to hide a message in a PPM image
void hide_message(PPM_Image* image, char* message) {
    int message_len = strlen(message);
    int pixel_index = 0;
    int char_index = 0;
    unsigned char pixel_value;
    int bit_index;
    int bit_value;

    for (char_index = 0; char_index < message_len; char_index++) {
        for (bit_index = 0; bit_index < 8; bit_index++) {
            // Get the next bit of the message
            bit_value = message[char_index] & (1 << (7 - bit_index));

            // Modify the least significant bit of the current pixel
            pixel_value = image->pixels[pixel_index];
            pixel_value = (pixel_value & ~1) | bit_value;
            image->pixels[pixel_index] = pixel_value;

            pixel_index++;
        }
    }
}

// Function to retrieve a hidden message from a PPM image
char* retrieve_message(PPM_Image* image) {
    int message_len = 0;
    int pixel_index = 0;
    unsigned char pixel_value;
    int bit_index;
    int bit_value;

    while (1) {
        for (bit_index = 0; bit_index < 8; bit_index++) {
            // Get the least significant bit of the current pixel
            pixel_value = image->pixels[pixel_index];
            bit_value = pixel_value & 1;

            // Add the bit to the message
            message_len = (message_len << 1) | bit_value;

            pixel_index++;

            // If we have reached the end of the message, return it
            if (bit_index == 7 && message_len == 0) {
                // Allocate memory for the message and return it
                char* message = (char*) malloc(sizeof(char));
                message[0] = '\0';
                return message;
            } else if (bit_index == 7) {
                break;
            }
        }

        // Check if we have retrieved all the bits of the message
        if (bit_index == 7 && message_len != 0) {
            break;
        }
    }

    // Allocate memory for the message and fill it with the retrieved bits
    char* message = (char*) malloc(sizeof(char) * (message_len / 8 + 1));
    int char_index = 0;

    while (char_index < message_len / 8) {
        char current_char = 0;

        for (bit_index = 0; bit_index < 8; bit_index++) {
            pixel_value = image->pixels[pixel_index];
            bit_value = pixel_value & 1;

            current_char = (current_char << 1) | bit_value;

            pixel_index++;
        }

        message[char_index] = current_char;
        char_index++;
    }

    message[char_index] = '\0';

    return message;
}

int main() {
    // Read the input image and display its dimensions
    PPM_Image* image = read_ppm_image("input.ppm");
    printf("Image width: %d pixels\n", image->width);
    printf("Image height: %d pixels\n", image->height);

    // Hide a message in the image and write the resulting image to a file
    char* message = "Hello, world!";
    hide_message(image, message);
    write_ppm_image(image, "output.ppm");

    // Retrieve the hidden message from the image and print it
    PPM_Image* encoded_image = read_ppm_image("output.ppm");
    char* retrieved_message = retrieve_message(encoded_image);
    printf("Retrieved message: %s\n", retrieved_message);

    // Free memory
    free(image->pixels);
    free(image);
    free(encoded_image->pixels);
    free(encoded_image);
    free(retrieved_message);

    return 0;
}