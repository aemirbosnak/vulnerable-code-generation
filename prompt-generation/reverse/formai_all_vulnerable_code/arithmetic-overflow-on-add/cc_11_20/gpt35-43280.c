//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>

int main(){
    // Opening the image file
    FILE *file = fopen("image.bmp", "rb");

    // Reading the header of image
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);

    // Extracting image dimensions
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Extracting color depth
    int color_depth = *(int*)&header[28];

    // Calculating row padding
    int padding = (4 - (width * (color_depth / 8)) % 4) % 4;

    // Allocating memory for image data
    unsigned char *img_data = (unsigned char*)malloc(sizeof(unsigned char)*((width*(color_depth/8))+padding)*height);

    // Reading image data
    fread(img_data, sizeof(unsigned char), ((width*(color_depth/8))+padding)*height, file);

    // Closing the image file
    fclose(file);

    // Flip the image vertically
    unsigned char *temp_row_data = (unsigned char*)malloc(sizeof(unsigned char)*(width*(color_depth/8)));
    for(int i = 0; i < height/2; i++){
        for(int j = 0; j < width*(color_depth/8); j++){
            temp_row_data[j] = img_data[(i*(width*(color_depth/8)+padding))+j];
            img_data[(i*(width*(color_depth/8)+padding))+j] = img_data[((height-1-i)*(width*(color_depth/8)+padding))+j];
            img_data[((height-1-i)*(width*(color_depth/8)+padding))+j] = temp_row_data[j];
        }
    }
    free(temp_row_data);

    // Changing brightness of the image
    int brightness = 50;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            for(int k = 0; k < color_depth/8; k++){
                int val = img_data[(i*(width*(color_depth/8)+padding))+(j*(color_depth/8))+k] + brightness;
                if(val < 0) val = 0;
                if(val > 255) val = 255;
                img_data[(i*(width*(color_depth/8)+padding))+(j*(color_depth/8))+k] = val;
            }
        }
    }

    // Changing contrast of the image
    float contrast = 1.5;
    float factor = (259*(contrast+255)) / (255*(259-contrast));
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            for(int k = 0; k < color_depth/8; k++){
                int val = factor * (img_data[(i*(width*(color_depth/8)+padding))+(j*(color_depth/8))+k] - 128) + 128;
                if(val < 0) val = 0;
                if(val > 255) val = 255;
                img_data[(i*(width*(color_depth/8)+padding))+(j*(color_depth/8))+k] = val;
            }
        }
    }

    // Saving the modified image
    file = fopen("modified_image.bmp", "wb");
    fwrite(header, sizeof(unsigned char), 54, file);
    fwrite(img_data, sizeof(unsigned char), ((width*(color_depth/8))+padding)*height, file);
    fclose(file);

    // Freeing memory associated with image data
    free(img_data);

    printf("Image processing successfully completed!\n");
    return 0;
}