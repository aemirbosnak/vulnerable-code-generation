//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define ASCII_CHARS "@%#*+=-:. "

void print_usage() {
    printf("Usage: ascii_art_converter <input_image.pgm> <output_file.txt>\n");
}

unsigned char* read_pgm(const char* filename, int* width, int* height) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        return NULL;
    }
    
    char format[3];
    fscanf(file, "%s\n%d %d\n%d\n", format, width, height, NULL);
    if (strcmp(format, "P5") != 0) {
        fprintf(stderr, "Unsupported image format. Please use PGM (P5).\n");
        fclose(file);
        return NULL;
    }

    unsigned char* data = malloc(*width * *height);
    fread(data, 1, *width * *height, file);
    fclose(file);
    return data;
}

void write_ascii_art(const char* output_filename, const char* ascii_art, int width, int height) {
    FILE* file = fopen(output_filename, "w");
    if (!file) {
        perror("Could not open output file");
        return;
    }
    fwrite(ascii_art, sizeof(char), width * height, file);
    fclose(file);
}

char pixel_to_ascii(unsigned char pixel) {
    int ascii_index = (pixel * (sizeof(ASCII_CHARS) - 2)) / 255; // map pixel value to ASCII index
    return ASCII_CHARS[ascii_index];
}

void convert_image_to_ascii(unsigned char* image_data, char* ascii_art, int width, int height) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            unsigned char pixel = image_data[i * width + j];
            ascii_art[i * (width + 1) + j] = pixel_to_ascii(pixel);
        }
        ascii_art[i * (width + 1) + width] = '\n'; // new line at the end of each row
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        print_usage();
        return 1;
    }

    int width, height;
    unsigned char* image_data = read_pgm(argv[1], &width, &height);
    if (!image_data) {
        return 1;
    }

    char* ascii_art = malloc((width + 1) * height);
    convert_image_to_ascii(image_data, ascii_art, width, height);
    write_ascii_art(argv[2], ascii_art, width, height);

    free(image_data);
    free(ascii_art);

    printf("ASCII art created successfully and saved to %s!\n", argv[2]);
    return 0;
}