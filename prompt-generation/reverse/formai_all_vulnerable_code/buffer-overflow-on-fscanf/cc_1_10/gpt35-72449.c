//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_IMAGE_SIZE 1000

// Struct to store image data
typedef struct{
    int width;
    int height;
    unsigned char red[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
    unsigned char green[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
    unsigned char blue[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
} ImageData;

// Function to read image from file
ImageData readImage(char *filename){
    ImageData imgData;
    FILE *f = fopen(filename,"rb");
    if(f==NULL){
        printf("Error opening file\n");
        exit(1);
    }
    // Read header
    char type[3];
    fscanf(f,"%s\n",type);
    if(type[0]!='P' || type[1]!='6'){
        printf("Invalid image type\n");
        exit(1);
    }
    fscanf(f,"%d %d\n",&imgData.width,&imgData.height);
    int maxVal;
    fscanf(f,"%d\n",&maxVal);
    if(maxVal<0 || maxVal>255){
        printf("Invalid maximum value\n");
        exit(1);
    }
    // Read pixel data
    int x, y;
    for(y=0;y<imgData.height;y++){
        for(x=0;x<imgData.width;x++){
            unsigned char r, g, b;
            fread(&r,1,1,f);
            fread(&g,1,1,f);
            fread(&b,1,1,f);
            imgData.red[x][y] = r;
            imgData.green[x][y] = g;
            imgData.blue[x][y] = b;
        }
    }
    fclose(f);
    return imgData;
}

// Function to write image to file
void writeImage(char *filename, ImageData imgData){
    FILE *f = fopen(filename,"wb");
    if(f==NULL){
        printf("Error opening file\n");
        exit(1);
    }
    // Write header
    fprintf(f,"P6\n");
    fprintf(f,"%d %d\n",imgData.width,imgData.height);
    fprintf(f,"255\n");
    // Write pixel data
    int x, y;
    for(y=0;y<imgData.height;y++){
        for(x=0;x<imgData.width;x++){
            fwrite(&imgData.red[x][y],1,1,f);
            fwrite(&imgData.green[x][y],1,1,f);
            fwrite(&imgData.blue[x][y],1,1,f);
        }
    }
    fclose(f);
}

// Function to flip an image horizontally
ImageData flipHorizontal(ImageData imgData){
    ImageData flipped;
    flipped.width = imgData.width;
    flipped.height = imgData.height;
    int x, y;
    for(y=0;y<flipped.height;y++){
        for(x=0;x<flipped.width;x++){
            flipped.red[x][y] = imgData.red[flipped.width-1-x][y];
            flipped.green[x][y] = imgData.green[flipped.width-1-x][y];
            flipped.blue[x][y] = imgData.blue[flipped.width-1-x][y];
        }
    }
    return flipped;
}

// Function to adjust brightness of an image
ImageData adjustBrightness(ImageData imgData, int amount){
    ImageData adjusted;
    adjusted.width = imgData.width;
    adjusted.height = imgData.height;
    int x, y;
    for(y=0;y<adjusted.height;y++){
        for(x=0;x<adjusted.width;x++){
            int r, g, b;
            r = (int)imgData.red[x][y] + amount;
            g = (int)imgData.green[x][y] + amount;
            b = (int)imgData.blue[x][y] + amount;
            if(r<0) r=0;
            if(r>255) r=255;
            if(g<0) g=0;
            if(g>255) g=255;
            if(b<0) b=0;
            if(b>255) b=255;
            adjusted.red[x][y] = (unsigned char)r;
            adjusted.green[x][y] = (unsigned char)g;
            adjusted.blue[x][y] = (unsigned char)b;
        }
    }
    return adjusted;
}

// Function to adjust contrast of an image
ImageData adjustContrast(ImageData imgData, float amount){
    ImageData adjusted;
    adjusted.width = imgData.width;
    adjusted.height = imgData.height;
    int x, y;
    float factor = (259*(amount+255))/(255*(259-amount));
    for(y=0;y<adjusted.height;y++){
        for(x=0;x<adjusted.width;x++){
            int r, g, b;
            r = (int)factor*(imgData.red[x][y]-128) + 128;
            g = (int)factor*(imgData.green[x][y]-128) + 128;
            b = (int)factor*(imgData.blue[x][y]-128) + 128;
            if(r<0) r=0;
            if(r>255) r=255;
            if(g<0) g=0;
            if(g>255) g=255;
            if(b<0) b=0;
            if(b>255) b=255;
            adjusted.red[x][y] = (unsigned char)r;
            adjusted.green[x][y] = (unsigned char)g;
            adjusted.blue[x][y] = (unsigned char)b;
        }
    }
    return adjusted;
}

int main(){
    // Read image from file
    ImageData imgData = readImage("input.ppm");
    
    // Flip image horizontally
    ImageData flipped = flipHorizontal(imgData);
    
    // Adjust brightness
    ImageData brightened = adjustBrightness(imgData, 50);
    
    // Adjust contrast
    ImageData contrasted = adjustContrast(imgData, 50.0);
    
    // Write images to files
    writeImage("flipped.ppm", flipped);
    writeImage("brightened.ppm", brightened);
    writeImage("contrasted.ppm", contrasted);
    
    return 0;
}