//FormAI DATASET v1.0 Category: Image Editor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXEL 256

typedef struct Pixel {
    int R;
    int G;
    int B;
} Pixel;

Pixel **initPixelArray(int height, int width) {
    Pixel **imgArr = malloc(height * sizeof(Pixel*));
    for (int i = 0; i < height; i++) {
        imgArr[i] = malloc(width * sizeof(Pixel));
    }
    return imgArr;
}

void freePixelArray(Pixel **imgArr, int height) {
    for (int i = 0; i < height; i++) {
        free(imgArr[i]);
    }
    free(imgArr);
}

void addFilter(Pixel **imgArr, int height, int width, int filter[MAX_PIXEL][MAX_PIXEL]) {
    // calculate filter dimensions
    int filterSize = 0;
    for (int i = 0; i < MAX_PIXEL; i++) {
        if (filter[0][i] != 0) {
            filterSize++;
        } else {
            break;
        }
    }

    int filterHalf = filterSize / 2;

    Pixel **newImgArr = initPixelArray(height, width);

    for (int i = filterHalf; i < height - filterHalf; i++) {
        for (int j = filterHalf; j < width - filterHalf; j++) {

            int R = 0;
            int G = 0;
            int B = 0;

            for (int k = -filterHalf; k <= filterHalf; k++) {
                for (int l = -filterHalf; l <= filterHalf; l++) {
                    R += imgArr[i+k][j+l].R * filter[k+filterHalf][l+filterHalf];
                    G += imgArr[i+k][j+l].G * filter[k+filterHalf][l+filterHalf];
                    B += imgArr[i+k][j+l].B * filter[k+filterHalf][l+filterHalf];
                }
            }

            // clamp RGB values between 0 and 255
            newImgArr[i][j].R = R < 0 ? 0 : (R > 255 ? 255 : R);
            newImgArr[i][j].G = G < 0 ? 0 : (G > 255 ? 255 : G);
            newImgArr[i][j].B = B < 0 ? 0 : (B > 255 ? 255 : B);
        }
    }

    // copy new array back to original array
    for (int i = filterHalf; i < height - filterHalf; i++) {
        for (int j = filterHalf; j < width - filterHalf; j++) {
            imgArr[i][j] = newImgArr[i][j];
        }
    }

    freePixelArray(newImgArr, height);
}

Pixel **readImage(char *filename, int *height, int *width) {
    FILE *fp;
    Pixel **imgArr;
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // read image header
    char c;
    while ((c = fgetc(fp)) != '\n') {
        // skip comments
        if (c == '#') {
            while ((c = fgetc(fp)) != '\n') {
            }
        }

        if (c == 'P') {
            c = fgetc(fp);
            if (c != '6') {
                printf("Error: Invalid PPM image format\n");
                exit(1);
            }
        }

        if (c == ' ') {
            fscanf(fp, "%d", width);
            fscanf(fp, "%d", height);
        }
    }

    // read pixel data
    imgArr = initPixelArray(*height, *width);
    for (int i = 0; i < *height; i++) {
        for (int j = 0; j < *width; j++) {
            imgArr[i][j].R = fgetc(fp);
            imgArr[i][j].G = fgetc(fp);
            imgArr[i][j].B = fgetc(fp);
        }
    }

    fclose(fp);
    return imgArr;
}

void writeImage(char *filename, Pixel **imgArr, int height, int width) {
    FILE *fp;
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // write image header
    fprintf(fp, "P6\n");
    fprintf(fp, "# Image processed using C Image Editor\n");
    fprintf(fp, "%d %d\n", width, height);
    fprintf(fp, "%d\n", MAX_PIXEL-1);

    // write pixel data
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fputc(imgArr[i][j].R, fp);
            fputc(imgArr[i][j].G, fp);
            fputc(imgArr[i][j].B, fp);
        }
    }

    fclose(fp);
}

int main() {
    printf("Welcome to C Image Editor\n");
    int height, width;

    // read image file
    Pixel **imgArr = readImage("input.ppm", &height, &width);

    // apply filter
    int filter[3][3] = {{0, -1, 0}, {-1, 5, -1}, {0, -1, 0}};
    addFilter(imgArr, height, width, filter);

    // write output image
    writeImage("output.ppm", imgArr, height, width);

    printf("Image processing complete\n");

    // free memory
    freePixelArray(imgArr, height);

    return 0;
}