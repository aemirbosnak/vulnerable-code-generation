//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

typedef struct Image {
    int width;
    int height;
    int max_color;
    unsigned char* data;
} Image;

void flip_image(Image* img) {
    unsigned char temp;
    int row, col;
    for(row = 0; row < img->height; row++) {
        for(col = 0; col < img->width / 2; col++) {
            temp = img->data[row * img->width + col * 3];
            img->data[row * img->width + col * 3] = img->data[row * img->width + (img->width - 1 - col) * 3];
            img->data[row * img->width + (img->width - 1 - col) * 3] = temp;
            
            temp = img->data[row * img->width + col * 3 + 1];
            img->data[row * img->width + col * 3 + 1] = img->data[row * img->width + (img->width - 1 - col) * 3 + 1];
            img->data[row * img->width + (img->width - 1 - col) * 3 + 1] = temp;
            
            temp = img->data[row * img->width + col * 3 + 2];
            img->data[row * img->width + col * 3 + 2] = img->data[row * img->width + (img->width - 1 - col) * 3 + 2];
            img->data[row * img->width + (img->width - 1 - col) * 3 + 2] = temp;
        }
    }
}

void adjust_brightness(Image* img, int brightness) {
    int row, col;
    for(row = 0; row < img->height; row++) {
        for(col = 0; col < img->width; col++) {
            img->data[row * img->width + col * 3] += brightness;
            img->data[row * img->width + col * 3 + 1] += brightness;
            img->data[row * img->width + col * 3 + 2] += brightness;
            
            if(img->data[row * img->width + col * 3] > img->max_color) {
                img->data[row * img->width + col * 3] = img->max_color;
            }
            if(img->data[row * img->width + col * 3 + 1] > img->max_color) {
                img->data[row * img->width + col * 3 + 1] = img->max_color;
            }
            if(img->data[row * img->width + col * 3 + 2] > img->max_color) {
                img->data[row * img->width + col * 3 + 2] = img->max_color;
            }
            
            if(img->data[row * img->width + col * 3] < 0) {
                img->data[row * img->width + col * 3] = 0;
            }
            if(img->data[row * img->width + col * 3 + 1] < 0) {
                img->data[row * img->width + col * 3 + 1] = 0;
            }
            if(img->data[row * img->width + col * 3 + 2] < 0) {
                img->data[row * img->width + col * 3 + 2] = 0;
            }
        }
    }
}

void adjust_contrast(Image* img, float contrast) {
    int row, col;
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for(row = 0; row < img->height; row++) {
        for(col = 0; col < img->width; col++) {
            img->data[row * img->width + col * 3] = factor * (img->data[row * img->width + col * 3] - 128) + 128;
            img->data[row * img->width + col * 3 + 1] = factor * (img->data[row * img->width + col * 3 + 1] - 128) + 128;
            img->data[row * img->width + col * 3 + 2] = factor * (img->data[row * img->width + col * 3 + 2] - 128) + 128;
            
            if(img->data[row * img->width + col * 3] > img->max_color) {
                img->data[row * img->width + col * 3] = img->max_color;
            }
            if(img->data[row * img->width + col * 3 + 1] > img->max_color) {
                img->data[row * img->width + col * 3 + 1] = img->max_color;
            }
            if(img->data[row * img->width + col * 3 + 2] > img->max_color) {
                img->data[row * img->width + col * 3 + 2] = img->max_color;
            }
            
            if(img->data[row * img->width + col * 3] < 0) {
                img->data[row * img->width + col * 3] = 0;
            }
            if(img->data[row * img->width + col * 3 + 1] < 0) {
                img->data[row * img->width + col * 3 + 1] = 0;
            }
            if(img->data[row * img->width + col * 3 + 2] < 0) {
                img->data[row * img->width + col * 3 + 2] = 0;
            }
        }
    }
}

int main() {
    // Load image from file
    FILE* fp = fopen("image.ppm", "r");
    if(fp == NULL) {
        printf("Error: Cannot open file\n");
        exit(1);
    }
    char magic_num[3];
    fscanf(fp, "%s", magic_num);
    if(magic_num[0] != 'P' || magic_num[1] != '6') {
        printf("Error: Not a valid PPM image\n");
        exit(1);
    }
    Image img;
    fscanf(fp, "%d %d %d", &img.width, &img.height, &img.max_color);
    img.data = (unsigned char*) malloc(img.width * img.height * 3);
    fgetc(fp);
    fread(img.data, 1, img.width * img.height * 3, fp);
    fclose(fp);
    
    // Flip image horizontally
    flip_image(&img);
    
    // Adjust brightness
    adjust_brightness(&img, 30);
    
    // Adjust contrast
    adjust_contrast(&img, 50.0);
    
    // Save image to file
    fp = fopen("output.ppm", "w");
    fprintf(fp, "%s\n", magic_num);
    fprintf(fp, "%d %d\n", img.width, img.height);
    fprintf(fp, "%d\n", img.max_color);
    fwrite(img.data, 1, img.width * img.height * 3, fp);
    fclose(fp);
    
    // Free memory
    free(img.data);
    
    return 0;
}