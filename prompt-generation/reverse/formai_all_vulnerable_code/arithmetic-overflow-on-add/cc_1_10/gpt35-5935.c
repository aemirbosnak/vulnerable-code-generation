//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void convert(char* image_path);

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Error! Usage: %s [image_path]", argv[0]);
        exit(EXIT_FAILURE);
    }
    convert(argv[1]);
    return EXIT_SUCCESS;
}

void convert(char* image_path) {
    int width, height, depth;
    FILE* image = fopen(image_path, "rb");
    if(image == NULL) {
        printf("Error! Unable to open the image file.");
        exit(EXIT_FAILURE);
    }
    char ascii_scale[] = " .:-=+*#%@";
    fseek(image, 0x12, SEEK_SET);
    fread(&width, sizeof(width), 1, image);
    fread(&height, sizeof(height), 1, image);
    fseek(image, 0x16, SEEK_SET);
    fread(&depth, sizeof(depth), 1, image);
    printf("Image information: Width=%d, Height=%d, Depth=%d\n", width, height, depth);
    if(depth != 24) {
        printf("Error! Invalid image depth. Only 24-bit depth images are supported.");
        exit(EXIT_FAILURE);
    }
    unsigned char pixel[3];
    int row_size = (width * 3 + 3) & (~3);
    char* row_buffer = (char*) malloc(row_size);
    fseek(image, 54, SEEK_SET);
    for(int y = height - 1; y >= 0; --y) {
        int result = fread(row_buffer, row_size, 1, image);
        if(result != 1) {
            printf("Error! Unable to read the row %d from the image file.", y);
            exit(EXIT_FAILURE);
        }
        for(int x = 0; x < width; ++x) {
            pixel[2] = row_buffer[x*3+2];
            pixel[1] = row_buffer[x*3+1];
            pixel[0] = row_buffer[x*3];
            int gray = 0.30*pixel[0] + 0.59*pixel[1] + 0.11*pixel[2];
            int index = gray*10/256;
            printf("%c", ascii_scale[index]);
        }
        printf("\n");
    }
    fclose(image);
    free(row_buffer);
}