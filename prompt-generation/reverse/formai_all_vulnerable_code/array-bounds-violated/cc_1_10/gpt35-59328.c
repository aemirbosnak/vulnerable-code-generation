//FormAI DATASET v1.0 Category: Image Editor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 20
#define MAX_PIXEL_VALUE 255

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Color;

typedef struct {
    int width;
    int height;
    Color *pixels;
} Image;

Image *createImage(int width, int height);
void freeImage(Image *image);
int loadImage(Image *image, char *filename);
int saveImage(Image *image, char *filename);
void applyFilter(Image *image, char *filterName);
void grayscaleFilter(Image *image);
void sepiaFilter(Image *image);
void invertFilter(Image *image);
void pixelateFilter(Image *image);

int main() {
    Image *image = createImage(0, 0);
    char filename[MAX_NAME_LENGTH];
    char input[20];
    int inputNum;
    int running = 1;
    
    while (running) {
        printf("\nMENU\n");
        printf("1: Load Image\n");
        printf("2: Save Image\n");
        printf("3: Apply Filter\n");
        printf("4: Quit Program\n");
        printf("Enter an option: ");
        fgets(input, 20, stdin);
        inputNum = atoi(input);
        
        switch (inputNum) {
            case 1:
                printf("Enter image filename: ");
                fgets(filename, MAX_NAME_LENGTH, stdin);
                filename[strlen(filename)-1] = '\0';
                
                if (loadImage(image, filename)) {
                    printf("Image loaded successfully!\n");
                    printf("Image dimensions: %d x %d\n", image->width, image->height);
                }
                else {
                    printf("Failed to load image\n");
                }
                break;
                
            case 2:
                if (image->width != 0 && image->height != 0) {
                    printf("Enter image filename: ");
                    fgets(filename, MAX_NAME_LENGTH, stdin);
                    filename[strlen(filename)-1] = '\0';
                    
                    if (saveImage(image, filename)) {
                        printf("Image saved successfully!\n");
                    }
                    else {
                        printf("Failed to save image\n");
                    }
                }
                else {
                    printf("No image loaded!\n");
                }
                break;
                
            case 3:
                if (image->width != 0 && image->height != 0) {
                    printf("\nFILTERS\n");
                    printf("1: Grayscale\n");
                    printf("2: Sepia\n");
                    printf("3: Invert\n");
                    printf("4: Pixelate\n");
                    printf("Enter a filter number: ");
                    fgets(input, 20, stdin);
                    inputNum = atoi(input);
                    
                    switch (inputNum) {
                        case 1:
                            applyFilter(image, "grayscale");
                            printf("Grayscale filter applied!\n");
                            break;
                            
                        case 2:
                            applyFilter(image, "sepia");
                            printf("Sepia filter applied!\n");
                            break;
                            
                        case 3:
                            applyFilter(image, "invert");
                            printf("Invert filter applied!\n");
                            break;
                            
                        case 4:
                            applyFilter(image, "pixelate");
                            printf("Pixelate filter applied!\n");
                            break;
                            
                        default:
                            printf("Invalid filter number\n");
                            break;
                    }
                }
                else {
                    printf("No image loaded!\n");
                }
                break;
                
            case 4:
                running = 0;
                break;
                
            default:
                printf("Invalid option\n");
                break;
        }
    }
    
    freeImage(image);
    printf("Program terminated\n");
    
    return 0;
}

Image *createImage(int width, int height) {
    Image *image = NULL;
    
    if (width > 0 && height > 0) {
        image = (Image *) malloc(sizeof(Image));
        image->width = width;
        image->height = height;
        image->pixels = (Color *) malloc(width * height * sizeof(Color));
    }
    
    return image;
}

void freeImage(Image *image) {
    if (image != NULL) {
        free(image->pixels);
        free(image);
    }
}

int loadImage(Image *image, char *filename) {
    FILE *file = fopen(filename, "rb");
    
    if (file != NULL) {
        unsigned char header[54];
        fread(header, sizeof(unsigned char), 54, file);
        
        if (header[0] == 'B' && header[1] == 'M' && header[28] == 24) {
            int width = *(int *) &header[18];
            int height = *(int *) &header[22];
            int rowSize = (width * sizeof(Color) + 3) & ~3;
            int padding = rowSize - width * sizeof(Color);
            
            if (image->width != 0 && image->height != 0) {
                free(image->pixels);
            }
            
            image->width = width;
            image->height = height;
            
            if ((image->pixels = (Color *) malloc(width * height * sizeof(Color))) != NULL) {
                for (int i = 0; i < height; i++) {
                    for (int j = 0; j < width; j++) {
                        unsigned char pixel[3];
                        fread(pixel, sizeof(unsigned char), 3, file);
                        image->pixels[i * width + j].blue = pixel[0];
                        image->pixels[i * width + j].green = pixel[1];
                        image->pixels[i * width + j].red = pixel[2];
                    }
                    
                    fseek(file, padding, SEEK_CUR);
                }
                
                fclose(file);
                return 1;
            }
        }
        
        fclose(file);
    }
    
    return 0;
}

int saveImage(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    
    if (file != NULL) {
        int rowSize = (image->width * sizeof(Color) + 3) & ~3;
        int padding = rowSize - image->width * sizeof(Color);
        unsigned char header[54] = {0};
        *(short int *) &header[0] = 0x4D42;
        *(int *) &header[2] = 54 + (rowSize * image->height);
        *(int *) &header[10] = 54;
        *(int *) &header[14] = 40;
        *(int *) &header[18] = image->width;
        *(int *) &header[22] = image->height;
        *(short int *) &header[26] = 1;
        *(short int *) &header[28] = 24;
        
        fwrite(header, sizeof(unsigned char), 54, file);
        
        for (int i = 0; i < image->height; i++) {
            for (int j = 0; j < image->width; j++) {
                unsigned char pixel[3] = {0};
                pixel[0] = image->pixels[i * image->width + j].blue;
                pixel[1] = image->pixels[i * image->width + j].green;
                pixel[2] = image->pixels[i * image->width + j].red;
                fwrite(pixel, sizeof(unsigned char), 3, file);
            }
            
            for (int j = 0; j < padding; j++) {
                fputc(0, file);
            }
        }
        
        fclose(file);
        return 1;
    }
    
    return 0;
}

void applyFilter(Image *image, char *filterName) {
    if (strcmp("grayscale", filterName) == 0) {
        grayscaleFilter(image);
    }
    else if (strcmp("sepia", filterName) == 0) {
        sepiaFilter(image);
    }
    else if (strcmp("invert", filterName) == 0) {
        invertFilter(image);
    }
    else if (strcmp("pixelate", filterName) == 0) {
        pixelateFilter(image);
    }
    else {
        printf("Invalid filter name\n");
    }
}

void grayscaleFilter(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            unsigned char r = image->pixels[i * image->width + j].red;
            unsigned char g = image->pixels[i * image->width + j].green;
            unsigned char b = image->pixels[i * image->width + j].blue;
            unsigned char gray = (unsigned char) (0.2989 * r + 0.5870 * g + 0.1140 * b);
            image->pixels[i * image->width + j].red = gray;
            image->pixels[i * image->width + j].green = gray;
            image->pixels[i * image->width + j].blue = gray;
        }
    }
}

void sepiaFilter(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            unsigned char r = image->pixels[i * image->width + j].red;
            unsigned char g = image->pixels[i * image->width + j].green;
            unsigned char b = image->pixels[i * image->width + j].blue;
            unsigned char sred = (unsigned char) (0.393 * r + 0.769 * g + 0.189 * b);
            unsigned char sgreen = (unsigned char) (0.349 * r + 0.686 * g + 0.168 * b);
            unsigned char sblue = (unsigned char) (0.272 * r + 0.534 * g + 0.131 * b);
            image->pixels[i * image->width + j].red = (sred > MAX_PIXEL_VALUE) ? MAX_PIXEL_VALUE : sred;
            image->pixels[i * image->width + j].green = (sgreen > MAX_PIXEL_VALUE) ? MAX_PIXEL_VALUE : sgreen;
            image->pixels[i * image->width + j].blue = (sblue > MAX_PIXEL_VALUE) ? MAX_PIXEL_VALUE : sblue;
        }
    }
}

void invertFilter(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            image->pixels[i * image->width + j].red = MAX_PIXEL_VALUE - image->pixels[i * image->width + j].red;
            image->pixels[i * image->width + j].green = MAX_PIXEL_VALUE - image->pixels[i * image->width + j].green;
            image->pixels[i * image->width + j].blue = MAX_PIXEL_VALUE - image->pixels[i * image->width + j].blue;
        }
    }
}

void pixelateFilter(Image *image) {
    int blockSize = 10;
    
    for (int i = 0; i < image->height; i += blockSize) {
        for (int j = 0; j < image->width; j += blockSize) {
            int pixelCount = 0;
            int redSum = 0;
            int greenSum = 0;
            int blueSum = 0;
            
            for (int k = i; k < i + blockSize && k < image->height; k++) {
                for (int l = j; l < j + blockSize && l < image->width; l++) {
                    redSum += image->pixels[k * image->width + l].red;
                    greenSum += image->pixels[k * image->width + l].green;
                    blueSum += image->pixels[k * image->width + l].blue;
                    pixelCount++;
                }
            }
            
            unsigned char redAvg = (unsigned char) (redSum / pixelCount);
            unsigned char greenAvg = (unsigned char) (greenSum / pixelCount);
            unsigned char blueAvg = (unsigned char) (blueSum / pixelCount);
            
            for (int k = i; k < i + blockSize && k < image->height; k++) {
                for (int l = j; l < j + blockSize && l < image->width; l++) {
                    image->pixels[k * image->width + l].red = redAvg;
                    image->pixels[k * image->width + l].green = greenAvg;
                    image->pixels[k * image->width + l].blue = blueAvg;
                }
            }
        }
    }
}