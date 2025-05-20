//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define ROWS 256
#define COLS 256

void flipImage(int* image) {
    int temp;
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS/2; j++) {
            temp = *(image + i*COLS + j);
            *(image + i*COLS + j) = *(image + i*COLS + COLS-j-1);
            *(image + i*COLS + COLS-j-1) = temp;
        }
    }
}

void adjustBrightness(int* image, int brightness) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            *(image + i*COLS + j) += brightness;
            if(*(image + i*COLS + j) > 255)
                *(image + i*COLS + j) = 255;
            if(*(image + i*COLS + j) < 0)
                *(image + i*COLS + j) = 0;
        }
    }
}

void adjustContrast(int* image, float contrast) {
    float factor = (259.0*(contrast + 255.0)) / (255.0*(259.0-contrast));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            *(image + i*COLS + j) = (int)(factor * (*(image + i*COLS + j) - 128.0) + 128.0);
            if(*(image + i*COLS + j) > 255)
                *(image + i*COLS + j) = 255;
            if(*(image + i*COLS + j) < 0)
                *(image + i*COLS + j) = 0;
        }
    }
}

int main() {
    int image[ROWS][COLS];
    // Reading image from file
    FILE *fp;
    fp = fopen("input_image.txt", "r");
    if(fp == NULL) {
        printf("Error opening file.\n");
        return 0;
    }
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            fscanf(fp, "%d", &image[i][j]);
        }
    }
    fclose(fp);
    
    // Flipping the image
    flipImage(&image[0][0]);
    
    // Adjusting brightness
    adjustBrightness(&image[0][0], 50);
    
    // Adjusting contrast
    adjustContrast(&image[0][0], 50.0);
    
    // Writing the processed image to file
    fp = fopen("output_image.txt", "w");
    if(fp == NULL) {
        printf("Error opening file.\n");
        return 0;
    }
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            fprintf(fp, "%d ", image[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    
    return 0;
}