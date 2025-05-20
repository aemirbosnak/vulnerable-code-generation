//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold image data
typedef struct {
    unsigned char r, g, b;
} Pixel;

// Function to read a PPM image
int read_ppm(const char *filename, Pixel **image, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Cannot open file");
        return -1;
    }

    char buffer[16];
    fgets(buffer, sizeof(buffer), file);
    if (buffer[0] != 'P' || buffer[1] != '6') {
        fprintf(stderr, "Invalid PPM file\n");
        fclose(file);
        return -1;
    }

    fscanf(file, "%d %d", width, height);
    int max_color;
    fscanf(file, "%d", &max_color);
    fgetc(file); // Consume newline character

    *image = (Pixel *)malloc((*width) * (*height) * sizeof(Pixel));
    if (!*image) {
        perror("Unable to allocate memory");
        fclose(file);
        return -1;
    }

    fread(*image, sizeof(Pixel), (*width) * (*height), file);
    fclose(file);
    return 0;
}

// Function to write a PPM image
int write_ppm(const char *filename, Pixel *image, int width, int height) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Cannot open file for writing");
        return -1;
    }

    fprintf(file, "P6\n%d %d\n255\n", width, height);
    fwrite(image, sizeof(Pixel), width * height, file);
    fclose(file);
    return 0;
}

// Function to encode a message into the image
void encode_message(Pixel *image, const char *message, int width, int height) {
    int length = strlen(message);
    int total_pixels = width * height;

    // Embed the length of the message in the first pixel's blue value
    image[0].b = length;

    for (int i = 0; i < length && i < total_pixels - 1; i++) {
        // Store each character in the blue channel of subsequent pixels
        image[i + 1].b = message[i];
    }
}

// Function to decode a message from the image
void decode_message(Pixel *image, char *message, int width, int height) {
    int length = image[0].b;
    for (int i = 0; i < length && i < (width * height - 1); i++) {
        message[i] = image[i + 1].b;
    }
    message[length] = '\0'; // Null terminate the decoded string
}

int main() {
    const char *input_file = "input.ppm";     // The input image file
    const char *output_file = "output.ppm";   // The output image file
    const char *secret_message = "Hello, friend!"; // The message to be encoded

    Pixel *image = NULL;
    int width, height;

    // Read the original image
    if (read_ppm(input_file, &image, &width, &height) != 0) {
        return EXIT_FAILURE;
    }

    // Encode the message into the image
    encode_message(image, secret_message, width, height);
    
    // Write the modified image to a new file
    if (write_ppm(output_file, image, width, height) != 0) {
        free(image);
        return EXIT_FAILURE;
    }

    printf("Message encoded successfully into %s\n", output_file);

    // Decoding the message to verify
    char decoded_message[1024];
    decode_message(image, decoded_message, width, height);
    printf("Decoded message: %s\n", decoded_message);

    // Clean up
    free(image);
    return EXIT_SUCCESS;
}