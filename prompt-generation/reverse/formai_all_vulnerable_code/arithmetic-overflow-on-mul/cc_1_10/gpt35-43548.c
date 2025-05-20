//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXEL_VALUE 255
#define MAX_ASCII_VALUE 255

void ConvertImageToAscii(const unsigned char *image_data, const int width, const int height)
{
    const char ascii_chars[] = {' ', '.', ',', ':', ';', 'i', 'I', 'c', 'C', '8', '?', '|', '(', '[', '}', '@', '*', 'o', 'O', '0', 'X', '#'};
    const int num_ascii_chars = sizeof(ascii_chars) / sizeof(char);
    const int ascii_range = MAX_ASCII_VALUE + 1;
    const int pixel_range = MAX_PIXEL_VALUE + 1;

    unsigned char *gray_data = (unsigned char *) malloc(width * height * sizeof(unsigned char));
    memset(gray_data, 0, width * height * sizeof(unsigned char));

    for(int i = 0; i < width * height * 3; i += 3) {
        int gray_value = (int)(0.2126 * image_data[i] + 0.7152 * image_data[i + 1] + 0.0722 * image_data[i + 2]);
        int pixel_index = gray_value * ascii_range / pixel_range;
        if(pixel_index >= ascii_range) {
            pixel_index = ascii_range - 1;
        }
        gray_data[i / 3] = ascii_chars[pixel_index];
    }

    for(int i = 0; i < height; ++i) {
        for(int j = 0; j < width; ++j) {
            printf("%c", gray_data[i * width + j]);
        }
        printf("\n");
    }

    free(gray_data);
}

int main(int argc, char *argv[])
{
    if(argc != 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return -1;
    }

    FILE *file = fopen(argv[1], "rb");
    if(!file) {
        printf("Error: Cannot open image file: %s\n", argv[1]);
        return -1;
    }

    fseek(file, 0L, SEEK_END);
    long image_size = ftell(file);
    rewind(file);

    unsigned char *image_data = (unsigned char *)malloc(image_size * sizeof(unsigned char));
    fread(image_data, sizeof(unsigned char), image_size, file);
    fclose(file);

    int width, height;
    sscanf(argv[1], "%dx%d", &width, &height);

    printf("Converting %s to ASCII Art...\n", argv[1]);

    ConvertImageToAscii(image_data, width, height);

    free(image_data);

    return 0;
}