//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 4096

// Function to hide a message in an image
void hide_message(char* img_data, char* secret_message, int img_size, int msg_len) {
    // Calculate the message size in bytes
    int msg_size = strlen(secret_message) + 1;

    // Iterate through the image data
    for (int i = 0; i < img_size; i++) {
        // Find a suitable position to hide the message
        int j = 0;
        while (j < msg_size && i + j >= img_size) {
            j++;
        }

        // Replace the pixel value with the corresponding ASCII value of the message character
        int ascii_value = secret_message[j - 1];
        char pixel_value = img_data[i + j];
        img_data[i + j] = (ascii_value << 4) | (pixel_value & 0xF);
    }
}

int main() {
    char* img_data = NULL; // Pointer to the image data
    int img_size = 0; // Image size in bytes
    int msg_len = 0; // Length of the secret message

    // Load the image data
    printf("Enter the image data: ");
    fflush(stdout);
    fgets(img_data, MAX_SIZE, stdin);
    img_size = strlen(img_data);

    // Get the length of the secret message
    printf("Enter the length of the secret message: ");
    fflush(stdout);
    fgets(img_data, MAX_SIZE, stdin);
    sscanf(img_data, "%d", &msg_len);

    // Hide the message in the image
    hide_message(img_data, "This is a secret message!", img_size, msg_len);

    // Print the modified image data
    printf("Modified image data: %s\n", img_data);

    return 0;
}