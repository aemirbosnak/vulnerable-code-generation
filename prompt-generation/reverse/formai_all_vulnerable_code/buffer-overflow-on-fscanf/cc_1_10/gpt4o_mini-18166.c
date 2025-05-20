//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WATERMARK_LENGTH 256

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *pixels;
} Image;

// Function to read a P6 PPM image from a file
Image* readPPM(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    char format[3];
    fscanf(file, "%s\n", format);
    if (strcmp(format, "P6") != 0) {
        fprintf(stderr, "Unsupported file format: %s\n", format);
        fclose(file);
        return NULL;
    }

    int width, height, maxval;
    fscanf(file, "%d %d\n%d\n", &width, &height, &maxval);

    Image *img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->pixels = malloc(width * height * sizeof(Pixel));

    fread(img->pixels, sizeof(Pixel), width * height, file);
    fclose(file);
    
    return img;
}

// Function to write a P6 PPM image to a file
void writePPM(const char *filename, const Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->pixels, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

// Function to embed watermark into the image
void embedWatermark(Image *img, const char *watermark) {
    int watermarkLength = strlen(watermark);
    int index = 0;

    for (int i = 0; i < img->width * img->height && index < watermarkLength; ++i) {
        // Embed watermark bit in Least Significant Bit of the red channel
        img->pixels[i].r = (img->pixels[i].r & ~1) | (watermark[index] & 1);
        index++;
        
        if (index < watermarkLength) {
            // Embed next watermark bit in Least Significant Bit of the green channel
            img->pixels[i].g = (img->pixels[i].g & ~1) | ((watermark[index] >> 1) & 1);
            index++;
        }

        if (index < watermarkLength) {
            // Embed next watermark bit in Least Significant Bit of the blue channel
            img->pixels[i].b = (img->pixels[i].b & ~1) | ((watermark[index] >> 2) & 1);
            index++;
        }
    }
}

// Function to extract watermark from the image
void extractWatermark(const Image *img, char *watermark, int maxLength) {
    int index = 0;
    for (int i = 0; i < img->width * img->height && index < maxLength; ++i) {
        watermark[index] = 0;

        // Read watermark bits from the LSB of the RGB channels
        watermark[index] |= (img->pixels[i].r & 1);
        if (index < maxLength) {
            watermark[index] |= ((img->pixels[i].g & 1) << 1);
        }
        if (index < maxLength) {
            watermark[index] |= ((img->pixels[i].b & 1) << 2);
        }
        index++;
    }
    watermark[index] = '\0'; // Null terminate the string
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s input.ppm output.ppm watermark\n", argv[0]);
        return 1;
    }

    const char *inputFile = argv[1];
    const char *outputFile = argv[2];
    const char *watermark = argv[3];

    if (strlen(watermark) > MAX_WATERMARK_LENGTH) {
        fprintf(stderr, "Watermark is too long (max %d characters).\n", MAX_WATERMARK_LENGTH);
        return 1;
    }

    // Read the image
    Image *image = readPPM(inputFile);
    if (!image) {
        return 1;
    }

    // Embed the watermark
    embedWatermark(image, watermark);
    
    // Write the watermarked image
    writePPM(outputFile, image);
    
    // Prepare for extraction
    char extractedWatermark[MAX_WATERMARK_LENGTH + 1];
    extractWatermark(image, extractedWatermark, MAX_WATERMARK_LENGTH);
    
    printf("Extracted watermark: %s\n", extractedWatermark);

    // Clean up
    free(image->pixels);
    free(image);
    
    return 0;
}