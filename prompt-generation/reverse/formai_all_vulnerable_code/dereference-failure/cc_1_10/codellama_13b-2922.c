//Code Llama-13B DATASET v1.0 Category: Image Steganography ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_MSG_SIZE 1024
#define MAX_KEY_SIZE 1024
#define MAX_IMAGE_SIZE 1024*1024*1024

// Function to encode a message in an image
void encode_image(char* msg, char* key, char* image_path) {
    // Read the image file
    FILE* fp = fopen(image_path, "r");
    if (!fp) {
        printf("Error: Could not open image file.\n");
        return;
    }
    char* image = malloc(MAX_IMAGE_SIZE);
    fread(image, 1, MAX_IMAGE_SIZE, fp);
    fclose(fp);

    // Generate a random key
    srand(time(NULL));
    char* key_buf = malloc(MAX_KEY_SIZE);
    for (int i = 0; i < MAX_KEY_SIZE; i++) {
        key_buf[i] = (char) (rand() % 256);
    }

    // Encode the message in the image
    int msg_len = strlen(msg);
    for (int i = 0; i < msg_len; i++) {
        image[i] = (char) (image[i] ^ key_buf[i % MAX_KEY_SIZE]);
    }

    // Write the encoded image to a file
    fp = fopen("encoded.png", "w");
    fwrite(image, 1, MAX_IMAGE_SIZE, fp);
    fclose(fp);

    // Free memory
    free(image);
    free(key_buf);
}

// Function to decode an image
void decode_image(char* key, char* image_path) {
    // Read the encoded image file
    FILE* fp = fopen(image_path, "r");
    if (!fp) {
        printf("Error: Could not open image file.\n");
        return;
    }
    char* image = malloc(MAX_IMAGE_SIZE);
    fread(image, 1, MAX_IMAGE_SIZE, fp);
    fclose(fp);

    // Generate a random key
    srand(time(NULL));
    char* key_buf = malloc(MAX_KEY_SIZE);
    for (int i = 0; i < MAX_KEY_SIZE; i++) {
        key_buf[i] = (char) (rand() % 256);
    }

    // Decode the message in the image
    char* msg = malloc(MAX_MSG_SIZE);
    int msg_len = 0;
    for (int i = 0; i < MAX_IMAGE_SIZE; i++) {
        msg[i] = (char) (image[i] ^ key_buf[i % MAX_KEY_SIZE]);
        if (msg[i] == '\0') {
            break;
        }
        msg_len++;
    }

    // Print the decoded message
    printf("Decoded message: %s\n", msg);

    // Free memory
    free(image);
    free(key_buf);
    free(msg);
}

int main() {
    // Encode a message in an image
    char* msg = "This is a secret message.";
    char* key = "secret_key";
    char* image_path = "image.png";
    encode_image(msg, key, image_path);

    // Decode the message from the image
    decode_image(key, image_path);

    return 0;
}