//Code Llama-13B DATASET v1.0 Category: Image Steganography ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1000000

void hide_message(char* message, char* image_path) {
    FILE* image_file = fopen(image_path, "r");
    if (!image_file) {
        printf("Error: Could not open image file\n");
        return;
    }

    char image_buffer[MAX_IMAGE_SIZE];
    fread(image_buffer, 1, MAX_IMAGE_SIZE, image_file);
    fclose(image_file);

    int message_length = strlen(message);
    int image_length = strlen(image_buffer);

    int offset = 0;
    for (int i = 0; i < message_length; i++) {
        image_buffer[offset] = message[i];
        offset += 3;
    }

    image_file = fopen(image_path, "w");
    fwrite(image_buffer, 1, image_length, image_file);
    fclose(image_file);
}

void reveal_message(char* image_path) {
    FILE* image_file = fopen(image_path, "r");
    if (!image_file) {
        printf("Error: Could not open image file\n");
        return;
    }

    char image_buffer[MAX_IMAGE_SIZE];
    fread(image_buffer, 1, MAX_IMAGE_SIZE, image_file);
    fclose(image_file);

    int image_length = strlen(image_buffer);

    char message[image_length / 3];
    int offset = 0;
    for (int i = 0; i < image_length; i += 3) {
        message[offset] = image_buffer[i];
        offset++;
    }

    printf("Message: %s\n", message);
}

int main() {
    char* message = "Hello, world!";
    char* image_path = "image.jpg";

    hide_message(message, image_path);
    reveal_message(image_path);

    return 0;
}