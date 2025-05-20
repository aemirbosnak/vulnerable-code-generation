//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 200
#define MAX_HEIGHT 200

char ascii_chars[] = {'@', '#', 'S', '%', '?', '*', '+', ';', ':', ',', '.'};

// Function to convert color image to grayscale
void grayscale(unsigned char *image, int width, int height) {
    int i, j;
    unsigned char R, G, B, gray;
    for(i=0; i<height; i++) {
        for(j=0; j<width; j++) {
            R = *(image + (i*width + j)*3);
            G = *(image + (i*width + j)*3 + 1);
            B = *(image + (i*width + j)*3 + 2);
            gray = 0.2126*R + 0.7152*G + 0.0722*B;
            *(image + (i*width + j)*3) = gray;
            *(image + (i*width + j)*3 + 1) = gray;
            *(image + (i*width + j)*3 + 2) = gray;
        }
    }
}

// Function to map grayscale pixel values to ASCII characters
char map_pixel_to_ascii(unsigned char pixel_value) {
    int num_chars = sizeof(ascii_chars)/sizeof(char);
    int index = (((int) pixel_value)*num_chars)/256;
    return ascii_chars[index];
}

// Function to convert grayscale image to ASCII art
void ascii_art(unsigned char *image, int width, int height) {
    int i, j;
    char ascii_image[MAX_HEIGHT][MAX_WIDTH];
    for(i=0; i<height; i++) {
        for(j=0; j<width; j++) {
            ascii_image[i][j] = map_pixel_to_ascii(*(image + i*width + j));
        }
    }
    for(i=0; i<height; i++) {
        for(j=0; j<width; j++) {
            printf("%c", ascii_image[i][j]);
        }
        printf("\n");
    }
}

// Function to read image file and return pixel data in RGB format
unsigned char *read_image(char *filename, int *width, int *height) {
    FILE *fp;
    unsigned char *image;
    char magic_num[3];
    int maxval;
    fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: Unable to open file %s.\n", filename);
        exit(1);
    }
    fscanf(fp, "%s\n%d %d\n%d\n", magic_num, width, height, &maxval);
    if (strcmp(magic_num, "P6") != 0 || maxval != 255) {
        printf("Error: Invalid image format. Only P6 format with max value 255 is supported.\n");
        exit(1);
    }
    image = (unsigned char *) malloc((*width)*(*height)*3);
    fread(image, 3*(*width), *height, fp);
    fclose(fp);
    return image;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Error: Usage: ./ascii_art_converter <image_file>\n");
        exit(1);
    }
    int width, height;
    unsigned char *image = read_image(argv[1], &width, &height);
    grayscale(image, width, height);
    ascii_art(image, width, height);
    free(image);
    return 0;
}