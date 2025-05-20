//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: secure
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SIZE 1024

char gray_scale_chars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};
int gray_scale_levels = 10;

void convert_to_ascii_art(char* image_file_path) {

    FILE* image_file = fopen(image_file_path, "rb");

    if(image_file == NULL) {
        printf("Image file not found!\n");
        return;
    }

    char header[54];
    fread(header, sizeof(char), 54, image_file);

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int depth = *(int*)&header[28];

    if(depth != 24) {
        printf("Unsupported image format!\n");
        fclose(image_file);
        return;
    }

    int image_size = width * height * 3;
    unsigned char* image_data = (unsigned char*) malloc(image_size);
    fread(image_data, sizeof(unsigned char), image_size, image_file);
    fclose(image_file);

    char ascii_art[MAX_SIZE];
    int ascii_index = 0;
    int gray_level = 0;

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            int pixel_index = (i * width + j) * 3;
            int r = image_data[pixel_index];
            int g = image_data[pixel_index + 1];
            int b = image_data[pixel_index + 2];
            int avg_gray = (r + g + b) / 3;
            gray_level = avg_gray * gray_scale_levels / 256;
            if(gray_level > gray_scale_levels - 1) {
                gray_level = gray_scale_levels - 1;
            }
            ascii_art[ascii_index++] = gray_scale_chars[gray_level];
        }
        ascii_art[ascii_index++] = '\n';
    }
    ascii_art[ascii_index] = '\0';

    printf("%s", ascii_art);

    free(image_data);
}

int main(int argc, char* argv[]) {

    if(argc < 2) {
        printf("Usage: ./img2ascii <image_file_path>\n");
        return 0;
    }

    convert_to_ascii_art(argv[1]);

    return 0;
}