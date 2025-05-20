//FormAI DATASET v1.0 Category: Image compression ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_FILENAME_LENGTH 100
#define BLOCK_SIZE 8
#define MAX_PIXEL_VALUE 255

// Function to read the input image file
void readImage(char *filename, uint8_t **image, int *height, int *width)
{
    FILE *fp = fopen(filename, "rb");
    
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    
    // Read image height and width
    fread(height, sizeof(int), 1, fp);
    fread(width, sizeof(int), 1, fp);
    
    // Allocate memory for the image data
    *image = (uint8_t*)malloc((*height) * (*width) * sizeof(uint8_t));
    
    // Read the image data
    fread(*image, sizeof(uint8_t), (*height) * (*width), fp);
    
    fclose(fp);
}

// Function to write the output compressed image file
void writeCompressedImage(char *filename, uint8_t *compressedImage, int compressedSize, int height, int width)
{
    FILE *fp = fopen(filename, "wb");
    
    if (fp == NULL)
    {
        printf("Error writing file!\n");
        exit(1);
    }
    
    // Write image height and width
    fwrite(&height, sizeof(int), 1, fp);
    fwrite(&width, sizeof(int), 1, fp);
    
    // Write the compressed image data
    fwrite(compressedImage, sizeof(uint8_t), compressedSize, fp);
    
    fclose(fp);
}

// Function to compress the image using block-wise differential pulse code modulation (DPCM)
uint8_t *compressImage(uint8_t *image, int height, int width, int *compressedSize)
{
    // First block is not compressed, it is the reference block
    *compressedSize = height * width / BLOCK_SIZE;
    uint8_t *compressedImage = (uint8_t*)malloc((*compressedSize) * sizeof(uint8_t));
    
    int compressedIndex = 0;
    
    for (int i = 0; i < height; i += BLOCK_SIZE)
    {
        for (int j = 0; j < width; j += BLOCK_SIZE)
        {
            // First block is the reference block, don't compress it
            if (i == 0 && j == 0)
            {
                for (int m = i; m < i + BLOCK_SIZE; m++)
                {
                    for (int n = j; n < j + BLOCK_SIZE; n++)
                    {
                        compressedImage[compressedIndex++] = image[m * width + n];
                    }
                }
                
                continue;
            }
            
            // Compress the other blocks using DPCM
            int diff;
            uint8_t prev = image[(i - BLOCK_SIZE) * width + j];
            
            for (int m = i; m < i + BLOCK_SIZE; m++)
            {
                for (int n = j; n < j + BLOCK_SIZE; n++)
                {
                    diff = image[m * width + n] - prev;
                    prev = image[m * width + n];
                    
                    compressedImage[compressedIndex++] = (uint8_t)diff;
                }
            }
        }
    }
    
    return compressedImage;
}

int main()
{
    char inputFilename[MAX_FILENAME_LENGTH];
    char outputFilename[MAX_FILENAME_LENGTH];
    
    printf("Enter the name of the input image file: ");
    scanf("%s", inputFilename);
    
    int height, width;
    uint8_t *image;
    
    readImage(inputFilename, &image, &height, &width);
    printf("Image read successfuly. Height = %d, Width = %d\n", height, width);
    
    int compressedSize;
    uint8_t *compressedImage = compressImage(image, height, width, &compressedSize);
    printf("Image compressed successfully. Compressed size = %d bytes\n", compressedSize);
    
    printf("Enter the name of the output compressed image file: ");
    scanf("%s", outputFilename);
    
    writeCompressedImage(outputFilename, compressedImage, compressedSize, height, width);
    printf("Compressed image written to file successfully.\n");
    
    free(image);
    free(compressedImage);
    
    return 0;
}