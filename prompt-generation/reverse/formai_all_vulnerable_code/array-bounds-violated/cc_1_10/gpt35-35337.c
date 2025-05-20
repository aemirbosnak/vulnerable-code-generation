//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

void print_ascii_art(char* image_path, int width, int height) {
    FILE* fptr = fopen(image_path, "rb");
    if (fptr == NULL) {
        printf("Error opening file.");
        return;
    }

    // Allocate memory to store image data
    unsigned char* img_data = (unsigned char*)malloc(width * height);

    // Read image data from file
    fread(img_data, sizeof(unsigned char), width * height, fptr);

    // Close file pointer
    fclose(fptr);

    // Map pixel values to ASCII characters
    char ascii_chars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};
    int num_chars = sizeof(ascii_chars)/sizeof(ascii_chars[0]);

    // Print ASCII art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixel_val = *(img_data + i * width + j);

            // Map pixel value to ASCII character index
            int char_index = (pixel_val * num_chars) / 255;

            // Print ASCII character
            printf("%c", ascii_chars[char_index]);
        }
        printf("\n");
    }

    // Free memory
    free(img_data);
}

int main() {
    char* image_path = "image.bin";
    int width = 20;
    int height = 10;

    print_ascii_art(image_path, width, height);

    return 0;
}