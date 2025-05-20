//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: brave
#include <stdio.h>

int main() {
    // read the image file
    FILE* input_file = fopen("image.bmp", "rb");
    if (input_file == NULL) {
        printf("Error: Can't open the image file.");
        return 1;
    }
    
    // read image header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, input_file);
    
    // get image information
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int pixel_data_size = *(int*)&header[34];
    
    // allocate memory for pixel data
    unsigned char* pixel_data = (unsigned char*)malloc(pixel_data_size);
    if (pixel_data == NULL) {
        printf("Error: Can't allocate memory for pixel data.");
        return 1;
    }
    
    // read the pixel data
    fread(pixel_data, sizeof(unsigned char), pixel_data_size, input_file);
    fclose(input_file);
    
    // flip the image vertically
    unsigned char temp_pixel[3];
    for (int row = 0; row < height/2; row++) {
        for (int col = 0; col < width; col++) {
            int offset_1 = row*width*3 + col*3;
            int offset_2 = (height-row-1)*width*3 + col*3;
            memcpy(temp_pixel, &pixel_data[offset_1], 3);
            memcpy(&pixel_data[offset_1], &pixel_data[offset_2], 3);
            memcpy(&pixel_data[offset_2], temp_pixel, 3);
        }
    }
    
    // increase image brightness by 20%
    for (int i = 0; i < pixel_data_size; i++) {
        int val = pixel_data[i] + pixel_data[i]/5;
        if (val > 255) val = 255;
        pixel_data[i] = (unsigned char)val;
    }
    
    // decrease image contrast by 20%
    int avg_intensity = 0;
    for (int i = 0; i < pixel_data_size; i += 3) {
        int intensity = (pixel_data[i] + pixel_data[i+1] + pixel_data[i+2]) / 3;
        avg_intensity += intensity;
    }
    avg_intensity /= width*height;
    for (int i = 0; i < pixel_data_size; i++) {
        int val = (pixel_data[i] - avg_intensity)*0.8 + avg_intensity;
        if (val < 0) val = 0;
        if (val > 255) val = 255;
        pixel_data[i] = (unsigned char)val;
    }
    
    // write the new image to file
    FILE* output_file = fopen("new_image.bmp", "wb");
    fwrite(header, sizeof(unsigned char), 54, output_file);
    fwrite(pixel_data, sizeof(unsigned char), pixel_data_size, output_file);
    fclose(output_file);
    
    // free allocated memory
    free(pixel_data);
    
    return 0;
}