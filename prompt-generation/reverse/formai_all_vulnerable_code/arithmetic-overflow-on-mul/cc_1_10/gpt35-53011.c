//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 45

char* IMG_FILE = "example_image.jpg"; // replace with the image you want to convert

// ASCII characters from darkest to lightest
char grayscale_lookup[] = {'@', '#', '8', '&', 'W', 'B', '%', 'M', '$', '7', 'X', 'm', 'o', 'O', '0', 'Q', 'L', 'C', 'J', 'U', 'Y', 'z', 's', 'a', 'u', 'n', 'x', 'v', 'r', 'j', 'f', 't', '/', '\\', '|', '(', ')', '1', '{', '}', '[', ']', '?', '-', ';', ':', ',', '.', ' '};

int main(void) {
    FILE *fp = fopen(IMG_FILE, "rb");
    if (!fp) {
        printf("Error opening file %s", IMG_FILE);
        return 1;
    }
    
    // get image metadata
    char image_type[2];
    fseek(fp, 0, SEEK_SET);
    fread(image_type, sizeof(image_type), 1, fp);
    image_type[2] = '\0';
    
    int width, height;
    fseek(fp, 16, SEEK_SET);
    fread(&width, sizeof(width), 1, fp);
    fread(&height, sizeof(height), 1, fp);
    
    // print some info about the image
    printf("Image type: %s\n", image_type);
    printf("Width: %d\n", width);
    printf("Height: %d\n", height);
    
    // allocate memory for pixel data
    int num_pixels = width * height;
    unsigned char *pixels = (unsigned char*)malloc(num_pixels * sizeof(unsigned char));
    
    // read pixel data from file
    if (strcmp(image_type, "BM") == 0) {
        // BMP image format
        int data_offset;
        fseek(fp, 10, SEEK_SET);
        fread(&data_offset, sizeof(data_offset), 1, fp);
        fseek(fp, data_offset, SEEK_SET);
        fread(pixels, sizeof(unsigned char), num_pixels, fp);
    } else {
        // unsupported image format
        printf("Unsupported image format");
        return 1;
    }
    
    fclose(fp);
    
    // create 2D array of brightness values
    int **brightness = (int**)malloc(height * sizeof(int*));
    for (int y = 0; y < height; y++) {
        brightness[y] = (int*)malloc(width * sizeof(int));
        for (int x = 0; x < width; x++) {
            brightness[y][x] = (int)pixels[(height-y-1)*width+x];
        }
    }
    
    // calculate block dimensions based on the aspect ratio
    int block_width = WIDTH / width;
    int block_height = HEIGHT / height;
    int block_size = fmin(block_width, block_height);
    
    // create ASCII art from brightness values
    char ascii_art[HEIGHT][WIDTH];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int grayscale_index = (int)(brightness[y][x] / 255.0 * (sizeof(grayscale_lookup)/sizeof(char)));
            ascii_art[y][x] = grayscale_lookup[grayscale_index];
        }
    }
    
    // print ASCII art to console
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            putchar(ascii_art[y/block_height][x/block_width]);
        }
        putchar('\n');
    }
    
    // free allocated memory
    for (int y = 0; y < height; y++) {
        free(brightness[y]);
    }
    free(brightness);
    free(pixels);
    
    return 0;
}