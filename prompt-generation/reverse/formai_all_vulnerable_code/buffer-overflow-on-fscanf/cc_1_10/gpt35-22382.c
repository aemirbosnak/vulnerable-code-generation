//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//structure to hold image details
struct Image{
    int width;
    int height;
    int maxVal;
    int **data;
};

//function to read an image from file
void readImage(char *fileName, struct Image *image){
    FILE *fp = fopen(fileName, "r");
    if(fp == NULL){
        printf("Error! Could not open file\n");
        exit(-1);
    }

    char ch;
    //eliminate comments at start of file
    while((ch = fgetc(fp)) == '#'){
        do{
            ch = fgetc(fp);
        }while(ch != '\n');
    }

    //go back one character to get width and height
    fseek(fp, -1, SEEK_CUR);

    //read width, height and maximum value
    fscanf(fp, "%d%d%d", &image->width, &image->height, &image->maxVal);

    //allocate memory for storing image data
    image->data = (int **)malloc(image->height * sizeof(int *));
    for(int i = 0; i < image->height; i++){
        image->data[i] = (int *)malloc(image->width * sizeof(int));
    }

    //read image data pixel by pixel
    for(int i = 0; i < image->height; i++){
        for(int j = 0; j < image->width; j++){
            fscanf(fp, "%d", &image->data[i][j]);
        }
    }

    fclose(fp);
}

//function to write an image to file
void writeImage(char *fileName, struct Image *image){
    FILE *fp = fopen(fileName, "w");
    if(fp == NULL){
        printf("Error! Could not open file\n");
        exit(-1);
    }

    //write image details to file
    fprintf(fp, "P2\n");
    fprintf(fp, "# Created by Image Processing Program\n");
    fprintf(fp, "%d %d\n", image->width, image->height);
    fprintf(fp, "%d\n", image->maxVal);

    //write pixel values to file
    for(int i = 0; i < image->height; i++){
        for(int j = 0; j < image->width; j++){
            fprintf(fp, "%d ", image->data[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

//function to flip image vertically
void flipVertical(struct Image *image){
    for(int i = 0; i < (image->height)/2; i++){
        for(int j = 0; j < image->width; j++){
            //swap values of pixels across the axis
            int temp = image->data[i][j];
            image->data[i][j] = image->data[image->height-i-1][j];
            image->data[image->height-i-1][j] = temp;
        }
    }
}

//function to increase or decrease contrast of image
void adjustContrast(struct Image *image, int delta){
    float factor = (259 * (delta + 255)) / (255 * (259 - delta));

    for(int i = 0; i < image->height; i++){
        for(int j = 0; j < image->width; j++){
            //adjust pixel value based on the factor
            image->data[i][j] = (int)(factor * (image->data[i][j] - 128) + 128);
        }
    }
}

int main(){
    struct Image image;

    //read image from file
    readImage("input.pgm", &image);

    //Flip image vertically
    flipVertical(&image);

    //Increase contrast of image
    adjustContrast(&image, 20);

    //write image back to file
    writeImage("output.pgm", &image);

    //free memory allocated for storing image data
    for(int i = 0; i < image.height; i++){
        free(image.data[i]);
    }
    free(image.data);

    return 0;
}