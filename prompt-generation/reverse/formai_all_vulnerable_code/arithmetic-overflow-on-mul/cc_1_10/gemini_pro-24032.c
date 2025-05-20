//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 512

typedef struct {
    unsigned char r, g, b;
} pixel;

typedef struct {
    int width, height;
    pixel *data;
} image;

int main() {
    // Load the image
    image img;
    FILE *fp = fopen("image.bmp", "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open image file\n");
        return EXIT_FAILURE;
    }
    fread(&img.width, sizeof(int), 1, fp);
    fread(&img.height, sizeof(int), 1, fp);
    img.data = malloc(img.width * img.height * sizeof(pixel));
    fread(img.data, sizeof(pixel), img.width * img.height, fp);
    fclose(fp);

    // Read the message
    char *message = malloc(MAX_SIZE);
    printf("Enter the message to hide: ");
    fgets(message, MAX_SIZE, stdin);
    
    // Hide the message in the image
    int pos = 0;
    for (int i = 0; i < img.width * img.height; i++) {
        // Get the least significant bit of each color component
        int r_lsb = img.data[i].r & 1;
        int g_lsb = img.data[i].g & 1;
        int b_lsb = img.data[i].b & 1;
        
        // Set the least significant bit of each color component to the message bit
        img.data[i].r = (img.data[i].r & ~1) | ((message[pos] >> 2) & 1);
        img.data[i].g = (img.data[i].g & ~1) | ((message[pos] >> 1) & 1);
        img.data[i].b = (img.data[i].b & ~1) | (message[pos] & 1);
        
        pos++;
        if (message[pos] == '\0') {
            break;
        }
    }

    // Save the modified image
    fp = fopen("output_image.bmp", "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open output image file\n");
        return EXIT_FAILURE;
    }
    fwrite(&img.width, sizeof(int), 1, fp);
    fwrite(&img.height, sizeof(int), 1, fp);
    fwrite(img.data, sizeof(pixel), img.width * img.height, fp);
    fclose(fp);
    
    // Free the memory
    free(img.data);
    free(message);

    return EXIT_SUCCESS;
}