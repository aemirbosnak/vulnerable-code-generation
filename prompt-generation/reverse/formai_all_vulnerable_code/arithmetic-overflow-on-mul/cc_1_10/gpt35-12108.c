//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: innovative
#include<stdio.h>
#include<stdlib.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 40
#define SCALE_FACTOR 3

// Function to map gray scale values to ASCII characters
char* mapToChar(int val) {
    static char c[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};
    return &c[(int)(val/25)];
}

int main() {
    // Open the image file in read-mode
    FILE *fp = fopen("image.jpg", "rb");
    if(fp == NULL) {
        printf("Error opening file");
        exit(1);
    }

    // Read the image header to get the width and height
    unsigned char buffer[54];
    fread(buffer, sizeof(unsigned char), 54, fp);
    int width = *(int*)&buffer[18];
    int height = *(int*)&buffer[22];
    
    // Calculate scaling factor based on image size and desired output size
    int width_scale = width/(MAX_WIDTH/SCALE_FACTOR);
    int height_scale = height/(MAX_HEIGHT/SCALE_FACTOR);

    // Get buffer size for the entire image
    int padding = (4 - (width * 3) % 4) % 4;
    int size = (width * 3 + padding) * height;
    
    // Create buffer to hold the image data
    unsigned char* img_buffer = (unsigned char*) malloc(size);
    
    // Read image data into the buffer
    fread(img_buffer, sizeof(unsigned char), size, fp);
    fclose(fp);
    
    // Print ASCII art based on the gray scale value of each pixel
    for(int i = 0; i < height; i+=height_scale) {
        for(int j = 0; j < width; j+=width_scale) {
            int val = (int) (0.2126*img_buffer[i*width*3+j*3+2] + 0.7152*img_buffer[i*width*3+j*3+1] + 0.0722*img_buffer[i*width*3+j*3]);
            printf("%s", mapToChar(val));
        }
        printf("\n");
    }
    
    return 0;
}