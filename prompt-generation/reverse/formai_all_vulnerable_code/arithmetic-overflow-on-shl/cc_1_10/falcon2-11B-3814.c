//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

// Function to hash a string using SHA-256
void hash_string(char* str, unsigned char* hash) {
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, str, strlen(str));
    SHA256_Final(hash, &ctx);
}

// Function to embed a message in an image
void watermark_image(char* image, char* message) {
    // Get image dimensions
    int width = 0;
    int height = 0;
    unsigned char* image_data = NULL;

    FILE* fp = fopen(image, "rb");
    if (fp == NULL) {
        perror("Failed to open image file");
        return;
    }

    fseek(fp, 0, SEEK_END);
    long length = ftell(fp);
    rewind(fp);

    image_data = malloc(length);
    if (image_data == NULL) {
        perror("Failed to allocate memory for image data");
        return;
    }

    fread(image_data, 1, length, fp);
    fclose(fp);

    width = image_data[0] + (image_data[1] << 8) + (image_data[2] << 16) + (image_data[3] << 24);
    height = image_data[4] + (image_data[5] << 8) + (image_data[6] << 16) + (image_data[7] << 24);

    unsigned char* hash = malloc(32);
    hash_string(message, hash);

    // Embed the hash as a comment in the image
    unsigned char* comment = malloc(strlen(image) + strlen(message) + 2);
    sprintf(comment, "%s%s%s", "-- ", hash, "\n");

    int i;
    for (i = 0; i < length; i++) {
        if (i < 4) {
            image_data[i] = comment[i];
        } else if (i < 8) {
            image_data[i] = comment[4];
        } else if (i < 12) {
            image_data[i] = comment[8];
        } else if (i < 16) {
            image_data[i] = comment[12];
        } else if (i < 20) {
            image_data[i] = comment[16];
        } else if (i < 24) {
            image_data[i] = comment[20];
        } else if (i < 28) {
            image_data[i] = comment[24];
        } else if (i < 32) {
            image_data[i] = comment[28];
        } else {
            image_data[i] = comment[32];
        }
    }

    // Write the modified image back to the file
    fp = fopen(image, "wb");
    if (fp == NULL) {
        perror("Failed to open image file for writing");
        free(image_data);
        free(hash);
        free(comment);
        return;
    }

    fwrite(image_data, 1, length, fp);
    fclose(fp);

    free(image_data);
    free(hash);
    free(comment);
}

int main() {
    // Example usage
    char image[] = "example.png";
    char message[] = "Hello, world!";

    watermark_image(image, message);

    return 0;
}