//FormAI DATASET v1.0 Category: Image Editor ; Style: Ada Lovelace
/* A program to perform image editing operations using C */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_PIXEL_VALUE 255

/* Function to get the name of image file from the user */
char* get_filename() {
    char* filename = (char*)malloc(MAX_FILENAME_LENGTH * sizeof(char));
    printf("Enter the name of the image file: ");
    scanf("%s", filename);
    return filename;
}

/* Function to read the image file */
void read_image_file(char* filename, int** image_data, int* width, int* height) {
    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error: Could not open the image file.\n");
        exit(1);
    }
    fscanf(fp, "%d %d", width, height);
    *image_data = (int*)malloc((*width) * (*height) * sizeof(int));
    for(int i = 0; i < (*width) * (*height); i++) {
        fscanf(fp, "%d", &((*image_data)[i]));
    }
    fclose(fp);
}

/* Function to write the modified image to a file */
void write_image_file(char* filename, int* image_data, int width, int height) {
    FILE* fp = fopen(filename, "w");
    fprintf(fp, "%d %d\n", width, height);
    for(int i = 0; i < width * height; i++) {
        fprintf(fp, "%d\n", image_data[i]);
    }
    fclose(fp);
}

/* Function to flip the image horizontally */
void flip_horizontally(int* image_data, int width, int height) {
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width / 2; x++) {
            int temp = image_data[y * width + x];
            image_data[y * width + x] = image_data[y * width + (width - 1 - x)];
            image_data[y * width + (width - 1 - x)] = temp;
        }
    }
}

/* Function to adjust the brightness of the image */
void adjust_brightness(int* image_data, int width, int height, int brightness_adjustment) {
    for(int i = 0; i < width * height; i++) {
        int new_value = image_data[i] + brightness_adjustment;
        if(new_value < 0) {
            new_value = 0;
        }
        else if(new_value > MAX_PIXEL_VALUE) {
            new_value = MAX_PIXEL_VALUE;
        }
        image_data[i] = new_value;
    }
}

/* Function to blur the image */
void blur_image(int* image_data, int width, int height) {
    int* temp_data = (int*)malloc(width * height * sizeof(int));
    memcpy(temp_data, image_data, width * height * sizeof(int));
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            int pixel_sum = 0;
            int num_pixels = 0;
            for(int dy = -1; dy <= 1; dy++) {
                for(int dx = -1; dx <= 1; dx++) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if(nx < 0 || nx >= width || ny < 0 || ny >= height) {
                        continue;
                    }
                    pixel_sum += temp_data[ny * width + nx];
                    num_pixels++;
                }
            }
            image_data[y * width + x] = pixel_sum / num_pixels;
        }
    }
    free(temp_data);
}

int main() {
    char* filename = get_filename();
    int* image_data = NULL;
    int width, height;
    read_image_file(filename, &image_data, &width, &height);
    free(filename);

    // perform image editing operations
    flip_horizontally(image_data, width, height);
    adjust_brightness(image_data, width, height, -50);
    blur_image(image_data, width, height);

    // write the modified image to a file
    write_image_file("modified_image.pgm", image_data, width, height);
    free(image_data);

    return 0;
}