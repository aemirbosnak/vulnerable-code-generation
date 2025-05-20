//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//function to flip image horizontally
void flip_horizontal(unsigned char *image, int width, int height, int channels){
    unsigned char temp;
    int k;
    for(int i=0;i<height;i++){
        for(int j=0;j<width/2;j++){
            for(k=0;k<channels;k++){
                temp = image[(i*width+j)*channels+k];
                image[(i*width+j)*channels+k] = image[(i*width+width-j-1)*channels+k];
                image[(i*width+width-j-1)*channels+k] = temp;
            }
        }
    }
}

//function to flip image vertically
void flip_vertical(unsigned char *image, int width, int height, int channels){
    unsigned char temp;
    int k;
    for(int j=0;j<width;j++){
        for(int i=0;i<height/2;i++){
            for(k=0;k<channels;k++){
                temp = image[(i*width+j)*channels+k];
                image[(i*width+j)*channels+k] = image[((height-i-1)*width+j)*channels+k];
                image[((height-i-1)*width+j)*channels+k] = temp;
            }
        }
    }
}

//function to adjust brightness of image
void brightness(unsigned char *image, int width, int height, int channels, int adjustment){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            for(int k=0;k<channels;k++){
                int pixel_value = image[(i*width+j)*channels+k];
                int new_value = pixel_value + adjustment;
                if(new_value < 0) new_value = 0;
                if(new_value > 255) new_value = 255;
                image[(i*width+j)*channels+k] = new_value;
            }
        }
    }
}

//function to adjust contrast of image
void contrast(unsigned char *image, int width, int height, int channels, float adjustment){
    float factor = (259*(adjustment + 255))/(255*(259-adjustment));
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            for(int k=0;k<channels;k++){
                int pixel_value = image[(i*width+j)*channels+k];
                int new_value = factor * (pixel_value - 128) + 128;
                if(new_value < 0) new_value = 0;
                if(new_value > 255) new_value = 255;
                image[(i*width+j)*channels+k] = new_value;
            }
        }
    }
}

int main(int argc, char **argv){
    //check number of command line arguments
    if(argc != 4){
        printf("Usage: %s <input_image> <output_image> <operation>\n", argv[0]);
        printf("Operations:\n");
        printf("\t-hf\tFlip image horizontally\n");
        printf("\t-vf\tFlip image vertically\n");
        printf("\t-b\tAdjust brightness (-255 to 255)\n");
        printf("\t-c\tAdjust contrast (0.1 to 10.0)\n");
        return 1;
    }

    //read input image
    char *input_filename = argv[1];
    FILE *input_file = fopen(input_filename, "rb");
    if(!input_file){
        printf("Error: can't open input file\n");
        return 1;
    }
    char header[54];
    fread(header, sizeof(unsigned char), 54, input_file);
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int channels = *(int*)&header[28];
    unsigned char *image = (unsigned char*)malloc(width*height*channels);
    fread(image, sizeof(unsigned char), width*height*channels, input_file);
    fclose(input_file);

    //get operation to perform
    char *operation = argv[3];
    if(strcmp(operation, "-hf") == 0){
        flip_horizontal(image, width, height, channels);
    }
    else if(strcmp(operation, "-vf") == 0){
        flip_vertical(image, width, height, channels);
    }
    else if(strcmp(operation, "-b") == 0){
        int adjustment = atoi(argv[4]);
        brightness(image, width, height, channels, adjustment);
    }
    else if(strcmp(operation, "-c") == 0){
        float adjustment = atof(argv[4]);
        contrast(image, width, height, channels, adjustment);
    }
    else{
        printf("Error: invalid operation\n");
        return 1;
    }

    //write output image
    char *output_filename = argv[2];
    FILE *output_file = fopen(output_filename, "wb");
    fwrite(header, sizeof(unsigned char), 54, output_file);
    fwrite(image, sizeof(unsigned char), width*height*channels, output_file);
    fclose(output_file);

    //cleanup
    free(image);

    return 0;
}