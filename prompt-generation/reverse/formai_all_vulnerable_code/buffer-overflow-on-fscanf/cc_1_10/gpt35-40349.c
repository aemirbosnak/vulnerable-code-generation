//FormAI DATASET v1.0 Category: Image Editor ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Pixel{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
}Pixel;

typedef struct Image{
    char format[3];
    int width;
    int height;
    int max_val;
    Pixel** pixels;
}Image;

Image* read_ppm(char* filename){ //function to read a ppm file
    FILE* fp = fopen(filename, "rb");
    if(fp == NULL){
        printf("Error: File '%s' could not be opened.\n", filename);
        return NULL;
    }

    Image* img = (Image*)malloc(sizeof(Image));
    fscanf(fp, "%s\n", img->format);
    
    if(strcmp(img->format, "P6") != 0){
        printf("Error: File format for '%s' not supported. Only P6 is currently supported.\n", filename);
        free(img);
        fclose(fp);
        return NULL;
    }
    
    fscanf(fp, "%d %d %d\n", &img->width, &img->height, &img->max_val);
    
    img->pixels = (Pixel**)malloc(sizeof(Pixel*) * img->height);
    for(int i=0; i<img->height; i++){
        img->pixels[i] = (Pixel*)malloc(sizeof(Pixel) * img->width);
        fread(img->pixels[i], sizeof(Pixel), img->width, fp);
    }
    
    fclose(fp);
    return img;
}

void save_ppm(Image* img, char* filename){ //function to save an image to a ppm file
    FILE* fp = fopen(filename, "wb");
    fprintf(fp, "%s\n%d %d\n%d\n", img->format, img->width, img->height, img->max_val);
    for(int i=0; i<img->height; i++){
        fwrite(img->pixels[i], sizeof(Pixel), img->width, fp);
    }
    fclose(fp);
}

void free_image(Image* img){ //function to free an image
    for(int i=0; i<img->height; i++){
        free(img->pixels[i]);
    }
    free(img->pixels);
    free(img);
}

void grayscale(Image* img){ //function to convert an image to grayscale
    for(int i=0; i<img->height; i++){
        for(int j=0; j<img->width; j++){
            unsigned int gray = 0.299 * img->pixels[i][j].red + 0.587 * img->pixels[i][j].green + 0.114 * img->pixels[i][j].blue;
            img->pixels[i][j].red = gray;
            img->pixels[i][j].green = gray;
            img->pixels[i][j].blue = gray;
        }
    }
}

void invert(Image* img){ //function to invert the colors of an image
    for(int i=0; i<img->height; i++){
        for(int j=0; j<img->width; j++){
            img->pixels[i][j].red = img->max_val - img->pixels[i][j].red;
            img->pixels[i][j].green = img->max_val - img->pixels[i][j].green;
            img->pixels[i][j].blue = img->max_val - img->pixels[i][j].blue;
        }
    }
}

void pixelate(Image* img, int block_size){ //function to pixelate an image
    for(int i=0; i<img->height; i+=block_size){
        for(int j=0; j<img->width; j+=block_size){
            int block_red = 0;
            int block_green = 0;
            int block_blue = 0;
            for(int k=i; k<i+block_size && k<img->height; k++){
                for(int l=j; l<j+block_size && l<img->width; l++){
                    block_red += img->pixels[k][l].red;
                    block_green += img->pixels[k][l].green;
                    block_blue += img->pixels[k][l].blue;
                }
            }
            int pixels_in_block = block_size * block_size;
            int avg_red = block_red / pixels_in_block;
            int avg_green = block_green / pixels_in_block;
            int avg_blue = block_blue / pixels_in_block;
            for(int k=i; k<i+block_size && k<img->height; k++){
                for(int l=j; l<j+block_size && l<img->width; l++){
                    img->pixels[k][l].red = avg_red;
                    img->pixels[k][l].green = avg_green;
                    img->pixels[k][l].blue = avg_blue;
                }
            }
        }
    }
}

int main(){
    Image* img = read_ppm("input.ppm");
    if(img == NULL){
        return 1;
    }
    
    //grayscale
    grayscale(img);
    save_ppm(img, "grayscale.ppm");
    
    //invert
    invert(img);
    save_ppm(img, "inverted.ppm");
    
    //pixelate
    pixelate(img, 32);
    save_ppm(img, "pixelated.ppm");
    
    free_image(img);
    return 0;
}