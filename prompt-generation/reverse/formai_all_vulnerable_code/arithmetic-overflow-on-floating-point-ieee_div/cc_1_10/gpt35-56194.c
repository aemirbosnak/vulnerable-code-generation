//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 512
#define MAX_BRIGHTNESS 255

void flipImage(unsigned char image[MAX_SIZE][MAX_SIZE], int width, int height){
    unsigned char temp[MAX_SIZE][MAX_SIZE];
    int x, y;
    for(y=0;y<height;y++){
        for(x=0;x<width;x++){
            temp[height-y-1][x] = image[y][x];
        }
    }
    for(y=0;y<height;y++){
        for(x=0;x<width;x++){
            image[y][x] = temp[y][x];
        }
    }
}

void adjustBrightness(unsigned char image[MAX_SIZE][MAX_SIZE], int width, int height, int amount){
    int x, y;
    for(y=0;y<height;y++){
        for(x=0;x<width;x++){
            int newValue = image[y][x] + amount;
            if(newValue > MAX_BRIGHTNESS){
                newValue = MAX_BRIGHTNESS;
            }
            if(newValue < 0){
                newValue = 0;
            }
            image[y][x] = newValue;
        }
    }
}

void adjustContrast(unsigned char image[MAX_SIZE][MAX_SIZE], int width, int height, float amount){
    int x, y;
    float factor = (259.0 * (amount + 255.0)) / (255.0 * (259.0 - amount));
    for(y=0;y<height;y++){
        for(x=0;x<width;x++){
            int newValue = (int)(factor * (image[y][x] - 128) + 128);
            if(newValue > MAX_BRIGHTNESS){
                newValue = MAX_BRIGHTNESS;
            }
            if(newValue < 0){
                newValue = 0;
            }
            image[y][x] = newValue;
        }
    }
}

int main(){
    unsigned char image[MAX_SIZE][MAX_SIZE];
    int width, height;
    FILE *inputFile;
    inputFile = fopen("inputImage.raw", "rb");
    if(inputFile == NULL){
        printf("Error opening input file.");
        return 1;
    }
    fread(image, sizeof(unsigned char), MAX_SIZE*MAX_SIZE, inputFile);
    fclose(inputFile);
    printf("Enter the width and height of the image (up to %d): ", MAX_SIZE);
    scanf("%d %d", &width, &height);
    printf("Enter the filename to save the output: ");
    char filename[100];
    scanf("%s", filename);
    printf("Choose the operation:\n");
    printf("1. Flip image\n");
    printf("2. Adjust brightness\n");
    printf("3. Adjust contrast\n");
    int choice;
    scanf("%d", &choice);
    switch(choice){
        case 1:
            flipImage(image, width, height);
            break;
        case 2:
            printf("Enter the amount to adjust brightness (up to %d): ", MAX_BRIGHTNESS);
            int brightness;
            scanf("%d", &brightness);
            adjustBrightness(image, width, height, brightness);
            break;
        case 3:
            printf("Enter the amount to adjust contrast: ");
            float contrast;
            scanf("%f", &contrast);
            adjustContrast(image, width, height, contrast);
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }
    FILE *outputFile;
    outputFile = fopen(filename, "wb");
    fwrite(image, sizeof(unsigned char), width*height, outputFile);
    fclose(outputFile);
    printf("Done.\n");
    return 0;
}