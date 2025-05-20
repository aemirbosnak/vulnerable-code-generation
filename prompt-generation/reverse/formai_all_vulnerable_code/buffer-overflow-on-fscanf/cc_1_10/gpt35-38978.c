//FormAI DATASET v1.0 Category: Image Editor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 256
#define MAX_PIXEL_SIZE 1024

typedef struct RGBPixel{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} RGBPixel;

int main(){
    char file_name[MAX_FILE_NAME_LEN];
    printf("Enter the image file name: ");
    fgets(file_name, MAX_FILE_NAME_LEN, stdin);

    // Removing the newline character from the file name
    file_name[strcspn(file_name, "\n")] = 0;

    FILE *input_file = fopen(file_name, "rb");
    if(input_file == NULL){
        printf("Error opening file!");
        return 1;
    }

    RGBPixel pixel_array[MAX_PIXEL_SIZE][MAX_PIXEL_SIZE];
    int width, height;

    // Reading the image header to extract the width and height
    fscanf(input_file, "P6 %d %d 255", &width, &height);

    // Reading the image pixel data into the 2D array
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            fread(&pixel_array[i][j], sizeof(RGBPixel), 1, input_file);
        }
    }

    fclose(input_file);

    // Applying a simple filter to invert the colors
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            pixel_array[i][j].red = 255 - pixel_array[i][j].red;
            pixel_array[i][j].green = 255 - pixel_array[i][j].green;
            pixel_array[i][j].blue = 255 - pixel_array[i][j].blue;
        }
    }

    // Writing the modified pixel data to a new file
    FILE *output_file = fopen("inverted_image.ppm", "wb");
    fprintf(output_file, "P6\n%d %d\n255\n", width, height);
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            fwrite(&pixel_array[i][j], sizeof(RGBPixel), 1, output_file);
        }
    }
    fclose(output_file);

    printf("Image saved successfully!");

    return 0;
}