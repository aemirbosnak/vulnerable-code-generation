//FormAI DATASET v1.0 Category: Image Editor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PIXEL_VALUE 255

typedef struct Image {
    int width;
    int height;
    int maxPixelValue;
    unsigned char** data;
} Image;

// Function prototypes
void loadImage(Image* img, const char* fileName);
void saveImage(Image img, const char* fileName);
void applyFilter(Image* img, int filterSize, double* filter);
void threshold(Image* img, int thresholdValue);

int main() {
    Image img;
    char fileName[256];

    printf("Enter the image file name: ");
    scanf("%s", fileName);

    // Load the image
    loadImage(&img, fileName);

    // Display image information
    printf("Width: %d\nHeight: %d\nMax Pixel Value: %d\n", img.width, img.height, img.maxPixelValue);

    // Apply Smooth filter
    double smoothFilter[9] = {1.0/9, 1.0/9, 1.0/9, 1.0/9, 1.0/9, 1.0/9, 1.0/9, 1.0/9, 1.0/9};
    applyFilter(&img, 3, smoothFilter);

    // Apply Sharp filter
    double sharpFilter[9] = {-1, -1, -1, -1, 9, -1, -1, -1, -1};
    applyFilter(&img, 3, sharpFilter);

    // Apply Thresholding
    int thresholdValue = 127;
    threshold(&img, thresholdValue);

    // Save the image
    saveImage(img, "output_image.pgm");

    return 0;
}

void loadImage(Image* img, const char* fileName) {
    FILE* fp = fopen(fileName, "rb");
    char fileType[3];

    // Check if file opened successfully
    if (!fp) {
        printf("Error: Failed to open file %s\n", fileName);
        exit(1);
    }

    // Read file header
    fgets(fileType, 3, fp);
    if (strcmp(fileType, "P5")) {
        printf("Error: Invalid file format\n");
        exit(1);
    }
    fscanf(fp, "%d %d %d", &img->width, &img->height, &img->maxPixelValue);

    // Allocate memory for image data
    img->data = (unsigned char**) malloc(sizeof(unsigned char*) * img->height);
    for (int i = 0; i < img->height; i++) {
        img->data[i] = (unsigned char*) malloc(sizeof(unsigned char) * img->width);
    }

    // Read image data
    for (int i = 0; i < img->height; i++) {
        fread(img->data[i], sizeof(unsigned char), img->width, fp);
    }

    // Close file
    fclose(fp);
}

void saveImage(Image img, const char* fileName) {
    FILE* fp = fopen(fileName, "wb");

    // Check if file opened successfully
    if (!fp) {
        printf("Error: Failed to open file %s\n", fileName);
        exit(1);
    }

    // Write file header
    fprintf(fp, "P5\n%d %d\n%d\n", img.width, img.height, img.maxPixelValue);

    // Write image data
    for (int i = 0; i < img.height; i++) {
        fwrite(img.data[i], sizeof(unsigned char), img.width, fp);
    }

    // Close file
    fclose(fp);
}

void applyFilter(Image* img, int filterSize, double* filter) {
    int padding = filterSize / 2;

    // Temporary image buffer
    unsigned char** tempData = (unsigned char**) malloc(sizeof(unsigned char*) * img->height);
    for (int i = 0; i < img->height; i++) {
        tempData[i] = (unsigned char*) malloc(sizeof(unsigned char) * img->width);
        memset(tempData[i], 0, sizeof(unsigned char) * img->width);
    }

    // Apply filter
    for (int i = padding; i < img->height - padding; i++) {
        for (int j = padding; j < img->width - padding; j++) {
            double sum = 0;
            for (int k = -padding; k <= padding; k++) {
                for (int l = -padding; l <= padding; l++) {
                    int pixelValue = img->data[i+k][j+l];
                    double filterValue = filter[(k+padding) * filterSize + (l+padding)];
                    sum += pixelValue * filterValue;
                }
            }
            tempData[i][j] = fmin(MAX_PIXEL_VALUE, fmax(0, round(sum)));
        }
    }

    // Copy temp data to image data
    for (int i = 0; i < img->height; i++) {
        memcpy(img->data[i], tempData[i], sizeof(unsigned char) * img->width);
    }

    // Free temporary data
    for (int i = 0; i < img->height; i++) {
        free(tempData[i]);
    }
    free(tempData);
}

void threshold(Image* img, int thresholdValue) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            if (img->data[i][j] < thresholdValue) {
                img->data[i][j] = 0;
            }
            else {
                img->data[i][j] = MAX_PIXEL_VALUE;
            }
        }
    }
}