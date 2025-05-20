//FormAI DATASET v1.0 Category: Image Editor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Define constants
#define MAX_FILENAME_LENGTH 50
#define MAX_COMMAND_LENGTH 10

// Define pixel struct
typedef struct Pixel {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} Pixel;

// Define image struct
typedef struct Image {
    Pixel** pixels;
    int width;
    int height;
} Image;

// Function to allocate memory for a new image
Image* create_image(int width, int height) {
    // Allocate memory for the struct
    Image* new_image = (Image*) malloc(sizeof(Image));

    // Allocate memory for the pixel array
    new_image->pixels = (Pixel**) malloc(sizeof(Pixel*) * height);
    for (int i = 0; i < height; i++) {
        new_image->pixels[i] = (Pixel*) malloc(sizeof(Pixel) * width);
    }

    // Set the width and height
    new_image->width = width;
    new_image->height = height;

    return new_image;
}

// Function to free memory allocated for an image
void destroy_image(Image* image) {
    // Free the pixel array memory
    for (int i = 0; i < image->height; i++) {
        free(image->pixels[i]);
    }
    free(image->pixels);

    // Free the struct memory
    free(image);
}

// Function to read an image from a file
Image* read_image_from_file(char* filename) {
    FILE* file = fopen(filename, "rb");

    // Check if file was opened successfully
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // Read the width and height from the file
    int width, height;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);

    // Create a new image with the given dimensions
    Image* image = create_image(width, height);

    // Read the pixels from the file
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fread(&(image->pixels[i][j]), sizeof(Pixel), 1, file);
        }
    }

    // Close the file
    fclose(file);

    return image;
}

// Function to write an image to a file
void write_image_to_file(Image* image, char* filename) {
    FILE* file = fopen(filename, "wb");

    // Write the width and height to the file
    fwrite(&(image->width), sizeof(int), 1, file);
    fwrite(&(image->height), sizeof(int), 1, file);

    // Write the pixels to the file
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            fwrite(&(image->pixels[i][j]), sizeof(Pixel), 1, file);
        }
    }

    // Close the file
    fclose(file);
}

// Function to apply a grayscale filter to an image
void grayscale_filter(Image* image) {
    // Loop through all pixels
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            // Calculate the grayscale value for each pixel
            uint8_t gray = (image->pixels[i][j].red + image->pixels[i][j].green + image->pixels[i][j].blue) / 3;
            image->pixels[i][j].red = gray;
            image->pixels[i][j].green = gray;
            image->pixels[i][j].blue = gray;
        }
    }
}

// Function to apply an invert filter to an image
void invert_filter(Image* image) {
    // Loop through all pixels
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            // Invert each color value for each pixel
            image->pixels[i][j].red = 255 - image->pixels[i][j].red;
            image->pixels[i][j].green = 255 - image->pixels[i][j].green;
            image->pixels[i][j].blue = 255 - image->pixels[i][j].blue;
        }
    }
}

// Function to apply a sepia filter to an image
void sepia_filter(Image* image) {
    // Loop through all pixels
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            // Calculate the sepia values for each color value for each pixel
            uint8_t gray = (image->pixels[i][j].red + image->pixels[i][j].green + image->pixels[i][j].blue) / 3;
            uint8_t sepia_red = gray + 40;
            uint8_t sepia_green = gray + 20;
            uint8_t sepia_blue = gray;

            // Clamp the values to between 0 and 255
            if (sepia_red > 255) {
                sepia_red = 255;
            }
            if (sepia_green > 255) {
                sepia_green = 255;
            }
            if (sepia_blue > 255) {
                sepia_blue = 255;
            }

            // Set the new color values for the pixel
            image->pixels[i][j].red = sepia_red;
            image->pixels[i][j].green = sepia_green;
            image->pixels[i][j].blue = sepia_blue;
        }
    }
}

int main() {
    // Allocate memory for the filename and command strings
    char* filename = (char*) malloc(sizeof(char) * MAX_FILENAME_LENGTH);
    char* command = (char*) malloc(sizeof(char) * MAX_COMMAND_LENGTH);

    // Loop until the user enters "exit"
    while (strcmp(command, "exit") != 0) {
        // Ask the user for a filename and command
        printf("Enter a filename (or 'exit' to quit):\n");
        scanf("%s", filename);

        if (strcmp(filename, "exit") != 0) {
            printf("Enter a command:\n");
            scanf("%s", command);

            // Read the image from the file
            Image* image = read_image_from_file(filename);

            // Apply the appropriate filter based on the command
            if (strcmp(command, "grayscale") == 0) {
                grayscale_filter(image);
            }
            else if (strcmp(command, "invert") == 0) {
                invert_filter(image);
            }
            else if (strcmp(command, "sepia") == 0) {
                sepia_filter(image);
            }
            else {
                printf("Command not recognized\n");
            }

            // Write the modified image to a new file
            char* output_filename = (char*) malloc(sizeof(char) * (strlen(filename) + 5));
            strcpy(output_filename, "new_");
            strcat(output_filename, filename);
            write_image_to_file(image, output_filename);

            // Free the image and output filename memory
            destroy_image(image);
            free(output_filename);
        }
    }

    // Free the filename and command memory
    free(filename);
    free(command);

    return 0;
}