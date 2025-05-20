//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

char coverage[] = "@#%xo;:. ";

int main() {
    // Load Image file
    char file_path[100];
    printf("Please enter the file path of the image: ");
    scanf("%s", file_path);
    FILE *img_file = fopen(file_path, "rb");
    
    // Check if file exists
    if(img_file == NULL) {
        fprintf(stderr, "Error: File not found");
        return 1;
    }
    
    // Read image header
    char img_header[54];
    fread(img_header, sizeof(unsigned char), 54, img_file);
    
    // Parse image width, height and color depth from header data
    int width = *(int*)&img_header[18];
    int height = *(int*)&img_header[22];
    int color_depth = *(int*)&img_header[28];
    
    // Check if image is in 24-bit BMP format
    if(color_depth != 24) {
        fprintf(stderr, "Error: Only 24-bit BMP format is supported.");
        return 1;
    }
    
    // Calculate padding of the image rows
    int padding = (4 - (width * 3) % 4) % 4;
    
    // Allocate memory to store image data
    unsigned char *img_data = (unsigned char*)malloc((width * height) * sizeof(unsigned char));
    
    // Read image data into memory
    int i, j;
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            unsigned char pixel[3];
            fread(pixel, sizeof(unsigned char), 3, img_file);
            int gray_value = pixel[0] * 0.3 + pixel[1] * 0.59 + pixel[2] * 0.11;
            int index = (i * width) + j;
            img_data[index] = gray_value;
        }
        fseek(img_file, padding, SEEK_CUR);
    }
    
    // Print ASCII Art
    printf("\n");
    for(i = 0; i < height; i += 2) {
        for(j = 0; j < width; j++) {
            int index1 = (i * width) + j;
            int index2 = ((i + 1) * width) + j;
            int avg_value = (img_data[index1] + img_data[index2]) / 2;
            int coverage_index = (int)((avg_value * 9) / 255);
            printf("%c", coverage[coverage_index]);
        }
        printf("\n");
    }

    // Free allocated memory and close file
    free(img_data);
    fclose(img_file);
    
    return 0;
}