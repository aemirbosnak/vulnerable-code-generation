//FormAI DATASET v1.0 Category: Image Steganography ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

struct pixel {
    unsigned char r, g, b; // RGB values for each pixel
};

// Function to read in image 
struct pixel** read_image(const char* file_name, int* width, int* height) {
    FILE* f = fopen(file_name, "rb");
    if (!f) {
        printf("Error: Invalid file\n");
        exit(1);
    }

    // Read file header
    char format[3];
    fscanf(f, "%s", format);
    if (format[0] != 'P' || format[1] != '6' || format[2] != 0) {
        printf("Error: Invalid image format\n");
        exit(1);
    }

    // Read image dimensions
    fscanf(f, "%d %d\n", width, height);

    // Read max color value
    int max_color;
    fscanf(f, "%d\n", &max_color);

    // Allocate memory for pixel array
    struct pixel** image = malloc(sizeof(struct pixel*) * (*height));
    for (int i = 0; i < *height; i++) {
        image[i] = malloc(sizeof(struct pixel) * (*width));
    }

    // Read in pixel values
    for (int i = 0; i < *height; i++) {
        for (int j = 0; j < *width; j++) {
            fread(&image[i][j], 3, 1, f);
        }
    }

    // Close file
    fclose(f);

    return image;
}

// Function to write out image to file
void write_image(const char* file_name, struct pixel** image, int width, int height) {
    FILE* f = fopen(file_name, "wb");
    if (!f) {
        printf("Error: Invalid file\n");
        exit(1);
    }

    // Write file header
    fprintf(f, "P6\n%d %d\n255\n", width, height);

    // Write pixel values
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fwrite(&image[i][j], 3, 1, f);
        }
    }

    // Close file
    fclose(f);
}

// Function to hide message in image
void hide_message(struct pixel** image, int width, int height, char* message) {
    int message_length = strlen(message);
    int message_index = 0;

    // Loop through pixels in image and hide message in LSB of each RGB value
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (message_index < message_length) {
                image[i][j].r = (image[i][j].r & 0xFE) | ((message[message_index] >> 7) & 0x01);
                image[i][j].g = (image[i][j].g & 0xFE) | ((message[message_index] >> 6) & 0x01);
                image[i][j].b = (image[i][j].b & 0xFE) | ((message[message_index] >> 5) & 0x01);
                message_index++;
            }
        }
    }
}

// Function to recover message from image
char* recover_message(struct pixel** image, int width, int height) {
    char* message = malloc(sizeof(char));
    int message_length = 0;

    // Loop through pixels in image and recover message from LSB of each RGB value
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            message_length++;
            message = realloc(message, sizeof(char) * message_length);
            message[message_length - 1] = ((image[i][j].r & 0x01) << 7) |
                                          ((image[i][j].g & 0x01) << 6) |
                                          ((image[i][j].b & 0x01) << 5);
        }
    }

    return message;
}

int main() {
    // Read in image
    int width, height;
    struct pixel** image = read_image("image.ppm", &width, &height);

    // Hide message in image
    char* message = "This is a hidden message!";
    hide_message(image, width, height, message);

    // Write out modified image
    write_image("modified_image.ppm", image, width, height);

    // Recover message from modified image
    struct pixel** modified_image = read_image("modified_image.ppm", &width, &height);
    char* recovered_message = recover_message(modified_image, width, height);
    printf("Recovered message: %s\n", recovered_message);

    // Clean up memory
    for (int i = 0; i < height; i++) {
        free(image[i]);
        free(modified_image[i]);
    }
    free(image);
    free(modified_image);
    free(recovered_message);

    return 0;
}