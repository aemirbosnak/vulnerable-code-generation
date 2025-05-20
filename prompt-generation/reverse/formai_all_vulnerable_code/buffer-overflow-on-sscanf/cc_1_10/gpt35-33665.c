//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXEL_VALUE 255
#define MAX_LINE_LENGTH 200

void convertImageToASCII(char* image_path) {
    FILE* fp;
    char line[MAX_LINE_LENGTH];
    int width, height, pixel_value;
    
    fp = fopen(image_path, "r");
    if(fp == NULL) {
        printf("Error opening file: %s\n", image_path);
        exit(1);
    }

    // Read and ignore the first line which contains the image format
    fgets(line, MAX_LINE_LENGTH, fp);

    // Read the image dimensions
    fgets(line, MAX_LINE_LENGTH, fp);
    sscanf(line, "%d %d\n", &width, &height);

    // Read the maximum pixel value
    fgets(line, MAX_LINE_LENGTH, fp);
    sscanf(line, "%d\n", &pixel_value);

    // Compute the pixel size
    int pixel_size = MAX_PIXEL_VALUE / 10;

    // Process each row of pixels in the image
    while(fgets(line, MAX_LINE_LENGTH, fp)) {
        for(int i = 0; i < width; i++) {
            int pixel = (int) line[i];
            int ascii_val = pixel / pixel_size;
            if(ascii_val >= 10) {
                printf("#");
            } else {
                printf("%d", ascii_val);
            }
        }
        printf("\n");
    }

    fclose(fp);
}

int main(int argc, char **argv) {
    if(argc < 2) {
        printf("Usage: %s <image_path>\n", argv[0]);
        exit(1);
    }

    char* image_path = argv[1];
    convertImageToASCII(image_path);

    return 0;
}