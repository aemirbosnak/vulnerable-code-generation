//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

int main() {
    // Get the input image from the user.
    char input_image_name[MAX_SIZE];
    printf("Enter the name of the input image: ");
    scanf("%s", input_image_name);

    // Open the input image file.
    FILE *input_image_file = fopen(input_image_name, "rb");
    if (input_image_file == NULL) {
        printf("Error opening the input image file.\n");
        return 1;
    }

    // Get the dimensions of the input image.
    int width, height;
    fscanf(input_image_file, "%d %d\n", &width, &height);

    // Create a 2D array to store the pixels of the input image.
    pixel **input_image = malloc(sizeof(pixel *) * height);
    for (int i = 0; i < height; i++) {
        input_image[i] = malloc(sizeof(pixel) * width);
    }

    // Read the pixels of the input image into the 2D array.
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fread(&input_image[i][j], sizeof(pixel), 1, input_image_file);
        }
    }

    // Close the input image file.
    fclose(input_image_file);

    // Get the secret message from the user.
    char secret_message[MAX_SIZE];
    printf("Enter the secret message: ");
    scanf(" %[^\n]", secret_message);

    // Convert the secret message to a binary string.
    char *binary_secret_message = malloc(sizeof(char) * (strlen(secret_message) * 8 + 1));
    int binary_secret_message_index = 0;
    for (int i = 0; i < strlen(secret_message); i++) {
        for (int j = 7; j >= 0; j--) {
            binary_secret_message[binary_secret_message_index++] = (secret_message[i] >> j) & 1 ? '1' : '0';
        }
    }
    binary_secret_message[binary_secret_message_index] = '\0';

    // Embed the secret message into the input image.
    int secret_message_index = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Get the least significant bit of each color channel of the pixel.
            unsigned char red_lsb = input_image[i][j].red & 1;
            unsigned char green_lsb = input_image[i][j].green & 1;
            unsigned char blue_lsb = input_image[i][j].blue & 1;

            // Set the least significant bit of each color channel of the pixel to the corresponding bit of the secret message.
            input_image[i][j].red = (input_image[i][j].red & ~1) | (binary_secret_message[secret_message_index++] == '1' ? 1 : 0);
            input_image[i][j].green = (input_image[i][j].green & ~1) | (binary_secret_message[secret_message_index++] == '1' ? 1 : 0);
            input_image[i][j].blue = (input_image[i][j].blue & ~1) | (binary_secret_message[secret_message_index++] == '1' ? 1 : 0);
        }
    }

    // Get the output image name from the user.
    char output_image_name[MAX_SIZE];
    printf("Enter the name of the output image: ");
    scanf("%s", output_image_name);

    // Open the output image file.
    FILE *output_image_file = fopen(output_image_name, "wb");
    if (output_image_file == NULL) {
        printf("Error opening the output image file.\n");
        return 1;
    }

    // Write the dimensions of the output image to the file.
    fprintf(output_image_file, "%d %d\n", width, height);

    // Write the pixels of the output image to the file.
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fwrite(&input_image[i][j], sizeof(pixel), 1, output_image_file);
        }
    }

    // Close the output image file.
    fclose(output_image_file);

    // Free the memory allocated for the input image.
    for (int i = 0; i < height; i++) {
        free(input_image[i]);
    }
    free(input_image);

    // Free the memory allocated for the binary secret message.
    free(binary_secret_message);

    return 0;
}