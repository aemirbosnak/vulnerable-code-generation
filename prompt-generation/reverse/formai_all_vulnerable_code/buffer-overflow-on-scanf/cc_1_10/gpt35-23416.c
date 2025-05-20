//FormAI DATASET v1.0 Category: Image Editor ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILENAME_LEN 256 // Maximum length of the filename string
#define MAX_IMAGE_SIZE 256 // Maximum size of the image, both width and height should not exceed this value

typedef struct image{
    char filename[MAX_FILENAME_LEN]; // Name of the image file
    int height; // Height of the image
    int width; // Width of the image
    unsigned char imageData[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE][3]; // RGB values of each pixel
}Image;

// Function to read the image file and store the image data in the Image struct
Image* readImage(char* filename){
    FILE* fp = fopen(filename, "rb"); // Open the file in read binary mode
    if(fp == NULL){
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    char magicNumber[3];
    fscanf(fp, "%s\n", magicNumber);
    if(strcmp(magicNumber, "P6") != 0){
        printf("Error: Invalid magic number in file %s, expected P6\n", filename);
        fclose(fp);
        return NULL;
    }

    Image* img = (Image*) malloc(sizeof(Image));
    strcpy(img->filename, filename);

    fscanf(fp, "%d %d\n", &img->width, &img->height);
    if(img->width > MAX_IMAGE_SIZE || img->height > MAX_IMAGE_SIZE){
        printf("Error: Image size too large, maximum supported size is %dx%d\n", MAX_IMAGE_SIZE, MAX_IMAGE_SIZE);
        fclose(fp);
        return NULL;
    }

    int maxValue;
    fscanf(fp, "%d\n", &maxValue);
    if(maxValue != 255){
        printf("Error: Invalid maximum value in file %s, expected 255\n", filename);
        fclose(fp);
        return NULL;
    }

    for(int i=0;i<img->height;i++){
        for(int j=0;j<img->width;j++){
            unsigned char r,g,b;
            fread(&r, 1, 1, fp);
            fread(&g, 1, 1, fp);
            fread(&b, 1, 1, fp);
            img->imageData[i][j][0] = r;
            img->imageData[i][j][1] = g;
            img->imageData[i][j][2] = b;
        }
    }

    fclose(fp);
    return img;
}

// Function to write the image data stored in the Image struct to a new file
void writeImage(Image* img){
    char newFilename[MAX_FILENAME_LEN];
    sprintf(newFilename, "edited_%s", img->filename);
    FILE* fp = fopen(newFilename, "wb"); // Open the file in write binary mode
    if(fp == NULL){
        printf("Error creating file %s\n", newFilename);
        return;
    }

    fprintf(fp, "P6\n");
    fprintf(fp, "%d %d\n", img->width, img->height);
    fprintf(fp, "255\n");

    for(int i=0;i<img->height;i++){
        for(int j=0;j<img->width;j++){
            unsigned char r = img->imageData[i][j][0];
            unsigned char g = img->imageData[i][j][1];
            unsigned char b = img->imageData[i][j][2];
            fwrite(&r, 1, 1, fp);
            fwrite(&g, 1, 1, fp);
            fwrite(&b, 1, 1, fp);
        }
    }

    printf("Image saved as %s\n", newFilename);
    fclose(fp);
}

// Function to invert the colors of the image
void invertColors(Image* img){
    for(int i=0;i<img->height;i++){
        for(int j=0;j<img->width;j++){
            img->imageData[i][j][0] = 255 - img->imageData[i][j][0];
            img->imageData[i][j][1] = 255 - img->imageData[i][j][1];
            img->imageData[i][j][2] = 255 - img->imageData[i][j][2];
        }
    }
}

int main(){
    char filename[MAX_FILENAME_LEN];
    printf("Enter the filename of the image you want to edit: ");
    scanf("%s", filename);

    Image* img = readImage(filename);
    if(img == NULL){
        return -1;
    }

    printf("Image dimensions: %dx%d\n", img->width, img->height);

    printf("Menu:\n");
    printf("1. Invert colors\n");
    printf("2. Save and exit\n");

    int option;
    scanf("%d", &option);
    while(option != 2){
        if(option == 1){
            invertColors(img);
            printf("Colors inverted!\n");
        }
        else{
            printf("Invalid option, try again:\n");
        }

        printf("Menu:\n");
        printf("1. Invert colors\n");
        printf("2. Save and exit\n");

        scanf("%d", &option);
    }

    writeImage(img);

    free(img);

    return 0;
}