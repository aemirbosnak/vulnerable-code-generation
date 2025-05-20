//FormAI DATASET v1.0 Category: Image Editor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_COLOR 255
#define MAX_PIXEL 512
#define FILE_HEADER_SIZE 14
#define INFO_HEADER_SIZE 40

#pragma pack(push, 1)
typedef struct {
    unsigned short type;
    unsigned int size;
    unsigned short reserved1, reserved2;
    unsigned int offset;
} file_header;
typedef struct {
    unsigned int size;
    int width, height;
    unsigned short planes;
    unsigned short bit_count;
    unsigned int compression;
    unsigned int image_size;
    int x_pixels_per_meter, y_pixels_per_meter;
    unsigned int colors_used, colors_important;
} info_header;
#pragma pack(pop)

// Functions to read and write bmp files
unsigned char** read_bmp(const char* file_name, int* img_width, int* img_height) {
    file_header f_header;
    info_header i_header;

    FILE* fp = fopen(file_name, "rb");
    if (!fp) {
        printf("Error: Opening file failed\n");
        return NULL;
    }

    // Read bitmap file header and info header
    fread(&f_header, sizeof(file_header), 1, fp);
    fread(&i_header, sizeof(info_header), 1, fp);

    // Get image dimensions
    *img_width = i_header.width;
    *img_height = i_header.height;

    // Allocate image memory
    unsigned char** img = (unsigned char**) malloc((*img_height) * sizeof(unsigned char*));
    for (int i = 0; i < (*img_height); i++) {
        img[i] = (unsigned char*) malloc((*img_width) * sizeof(unsigned char));
    }

    // Calculate padding of each row in bytes
    int row_padding = 4 - ((*img_width * i_header.bit_count / 8) % 4);
    if (row_padding == 4) row_padding = 0;

    // Skip the file header offset bytes to start reading image data
    fseek(fp, f_header.offset, SEEK_SET);

    // Read image data pixel by pixel
    for (int i = 0; i < (*img_height); i++) {
        for (int j = 0; j < (*img_width); j++) {
            fread(&img[i][j], sizeof(unsigned char), 1, fp);
        }
        fseek(fp, row_padding, SEEK_CUR); // Skip row padding bytes
    }

    fclose(fp);
    return img;
}

void write_bmp(const char* file_name, unsigned char** img, int img_width, int img_height) {
    file_header f_header;
    info_header i_header;

    strcpy(f_header.type, "BM"); // Set file type
    f_header.size = FILE_HEADER_SIZE + INFO_HEADER_SIZE + img_width * img_height;
    f_header.reserved1 = 0;
    f_header.reserved2 = 0;
    f_header.offset = FILE_HEADER_SIZE + INFO_HEADER_SIZE;

    i_header.size = INFO_HEADER_SIZE;
    i_header.width = img_width;
    i_header.height = img_height;
    i_header.planes = 1;
    i_header.bit_count = 8;
    i_header.compression = 0;
    i_header.image_size = img_width * img_height;
    i_header.x_pixels_per_meter = 0;
    i_header.y_pixels_per_meter = 0;
    i_header.colors_used = 256;
    i_header.colors_important = 0;

    // Calculate padding of each row in bytes
    int row_padding = 4 - (img_width % 4);
    if (row_padding == 4) row_padding = 0;

    // Allocate memory for the image data array
    unsigned char* img_data = (unsigned char*) malloc(img_width * img_height * sizeof(unsigned char));

    // Copy pixel values into image data array
    for (int i = 0; i < img_height; i++) {
        for (int j = 0; j < img_width; j++) {
            img_data[i*img_width + j] = img[i][j];
        }
        memset(img_data + i*img_width + img_width, 0, row_padding); // Add row padding
    }

    FILE* fp = fopen(file_name, "wb");
    if (!fp) {
        printf("Error: Opening file failed\n");
        return;
    }

    fwrite(&f_header, sizeof(file_header), 1, fp);
    fwrite(&i_header, sizeof(info_header), 1, fp);
    fwrite(img_data, sizeof(unsigned char), img_width * img_height, fp);
    fclose(fp);
}

// Image processing functions
void grayscale(unsigned char** img, int img_width, int img_height) {
    for (int i = 0; i < img_height; i++) {
        for (int j = 0; j < img_width; j++) {
            unsigned char val = img[i][j];
            img[i][j] = 0.21*val + 0.72*val + 0.07*val; // Grayscale conversion formula
        }
    }
}

void invert(unsigned char** img, int img_width, int img_height) {
    for (int i = 0; i < img_height; i++) {
        for (int j = 0; j < img_width; j++) {
            img[i][j] = MAX_COLOR - img[i][j]; // Invert pixel value
        }
    }
}

void brightness(unsigned char** img, int img_width, int img_height, int delta) {
    for (int i = 0; i < img_height; i++) {
        for (int j = 0; j < img_width; j++) {
            int new_val = img[i][j] + delta; // Increase or decrease pixel value by delta
            img[i][j] = fmax(0, fmin(MAX_COLOR, new_val)); // Clamp values between 0 and MAX_COLOR
        }
    }
}

int main() {
    int img_width, img_height;
    unsigned char** img = read_bmp("input.bmp", &img_width, &img_height);

    // Apply image processing functions
    grayscale(img, img_width, img_height);
    invert(img, img_width, img_height);
    brightness(img, img_width, img_height, -50);

    write_bmp("output.bmp", img, img_width, img_height);

    // Deallocate image memory
    for (int i = 0; i < img_height; i++) {
        free(img[i]);
    }
    free(img);
    return 0;
}