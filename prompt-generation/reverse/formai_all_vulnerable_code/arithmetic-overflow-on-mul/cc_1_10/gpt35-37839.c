//FormAI DATASET v1.0 Category: Image compression ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

typedef struct pixel {
    unsigned char r,g,b; // red, green, blue values for each pixel
} Pixel;

typedef struct image {
    int width, height; // dimensions of the image in pixels
    int max_val; // maximum color value (usually 255)
    Pixel *pix_array; // 1D array of pixels storing the image data
} Image;

// Function to load image data from a PPM file
Image * load_ppm(char *filename) {
    char c;
    int i,j,k;
    FILE *ppmFile;
    Image *image;

    // Open file for reading
    ppmFile = fopen(filename,"rb");
    if (!ppmFile) {
        perror("failed to open file");
        return NULL;
    }

    // Allocate memory for the Image struct
    image = (Image *) malloc(sizeof(Image));
    if (!image) {
        perror("failed to allocate memory for image");
        return NULL;
    }

    // Read image header
    fscanf(ppmFile,"P6\n");
    // skip comments
    c = getc(ppmFile);
    while (c == '#') {
        while (getc(ppmFile) != '\n');
        c = getc(ppmFile);
    }
    ungetc(c,ppmFile);
    // read image dimensions
    fscanf(ppmFile,"%d %d\n",&image->width,&image->height);
    // read maximum color value
    fscanf(ppmFile,"%d\n",&image->max_val);

    // Allocate memory for pixel data
    image->pix_array = (Pixel *) malloc(image->width * image->height * sizeof(Pixel));
    if (!image->pix_array) {
        perror("failed to allocate memory for pixel data");
        return NULL;
    }

    // Read pixel data
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            k = i * image->width + j;
            fread(&image->pix_array[k].r,1,1,ppmFile);
            fread(&image->pix_array[k].g,1,1,ppmFile);
            fread(&image->pix_array[k].b,1,1,ppmFile);
        }
    }

    // Close file and return image
    fclose(ppmFile);
    return image;
}

// Function to write image data to a PPM file
void save_ppm(char *filename, Image *image) {
    int i,j,k;
    FILE *ppmFile;

    // Open file for writing
    ppmFile = fopen(filename,"wb");
    if (!ppmFile) {
        perror("failed to open file");
        return;
    }

    // Write image header
    fprintf(ppmFile,"P6\n");
    fprintf(ppmFile,"# Created using Image Compression Example program\n");
    fprintf(ppmFile,"%d %d\n",image->width,image->height);
    fprintf(ppmFile,"%d\n",image->max_val);

    // Write pixel data
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            k = i * image->width + j;
            fwrite(&image->pix_array[k].r,1,1,ppmFile);
            fwrite(&image->pix_array[k].g,1,1,ppmFile);
            fwrite(&image->pix_array[k].b,1,1,ppmFile);
        }
    }

    // Close file
    fclose(ppmFile);
}

// Function to compress image using simple run-length encoding
Image * compress_image(Image *image) {
    int i,j,k,count;
    Image *compressed_image;

    // Allocate memory for the compressed image
    compressed_image = (Image *) malloc(sizeof(Image));
    if (!compressed_image) {
        perror("failed to allocate memory for compressed image");
        return NULL;
    }

    // Copy dimensions and maximum color value to compressed image
    compressed_image->width = image->width;
    compressed_image->height = image->height;
    compressed_image->max_val = image->max_val;

    // Allocate memory for compressed pixel data
    compressed_image->pix_array = (Pixel *) malloc(image->width * image->height * sizeof(Pixel));
    if (!compressed_image->pix_array) {
        perror("failed to allocate memory for compressed pixel data");
        return NULL;
    }

    // Compress each row of pixels using run-length encoding
    for (i = 0; i < image->height; i++) {
        j = 0;
        while (j < image->width) {
            // Count the number of pixels with the same color
            count = 0;
            k = i * image->width + j;
            while (k < ((i+1) * image->width) && 
                   image->pix_array[k].r == image->pix_array[i * image->width + j].r &&
                   image->pix_array[k].g == image->pix_array[i * image->width + j].g &&
                   image->pix_array[k].b == image->pix_array[i * image->width + j].b) {
                count++;
                k++;
            }
            // Store the count and the color in the compressed image
            compressed_image->pix_array[i * image->width + j].r = count;
            compressed_image->pix_array[i * image->width + j].g = image->pix_array[i * image->width + j].r;
            compressed_image->pix_array[i * image->width + j].b = image->pix_array[i * image->width + j].r;
            // Move to next color in original image
            j += count;
        }
    }

    // Return the compressed image
    return compressed_image;
}

// Function to decompress image using simple run-length decoding
Image * decompress_image(Image *compressed_image) {
    int i,j,k,count;
    Image *image;

    // Allocate memory for the decompressed image
    image = (Image *) malloc(sizeof(Image));
    if (!image) {
        perror("failed to allocate memory for decompressed image");
        return NULL;
    }

    // Copy dimensions and maximum color value to decompressed image
    image->width = compressed_image->width;
    image->height = compressed_image->height;
    image->max_val = compressed_image->max_val;

    // Allocate memory for decompressed pixel data
    image->pix_array = (Pixel *) malloc(image->width * image->height * sizeof(Pixel));
    if (!image->pix_array) {
        perror("failed to allocate memory for decompressed pixel data");
        return NULL;
    }

    // Decompress each row of pixels using run-length decoding
    for (i = 0; i < compressed_image->height; i++) {
        j = 0;
        while (j < compressed_image->width) {
            // Read the count and the color from the compressed image
            count = compressed_image->pix_array[i * compressed_image->width + j].r;
            // Store the color in the decompressed image
            for (k = 0; k < count; k++) {
                image->pix_array[i * image->width + j + k].r = compressed_image->pix_array[i * compressed_image->width + j].g;
                image->pix_array[i * image->width + j + k].g = compressed_image->pix_array[i * compressed_image->width + j].b;
                image->pix_array[i * image->width + j + k].b = compressed_image->pix_array[i * compressed_image->width + j].b;
            }
            // Move to next color in compressed image
            j++;
        }
    }

    // Return the decompressed image
    return image;
}

int main() {
    Image *image, *compressed_image, *decompressed_image;

    // Load image from file
    image = load_ppm("myimage.ppm");
    if (!image) {
        perror("failed to load image");
        return 1;
    }

    // Compress image using run-length encoding
    compressed_image = compress_image(image);
    if (!compressed_image) {
        perror("failed to compress image");
        return 1;
    }

    // Save compressed image to file
    save_ppm("myimage-compressed.ppm",compressed_image);

    // Decompress image using run-length decoding
    decompressed_image = decompress_image(compressed_image);
    if (!decompressed_image) {
        perror("failed to decompress image");
        return 1;
    }

    // Save decompressed image to file
    save_ppm("myimage-decompressed.ppm",decompressed_image);

    // Free memory
    free(image->pix_array);
    free(image);
    free(compressed_image->pix_array);
    free(compressed_image);
    free(decompressed_image->pix_array);
    free(decompressed_image);

    return 0;
}