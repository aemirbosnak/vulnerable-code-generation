//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: portable
#include<stdio.h>
#include<stdlib.h>

typedef unsigned char BYTE;

/*Function prototypes*/
BYTE** read_image(char* filename, int* width, int* height);
void write_image(BYTE** image, char* filename, int width, int height);
void flip_image(BYTE** image, int width, int height);
void adjust_brightness(BYTE** image, int width, int height, int brightness);
void adjust_contrast(BYTE** image, int width, int height, int contrast);

void main(int argc, char* argv[]) {
    /*Check if filename is provided*/
    if (argc != 2) {
        printf("Error: No image file provided!");
        return;
    }

    /*Read image file*/
    int width, height;
    BYTE** image = read_image(argv[1], &width, &height);
    
    /*Flip image*/
    flip_image(image, width, height);

    /*Adjust brightness*/
    adjust_brightness(image, width, height, 20);

    /*Adjust contrast*/
    adjust_contrast(image, width, height, 50);

    /*Write image*/
    write_image(image, "processed_image.bmp", width, height);

    /*Free memory*/
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    printf("Image processing completed successfully!");
}

/*Read image file and return pixel array*/
BYTE** read_image(char* filename, int* width, int* height) {
    FILE* img = fopen(filename, "rb");

    /*Read BMP header (54 bytes)*/
    BYTE header[54];
    fread(header, sizeof(BYTE), 54, img);

    /*Get image dimensions*/
    *width = *(int*)&header[18];
    *height = *(int*)&header[22];

    /*Allocate memory for pixel array*/
    BYTE** image = (BYTE**)malloc(sizeof(BYTE*) * (*height));
    for (int i = 0; i < (*height); i++) {
        image[i] = (BYTE*)malloc(sizeof(BYTE) * (*width) * 3);
    }

    /*Read pixel array*/
    fread(image[0], sizeof(BYTE), (*width) * (*height) * 3, img);

    fclose(img);

    return image;
}

/*Write pixel array to image file*/
void write_image(BYTE** image, char* filename, int width, int height) {
    FILE* img = fopen(filename, "wb");

    /*Create BMP header (54 bytes)*/
    BYTE header[54] = {0};
    header[0] = 'B';
    header[1] = 'M';
    *(int*)&header[2] = 54 + 3 * width * height;
    *(int*)&header[10] = 54;
    *(int*)&header[14] = 40;
    *(int*)&header[18] = width;
    *(int*)&header[22] = height;
    *(short*)&header[26] = 1;
    *(short*)&header[28] = 24;
    *(int*)&header[34] = 3 * width * height;

    /*Write BMP header*/
    fwrite(header, sizeof(BYTE), 54, img);

    /*Write pixel array*/
    fwrite(image[0], sizeof(BYTE), 3 * width * height, img);

    fclose(img);
}

/*Flip image*/
void flip_image(BYTE** image, int width, int height) {
    BYTE temp[3] = {0};
    for (int i = 0; i < height/2; i++) {
        for (int j = 0; j < width; j++) {
            /*Swap pixels*/
            temp[0] = image[i][3*j];
            temp[1] = image[i][3*j+1];
            temp[2] = image[i][3*j+2];
            image[i][3*j] = image[height-i-1][3*j];
            image[i][3*j+1] = image[height-i-1][3*j+1];
            image[i][3*j+2] = image[height-i-1][3*j+2];
            image[height-i-1][3*j] = temp[0];
            image[height-i-1][3*j+1] = temp[1];
            image[height-i-1][3*j+2] = temp[2];
        }
    }
}

/*Adjust brightness*/
void adjust_brightness(BYTE** image, int width, int height, int brightness) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            /*Apply brightness correction*/
            image[i][3*j] += brightness;
            image[i][3*j+1] += brightness;
            image[i][3*j+2] += brightness;
        }
    }
}

/*Adjust contrast*/
void adjust_contrast(BYTE** image, int width, int height, int contrast) {
    double factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            /*Apply contrast correction*/
            image[i][3*j] = (BYTE) (factor * (image[i][3*j] - 128) + 128);
            image[i][3*j+1] = (BYTE) (factor * (image[i][3*j+1] - 128) + 128);
            image[i][3*j+2] = (BYTE) (factor * (image[i][3*j+2] - 128) + 128);
        }
    }
}