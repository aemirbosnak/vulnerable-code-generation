//FormAI DATASET v1.0 Category: Image compression ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define BLOCK_SIZE 8

typedef struct {
    unsigned char R;
    unsigned char G;
    unsigned char B;
} pixel;

typedef struct {
    pixel *data;
    int width;
    int height;
} image;

// Function prototypes
bool loadImage(image *img, const char *filename);
bool saveImage(image *img, const char *filename);
void freeImage(image *img);
void compress(image *img);

int main(int argc, char *argv[]) {
    // Check for correct usage
    if(argc != 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    // Load the image from file
    image img;
    if(!loadImage(&img, argv[1])) {
        printf("Error: Failed to load image '%s'\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    printf("Successfully loaded image '%s'\n", argv[1]);
    
    // Compress the image
    compress(&img);
    printf("Successfully compressed image\n");
    
    // Save the compressed image to file
    if(!saveImage(&img, argv[2])) {
        printf("Error: Failed to save compressed image to file '%s'\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    printf("Successfully saved compressed image to file '%s'\n", argv[2]);
    
    // Free the image data
    freeImage(&img);
    
    return 0;
}

bool loadImage(image *img, const char *filename) {
    // Open the image file
    FILE *file = fopen(filename, "rb");
    if(!file) {
        printf("Error: Failed to open image file '%s'\n", filename);
        return false;
    }
    
    // Read the image size
    char header[54];
    fread(header, sizeof(char), 54, file);
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    
    // Read the image data
    int rowSize = width * 3;
    while(rowSize % 4 != 0) {
        rowSize++;
    }
    int dataSize = rowSize * height;
    unsigned char *data = (unsigned char*)malloc(sizeof(unsigned char) * dataSize);
    fread(data, sizeof(unsigned char), dataSize, file);
    
    // Close the image file
    fclose(file);
    
    // Allocate memory for the image data
    img->data = (pixel*)malloc(sizeof(pixel) * width * height);
    img->width = width;
    img->height = height;
    
    // Convert the raw image data to pixel data
    int dataIndex = 0;
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            pixel px;
            px.B = data[dataIndex++];
            px.G = data[dataIndex++];
            px.R = data[dataIndex++];
            img->data[(height - y - 1) * width + x] = px;
        }
        dataIndex += rowSize - (width * 3);
    }
    
    // Free the raw image data
    free(data);
    
    return true;
}

bool saveImage(image *img, const char *filename) {
    // Open the output file
    FILE *file = fopen(filename, "wb");
    if(!file) {
        printf("Error: Failed to open output file '%s'\n", filename);
        return false;
    }
    
    // Write the BMP header
    unsigned char header[54] = {
        0x42, 0x4D,
        0x36, 0xCF, 0x0E, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x36, 0x00, 0x00, 0x00,
        0x28, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0xCC, 0x0E, 0x00, 0x00,
        0xCC, 0x0E, 0x00, 0x00,
        0x01, 0x00, 0x18, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00
    };
    *(int*)&header[18] = img->width;
    *(int*)&header[22] = img->height;
    fwrite(header, sizeof(unsigned char), 54, file);
    
    // Write the pixel data in rows of 4-byte multiples
    int rowSize = img->width * 3;
    while(rowSize % 4 != 0) {
        rowSize++;
    }
    unsigned char *data = (unsigned char*)malloc(sizeof(unsigned char) * rowSize * img->height);
    int dataIndex = 0;
    for(int y = img->height - 1; y >= 0; y--) {
        for(int x = 0; x < img->width; x++) {
            data[dataIndex++] = img->data[y * img->width + x].B;
            data[dataIndex++] = img->data[y * img->width + x].G;
            data[dataIndex++] = img->data[y * img->width + x].R;
        }
        dataIndex += rowSize - (img->width * 3);
    }
    fwrite(data, sizeof(unsigned char), rowSize * img->height, file);
    
    // Close the output file
    fclose(file);
    
    // Free the pixel data
    free(data);
    
    return true;
}

void freeImage(image *img) {
    // Free the image data
    free(img->data);
}

void compress(image *img) {
    // Calculate the number of blocks
    int nBlocksX = img->width / BLOCK_SIZE;
    int nBlocksY = img->height / BLOCK_SIZE;
    int nBlocks = nBlocksX * nBlocksY;
    
    // Allocate memory for the compressed image data
    pixel *compressedData = (pixel*)malloc(sizeof(pixel) * nBlocks * BLOCK_SIZE * BLOCK_SIZE);
    
    // Compress each block
    int compressedDataIndex = 0;
    for(int y = 0; y < nBlocksY; y++) {
        for(int x = 0; x < nBlocksX; x++) {
            // Get the block bounds
            int startX = x * BLOCK_SIZE;
            int startY = y * BLOCK_SIZE;
            int endX = startX + BLOCK_SIZE;
            int endY = startY + BLOCK_SIZE;
            
            // Compress the block
            pixel averagePx = {0, 0, 0};
            for(int bx = startX; bx < endX; bx++) {
                for(int by = startY; by < endY; by++) {
                    pixel px = img->data[by * img->width + bx];
                    averagePx.B += px.B;
                    averagePx.G += px.G;
                    averagePx.R += px.R;
                }
            }
            averagePx.B /= BLOCK_SIZE * BLOCK_SIZE;
            averagePx.G /= BLOCK_SIZE * BLOCK_SIZE;
            averagePx.R /= BLOCK_SIZE * BLOCK_SIZE;
            for(int bx = startX; bx < endX; bx++) {
                for(int by = startY; by < endY; by++) {
                    compressedData[compressedDataIndex++] = averagePx;
                }
            }
        }
    }
    
    // Free the original image data
    free(img->data);
    
    // Update the image data with the compressed data
    img->data = compressedData;
    img->width = nBlocksX * BLOCK_SIZE;
    img->height = nBlocksY * BLOCK_SIZE;
}