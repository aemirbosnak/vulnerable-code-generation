//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the maximum number of bits to modify
#define MAX_BITS 32

// Define the maximum number of bytes in the image
#define MAX_BYTES 1024

// Define the size of the image in pixels
#define IMAGE_SIZE 640

int main(int argc, char **argv) {
    // Check if the correct number of arguments is provided
    if (argc!= 2) {
        printf("Usage: %s image_file\n", argv[0]);
        return 1;
    }

    // Read the image file
    unsigned char *image = NULL;
    size_t image_size = 0;
    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }
    fseek(file, 0, SEEK_END);
    image_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    image = (unsigned char*)malloc(image_size);
    if (image == NULL) {
        printf("Error allocating memory for image\n");
        return 1;
    }
    fread(image, image_size, 1, file);
    fclose(file);

    // Perform the watermarking algorithm
    unsigned char *watermarked_image = NULL;
    size_t watermarked_image_size = 0;
    unsigned char *modified_image = NULL;
    size_t modified_image_size = 0;
    unsigned char *watermark = (unsigned char*)malloc(MAX_BITS);
    unsigned char *modified_watermark = (unsigned char*)malloc(MAX_BITS);
    if (watermark == NULL || modified_watermark == NULL) {
        printf("Error allocating memory for watermark\n");
        return 1;
    }

    // Extract the watermark from the secret message
    char *secret_message = (char*)malloc(MAX_BITS);
    if (secret_message == NULL) {
        printf("Error allocating memory for secret message\n");
        return 1;
    }
    int watermark_bits = 0;
    for (int i = 0; i < MAX_BITS; i++) {
        secret_message[i] = '0';
        watermark_bits += 1;
        if (watermark_bits == MAX_BITS) {
            break;
        }
    }
    for (int i = 0; i < MAX_BITS; i++) {
        watermark[i] = secret_message[i];
    }

    // Calculate the number of bytes to modify
    int bytes_to_modify = (image_size * IMAGE_SIZE) / 8;

    // Modify the least significant bits of the image
    for (int i = 0; i < bytes_to_modify; i++) {
        unsigned char *byte = (unsigned char*)image + i;
        unsigned char *modified_byte = (unsigned char*)malloc(MAX_BITS);
        if (modified_byte == NULL) {
            printf("Error allocating memory for modified byte\n");
            return 1;
        }
        for (int j = 0; j < MAX_BITS; j++) {
            modified_byte[j] = byte[j];
        }
        int j = 0;
        for (int k = 0; k < MAX_BITS; k++) {
            if (modified_byte[k]!= watermark[k]) {
                modified_byte[j] = (unsigned char)(byte[j] | 1);
                modified_byte[j + 1] = (unsigned char)(byte[j + 1] & ~1);
                j += 2;
            }
        }
        modified_image_size += (j * sizeof(unsigned char));
        modified_image = (unsigned char*)realloc(modified_image, modified_image_size);
        if (modified_image == NULL) {
            printf("Error allocating memory for modified image\n");
            return 1;
        }
        memcpy(modified_image + i * sizeof(unsigned char), modified_byte, j * sizeof(unsigned char));
        free(modified_byte);
    }

    // Create the watermarked image
    watermarked_image_size = image_size + modified_image_size;
    watermarked_image = (unsigned char*)malloc(watermarked_image_size);
    if (watermarked_image == NULL) {
        printf("Error allocating memory for watermarked image\n");
        return 1;
    }
    memcpy(watermarked_image, image, image_size);
    memcpy(watermarked_image + image_size, modified_image, modified_image_size);

    // Write the watermarked image to a file
    FILE *outfile = fopen(argv[2], "wb");
    if (outfile == NULL) {
        printf("Error opening output file: %s\n", argv[2]);
        return 1;
    }
    fwrite(watermarked_image, watermarked_image_size, 1, outfile);
    fclose(outfile);

    // Free memory
    free(watermarked_image);
    free(modified_image);
    free(modified_watermark);
    free(watermark);
    free(secret_message);
    free(image);

    return 0;
}