//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void flip_image(char* input_file, char* output_file){

    FILE* input_image_file = fopen(input_file, "rb");
    if(input_image_file == NULL){
        printf("Error opening input image file.\n");
        return;
    }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, input_image_file);

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    int padding = 0;
    while ((width * 3 + padding) % 4 != 0){
        padding++;
    }
    int size = (width * 3 + padding) * height;

    unsigned char* image_data = (unsigned char*)malloc(sizeof(unsigned char) * size);
    fread(image_data, sizeof(unsigned char), size, input_image_file);

    for(int i=0; i<height/2; i++){
        int row_one = i * (width * 3 + padding);
        int row_two = (height - i - 1) * (width * 3 + padding);
        for(int j=0; j<width*3+padding; j++){
            unsigned char temp = image_data[row_one+j];
            image_data[row_one+j] = image_data[row_two+j];
            image_data[row_two+j] = temp;
        }
    }

    fclose(input_image_file);

    FILE* output_image_file = fopen(output_file, "wb");
    if(output_image_file == NULL){
        printf("Error opening output image file.\n");
        return;
    }

    fwrite(header, sizeof(unsigned char), 54, output_image_file);
    fwrite(image_data, sizeof(unsigned char), size, output_image_file);

    fclose(output_image_file);

    free(image_data);
}

void adjust_brightness_contrast(char* input_file, char* output_file, float brightness, float contrast){

    FILE* input_image_file = fopen(input_file, "rb");
    if(input_image_file == NULL){
        printf("Error opening input image file.\n");
        return;
    }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, input_image_file);

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    int padding = 0;
    while ((width * 3 + padding) % 4 != 0){
        padding++;
    }
    int size = (width * 3 + padding) * height;

    unsigned char* image_data = (unsigned char*)malloc(sizeof(unsigned char) * size);
    fread(image_data, sizeof(unsigned char), size, input_image_file);

    float c = (100.0 + contrast) / 100.0;
    c *= c;
    float factor = 259.0 * (c - 1.0);

    for(int i=0; i<height; i++){
        for(int j=0; j<width*3+padding; j++){
            int index = i * (width * 3 + padding) + j;
            float b = brightness / 255.0;
            int value = (int) (factor * (image_data[index] - 128) + 128 + (b * 255.0));
            if(value < 0){
                value = 0;
            }
            if(value > 255){
                value = 255;
            }
            image_data[index] = (unsigned char) value;
        }
    }

    fclose(input_image_file);

    FILE* output_image_file = fopen(output_file, "wb");
    if(output_image_file == NULL){
        printf("Error opening output image file.\n");
        return;
    }

    fwrite(header, sizeof(unsigned char), 54, output_image_file);
    fwrite(image_data, sizeof(unsigned char), size, output_image_file);

    fclose(output_image_file);

    free(image_data);
}

int main(){
    char input_file_name[] = "input.bmp";
    char output_file_name[] = "output.bmp";

    // Flip Image
    flip_image(input_file_name, output_file_name);

    // Increase Brightness by 50 and Contrast by 20
    adjust_brightness_contrast(input_file_name, output_file_name, 50.0, 20.0);

    return 0;
}