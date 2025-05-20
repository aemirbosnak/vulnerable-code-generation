//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXEL_VALUE 255
#define MIN_PIXEL_VALUE 0

void flip_image_horizontal(int image_data[], int width, int height){
    for(int y=0; y<height; y++){
        for(int x=0; x<width/2; x++){
            int left_index = y*width + x;
            int right_index = y*width + width-1-x;
            int temp = image_data[left_index];
            image_data[left_index] = image_data[right_index];
            image_data[right_index] = temp;
        }
    }
}

void adjust_brightness(int image_data[], int width, int height, int brightness){
    for(int i=0; i<width*height; i++){
        int new_pixel_value = image_data[i] + brightness;
        if(new_pixel_value > MAX_PIXEL_VALUE){
            image_data[i] = MAX_PIXEL_VALUE;
        }else if(new_pixel_value < MIN_PIXEL_VALUE){
            image_data[i] = MIN_PIXEL_VALUE;
        }else{
            image_data[i] = new_pixel_value;
        }
    }
}

void adjust_contrast(int image_data[], int width, int height, float contrast){
    float factor = (259.0f * (contrast + 255.0f)) / (255.0f * (259.0f - contrast));
    for(int i=0; i<width*height; i++){
        int new_pixel_value = factor * (image_data[i] - 128) + 128;
        if(new_pixel_value > MAX_PIXEL_VALUE){
            image_data[i] = MAX_PIXEL_VALUE;
        }else if(new_pixel_value < MIN_PIXEL_VALUE){
            image_data[i] = MIN_PIXEL_VALUE;
        }else{
            image_data[i] = new_pixel_value;
        }
    }
}

int main(){
    // Load image data from file
    FILE* f = fopen("image.dat", "rb");
    if(f == NULL){
        fprintf(stderr, "Failed to open image file.");
        return -1;
    }
    int width, height;
    fread(&width, sizeof(int), 1, f);
    fread(&height, sizeof(int), 1, f);
    int* image_data = malloc(width * height * sizeof(int));
    fread(image_data, sizeof(int), width*height, f);
    fclose(f);
    
    // Flip image horizontally
    flip_image_horizontal(image_data, width, height);
    
    // Adjust brightness by 50
    adjust_brightness(image_data, width, height, 50);
    
    // Adjust contrast by 50%
    adjust_contrast(image_data, width, height, 50.0f);
    
    // Save image data to file
    f = fopen("processed_image.dat", "wb");
    if(f == NULL){
        fprintf(stderr, "Failed to open image file.");
        return -1;
    }
    fwrite(&width, sizeof(int), 1, f);
    fwrite(&height, sizeof(int), 1, f);
    fwrite(image_data, sizeof(int), width*height, f);
    fclose(f);
    
    free(image_data);
    return 0;
}