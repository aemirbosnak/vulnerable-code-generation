//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// function to convert pixel value to ASCII character
char pixel_to_ascii(unsigned char pixel) {
    char ascii_char;
    // define ASCII characters from darkest to lightest
    char ascii_chars[] = {'#', 'M', 'X', 'D', 'O', '0'};
    // determine which ASCII character to use based on pixel value
    if (pixel < 25) {
        ascii_char = ascii_chars[0];
    }
    else if (pixel < 51) {
        ascii_char = ascii_chars[1];
    }
    else if (pixel < 102) {
        ascii_char = ascii_chars[2];
    }
    else if (pixel < 153) {
        ascii_char = ascii_chars[3];
    }
    else if (pixel < 204) {
        ascii_char = ascii_chars[4];
    }
    else {
        ascii_char = ascii_chars[5];
    }
    return ascii_char;
}

int main() {
    // open image file for reading
    FILE* image_file = fopen("image.bin", "rb");
    // check if file was opened successfully
    if (!image_file) {
        printf("Error opening image file\n");
        exit(1);
    }
    // read image dimensions from file
    int width, height;
    fread(&width, sizeof(int), 1, image_file);
    fread(&height, sizeof(int), 1, image_file);
    // allocate memory for image data
    unsigned char* image_data = malloc(width * height);
    // read image data from file
    fread(image_data, sizeof(unsigned char), width * height, image_file);
    // close image file
    fclose(image_file);
    // convert image data to ASCII art and print to console
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            char ascii_char = pixel_to_ascii(*(image_data + i * width + j));
            printf("%c", ascii_char);
        }
        printf("\n");
    }
    // free allocated memory
    free(image_data);
    return 0;
}