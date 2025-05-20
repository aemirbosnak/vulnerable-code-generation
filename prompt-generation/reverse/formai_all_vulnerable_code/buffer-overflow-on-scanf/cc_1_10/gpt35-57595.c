//FormAI DATASET v1.0 Category: Image Editor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100
#define MAX_COMMAND_LENGTH 10

// Function prototypes
void load_image(unsigned char **image, int *width, int *height, char *file_name);
void save_image(unsigned char *image, int width, int height, char *file_name);
void grayscale(unsigned char *image, int width, int height);
void invert_colors(unsigned char *image, int width, int height);
void pixelate(unsigned char *image, int width, int height);

// Main function
int main() {

    // Initialize variables
    unsigned char *image = NULL;
    int width = 0, height = 0;
    char file_name[MAX_FILE_NAME];
    char command[MAX_COMMAND_LENGTH];

    // Load the image
    printf("Enter the name of the input file: ");
    scanf("%s", file_name);
    load_image(&image, &width, &height, file_name);

    // Start the editor loop
    while (1) {

        // Print menu and get user command
        printf("Menu:\n");
        printf("  g - Grayscale\n");
        printf("  i - Invert colors\n");
        printf("  p - Pixelate\n");
        printf("  s - Save image\n");
        printf("  q - Quit\n");
        printf("Enter a command: ");
        scanf("%s", command);

        // Process the command
        if (strcmp(command, "g") == 0) {
            grayscale(image, width, height);
            printf("Grayscale done.\n");
        }
        else if (strcmp(command, "i") == 0) {
            invert_colors(image, width, height);
            printf("Invert colors done.\n");
        }
        else if (strcmp(command, "p") == 0) {
            pixelate(image, width, height);
            printf("Pixelate done.\n");
        }
        else if (strcmp(command, "s") == 0) {
            printf("Enter the name of the output file: ");
            scanf("%s", file_name);
            save_image(image, width, height, file_name);
            printf("Image saved.\n");
        }
        else if (strcmp(command, "q") == 0) {
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Invalid command.\n");
        }
    }

    // Free memory
    free(image);

    return 0;
}

// Load an image from a file
void load_image(unsigned char **image, int *width, int *height, char *file_name) {
    FILE *fp = fopen(file_name, "rb");

    // Read width and height
    fread(width, sizeof(int), 1, fp);
    fread(height, sizeof(int), 1, fp);

    // Allocate memory for the image
    *image = (unsigned char*) malloc((*width) * (*height) * sizeof(unsigned char));

    // Read the image data
    fread(*image, sizeof(unsigned char), (*width) * (*height), fp);

    // Close the file
    fclose(fp);
}

// Save an image to a file
void save_image(unsigned char *image, int width, int height, char *file_name) {
    FILE *fp = fopen(file_name, "wb");

    // Write width and height
    fwrite(&width, sizeof(int), 1, fp);
    fwrite(&height, sizeof(int), 1, fp);

    // Write the image data
    fwrite(image, sizeof(unsigned char), width * height, fp);

    // Close the file
    fclose(fp);
}

// Grayscale the image
void grayscale(unsigned char *image, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        int gray_value = 0.3 * image[3*i] + 0.59 * image[3*i+1] + 0.11 * image[3*i+2];
        image[3*i] = gray_value;
        image[3*i+1] = gray_value;
        image[3*i+2] = gray_value;
    }
}

// Invert the colors of the image
void invert_colors(unsigned char *image, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        image[3*i] = 255 - image[3*i];
        image[3*i+1] = 255 - image[3*i+1];
        image[3*i+2] = 255 - image[3*i+2];
    }
}

// Pixelate the image
void pixelate(unsigned char *image, int width, int height) {
    for (int i = 0; i < width * height; i += 4) {
        int pixel_value = (image[i] + image[i+1] + image[i+2] + image[i+3]) / 4;
        image[i] = pixel_value;
        image[i+1] = pixel_value;
        image[i+2] = pixel_value;
        image[i+3] = pixel_value;
    }
}