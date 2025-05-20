//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function to flip the image horizontally
void flip_horizontally(unsigned char *image_data, int width, int height, int bytes_per_pixel) {
    int row, col;

    for(row=0; row<height; row++) {
        for(col=0; col<width/2; col++) {
            int byte_index = row * width * bytes_per_pixel + col * bytes_per_pixel;
            int opposite_byte_index = row * width * bytes_per_pixel + (width - col - 1) * bytes_per_pixel;

            // swap the pixel values of the current pixel and its corresponding pixel on the opposite side
            for(int i=0; i<bytes_per_pixel; i++) {
                unsigned char temp = image_data[byte_index + i];
                image_data[byte_index + i] = image_data[opposite_byte_index + i];
                image_data[opposite_byte_index + i] = temp;
            }
        }
    }
}

// function to change the brightness of the image
void change_brightness(unsigned char *image_data, int width, int height, int bytes_per_pixel, float brightness_factor) {
    int row, col;

    for(row=0; row<height; row++) {
        for(col=0; col<width; col++) {
            int byte_index = row * width * bytes_per_pixel + col * bytes_per_pixel;

            // modify the brightness value of each pixel
            for(int i=0; i<bytes_per_pixel; i++) {
                float old_value = image_data[byte_index + i];
                float new_value = old_value * brightness_factor;
                image_data[byte_index + i] = (unsigned char)fmin(fmax(new_value, 0), 255); // clamp the value between 0 and 255
            }
        }
    }
}

// function to change the contrast of the image
void change_contrast(unsigned char *image_data, int width, int height, int bytes_per_pixel, float contrast_factor) {
    int row, col;

    float average_value = 0.0;
    int num_pixels = width * height;

    // calculate the average pixel value
    for(row=0; row<height; row++) {
        for(col=0; col<width; col++) {
            int byte_index = row * width * bytes_per_pixel + col * bytes_per_pixel;
            for(int i=0; i<bytes_per_pixel; i++) {
                average_value += image_data[byte_index + i];
            }
        }
    }
    average_value /= (float)(num_pixels * bytes_per_pixel);

    // modify the contrast value of each pixel
    for(row=0; row<height; row++) {
        for(col=0; col<width; col++) {
            int byte_index = row * width * bytes_per_pixel + col * bytes_per_pixel;

            for(int i=0; i<bytes_per_pixel; i++) {
                float old_value = image_data[byte_index + i];
                float new_value = (old_value - average_value) * contrast_factor + average_value;
                image_data[byte_index + i] = (unsigned char)fmin(fmax(new_value, 0), 255); // clamp the value between 0 and 255
            }
        }
    }
}

int main() {
    // read the image data from file
    FILE *file;
    file = fopen("input.bmp", "rb");

    if(file == NULL) {
        printf("Failed to open input file\n");
        return 0;
    }

    fseek(file, 18, SEEK_SET);
    int width;
    fread(&width, sizeof(int), 1, file);
    int height;
    fread(&height, sizeof(int), 1, file);
    int bits_per_pixel;
    fseek(file, 28, SEEK_SET);
    fread(&bits_per_pixel, sizeof(short), 1, file);
    int bytes_per_pixel = bits_per_pixel / 8;

    int image_size = width * height * bytes_per_pixel;
    unsigned char *image_data = (unsigned char*)malloc(image_size);

    fseek(file, 54, SEEK_SET);
    fread(image_data, sizeof(unsigned char), image_size, file);
    fclose(file);

    // flip the image horizontally
    flip_horizontally(image_data, width, height, bytes_per_pixel);

    // change the brightness of the image
    change_brightness(image_data, width, height, bytes_per_pixel, 1.5); // increase brightness by 50%

    // change the contrast of the image
    change_contrast(image_data, width, height, bytes_per_pixel, 1.2); // increase contrast by 20%

    // write the modified image data to file
    file = fopen("output.bmp", "wb");

    fwrite(image_data, sizeof(unsigned char), image_size, file);
    fclose(file);

    free(image_data);

    return 0;
}