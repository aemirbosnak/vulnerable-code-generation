//FormAI DATASET v1.0 Category: Image Steganography ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the message to be hidden
#define MAX_MSG_SIZE 1000

int main() {
    // Read in the cover image file path and the message file path
    char cover_image_path[100], message_file_path[100];
    printf("Enter the cover image file path: ");
    scanf("%s", cover_image_path);
    printf("Enter the message file path: ");
    scanf("%s", message_file_path);

    // Open the cover image file in binary mode
    FILE *cover_image = fopen(cover_image_path, "rb");
    if (!cover_image) {
        printf("Error: could not open the cover image file.");
        return 1;
    }

    // Open the message file in binary mode
    FILE *message_file = fopen(message_file_path, "rb");
    if (!message_file) {
        printf("Error: could not open the message file.");
        return 1;
    }

    // Allocate memory for the message to be hidden
    char *message = malloc(MAX_MSG_SIZE * sizeof(char));
    if (!message) {
        printf("Error: memory allocation failed.");
        return 1;
    }

    // Read in the message to be hidden
    fgets(message, MAX_MSG_SIZE, message_file);

    // Get the length of the message
    int message_len = strlen(message);

    // Allocate memory for the image data
    unsigned char *image_data = malloc(MAX_MSG_SIZE * sizeof(unsigned char));
    if (!image_data) {
        printf("Error: memory allocation failed.");
        return 1;
    }

    // Read in the image data
    fread(image_data, sizeof(unsigned char), MAX_MSG_SIZE, cover_image);

    // Close the files
    fclose(cover_image);
    fclose(message_file);

    // Get the number of bytes of image data to be used for hiding the message
    int num_image_bytes = strlen(image_data) - (strlen(image_data) % 8);

    // Hide the message in the image data
    int i, j, k, l;
    for (i = 0, j = 0; i < num_image_bytes && j < message_len * 8; i += 8, j += 8) {
        for (k = 7, l = 0; k >= 0; k--, l++) {
            if (j + l < message_len * 8) {
                unsigned char c = message[(j / 8)] & (1 << l);
                image_data[i + k] = (image_data[i + k] & 0xFE) | (c >> l);
            }
        }
    }

    // Write the modified image data to a new file with '_hidden' appended to the name
    char new_image_path[100];
    strcpy(new_image_path, cover_image_path);
    strcat(new_image_path, "_hidden");
    FILE *new_image = fopen(new_image_path, "wb");
    fwrite(image_data, sizeof(unsigned char), num_image_bytes, new_image);
    fclose(new_image);

    // Free the allocated memory
    free(message);
    free(image_data);

    printf("Message hidden successfully!\n");
    printf("New image file saved as: %s", new_image_path);

    return 0;
}