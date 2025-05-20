//FormAI DATASET v1.0 Category: Image Steganography ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define HEADER_SIZE 54
#define BYTE_SIZE 8

int main(int argc, char *argv[]) {

    if (argc != 4) {
        printf("Usage: %s <input_image.bmp> <hidden_text.txt> <output_image.bmp>\n", argv[0]);
        return 1;
    }
    
    // Open input image file
    FILE *input_image = fopen(argv[1], "rb");
    if (input_image == NULL) {
        printf("Error opening input image file.\n");
        return 1;
    }
    
    // Open hidden text file
    FILE *hidden_text = fopen(argv[2], "r");
    if (hidden_text == NULL) {
        printf("Error opening hidden text file.\n");
        return 1;
    }
    
    // Open output image file
    FILE *output_image = fopen(argv[3], "wb");
    if (output_image == NULL) {
        printf("Error opening output image file.\n");
        return 1;
    }
    
    // Get width and height from input image file header
    int width, height;
    fseek(input_image, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, input_image);
    fread(&height, sizeof(int), 1, input_image);
    
    // Copy header from input image file to output image file
    fseek(input_image, 0, SEEK_SET);
    char header[HEADER_SIZE];
    fread(header, sizeof(char), HEADER_SIZE, input_image);
    fwrite(header, sizeof(char), HEADER_SIZE, output_image);
    
    // Write hidden text size to output image header
    char hidden_text_size[4];
    fseek(hidden_text, 0, SEEK_END);
    int size = ftell(hidden_text);
    rewind(hidden_text);
    sprintf(hidden_text_size, "%d", size);
    fseek(output_image, HEADER_SIZE - 4, SEEK_SET);
    fwrite(hidden_text_size, sizeof(char), 4, output_image);
    
    // Write hidden text to LSB of each pixel in output image
    int i, j, k;
    char byte, bit;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            for (k = 0; k < 3; k++) {
                if (fread(&byte, sizeof(char), 1, hidden_text) == 0) {
                    fclose(input_image);
                    fclose(hidden_text);
                    fclose(output_image);
                    printf("Hidden text file too large to fit in image.\n");
                    return 1;
                }
                for (int l = 0; l < BYTE_SIZE; l++) {
                    fread(&bit, sizeof(char), 1, input_image);
                    bit = (bit & 0xFE) | ((byte >> l) & 1);
                    fwrite(&bit, sizeof(char), 1, output_image);
                }
            }
        }
    }
    
    // Copy remaining pixels from input image to output image
    while (fread(&byte, sizeof(char), 1, input_image) != 0) {
        fwrite(&byte, sizeof(char), 1, output_image);
    }
    
    fclose(input_image);
    fclose(hidden_text);
    fclose(output_image);
    return 0;
}