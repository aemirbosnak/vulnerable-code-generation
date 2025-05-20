//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define HEADER_SIZE 54

typedef unsigned char byte;

void flip_image(byte* image, int width, int height) {
    byte* temp = malloc(width * sizeof(byte));
    
    for(int y = 0; y < height / 2; y++) {
        int y_offset = y * width;
        int y_mirror_offset = (height - y - 1) * width;
        
        memcpy(temp, &image[y_offset], width);
        memcpy(&image[y_offset], &image[y_mirror_offset], width);
        memcpy(&image[y_mirror_offset], temp, width);
    }
    
    free(temp);
}

void change_brightness(byte* image, int width, int height, int brightness) {
    for(int i = 0; i < width * height * 3; i++) {
        int new_value = image[i] + brightness;
        image[i] = new_value > 255 ? 255 : new_value < 0 ? 0 : new_value;
    }
}

void change_contrast(byte* image, int width, int height, int contrast) {
    double factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    
    for(int i = 0; i < width * height * 3; i++) {
        int new_value = (int)(factor * (image[i] - 128) + 128);
        image[i] = new_value > 255 ? 255 : new_value < 0 ? 0 : new_value;
    }
}

int main() {
    // Get filename from user
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter file name: ");
    scanf("%s", filename);
    
    // Open image file
    FILE* infile = fopen(filename, "rb");
    if(infile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    // Read header and get image dimensions
    byte header[HEADER_SIZE];
    fread(header, sizeof(byte), HEADER_SIZE, infile);
    
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    
    // Allocate memory for image
    byte* image = malloc(width * height * 3 * sizeof(byte));
    fread(image, sizeof(byte), width * height * 3, infile);
    
    // Close input file
    fclose(infile);
    
    // Flip image
    flip_image(image, width, height);
    
    // Change brightness and contrast
    change_brightness(image, width, height, 50);
    change_contrast(image, width, height, 50);
    
    // Open output file and write header
    char* outfile_name = "processed.bmp";
    FILE* outfile = fopen(outfile_name, "wb");
    
    fwrite(header, sizeof(byte), HEADER_SIZE, outfile);
    
    // Write image data and close output file
    fwrite(image, sizeof(byte), width * height * 3, outfile);
    fclose(outfile);
    
    // Free memory
    free(image);
    
    printf("Image processing complete. Saved to \"%s\".\n", outfile_name);
    
    return 0;
}