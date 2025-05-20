//FormAI DATASET v1.0 Category: Image Editor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// structure that holds the information about an image
typedef struct {
    int width;
    int height;
    unsigned char* data;
} Image;

// function that loads an image from a file
Image* loadImage(char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: could not open file %s.\n", filename);
        return NULL;
    }
    
    // read header
    int width, height, maxval;
    fscanf(fp, "P6\n%d %d\n%d\n", &width, &height, &maxval);
    
    // allocate memory for image data
    unsigned char* data = (unsigned char*) malloc(width * height * 3);
    if (!data) {
        printf("Error: could not allocate memory for image data.\n");
        return NULL;
    }
    
    // read image data
    fread(data, 3, width * height, fp);
    
    // create image structure
    Image* image = (Image*) malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = data;
    
    // close file
    fclose(fp);
    
    return image;
}

// function that saves an image to a file
void saveImage(char* filename, Image* image) {
    FILE* fp = fopen(filename, "wb");
    if (!fp) {
        printf("Error: could not open file %s.\n", filename);
        return;
    }
    
    // write header
    fprintf(fp, "P6\n%d %d\n255\n", image->width, image->height);
    
    // write image data
    fwrite(image->data, 3, image->width * image->height, fp);
    
    // close file
    fclose(fp);
}

// function that applies a grayscale transformation to an image
void grayscale(Image* image) {
    int i;
    unsigned char r, g, b, gray;
    
    for (i = 0; i < image->width * image->height * 3; i += 3) {
        // read red, green, and blue components
        r = image->data[i];
        g = image->data[i+1];
        b = image->data[i+2];
        
        // compute grayscale value
        gray = (unsigned char) (0.299 * r + 0.587 * g + 0.114 * b);
        
        // write grayscale value to each component
        image->data[i] = gray;
        image->data[i+1] = gray;
        image->data[i+2] = gray;
    }
}

int main() {
    // load image from file
    Image* image = loadImage("image.ppm");
    if (!image) {
        return 1;
    }
    
    // apply grayscale transformation
    grayscale(image);
    
    // save image to file
    saveImage("image_gray.ppm", image);
    
    // free memory
    free(image->data);
    free(image);
    
    return 0;
}