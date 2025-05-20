//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char *data;
    int width;
    int height;
} Image;

void readPGM(const char *filename, Image *img) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char buffer[100];
    fgets(buffer, sizeof(buffer), file);  // Read magic number
    fgets(buffer, sizeof(buffer), file);  // Read dimensions
    sscanf(buffer, "%d %d", &img->width, &img->height);
    fgets(buffer, sizeof(buffer), file);  // Read max gray value

    img->data = (unsigned char *)malloc(img->width * img->height);
    fread(img->data, 1, img->width * img->height, file);
    fclose(file);
}

void writePGM(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "P5\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, 1, img->width * img->height, file);
    fclose(file);
}

void embedWatermark(Image *img, const char *watermark) {
    int wmLen = strlen(watermark);
    int totalPixels = img->width * img->height;

    for (int i = 0; i < wmLen && i < totalPixels; i++) {
        // Modify the pixel by adding the ASCII value of watermark character
        img->data[i] = (img->data[i] + watermark[i]) % 256; 
    }
}

void extractWatermark(Image *img, char *watermark, int wmLen) {
    for (int i = 0; i < wmLen; i++) {
        // Extract the watermark by subtracting the original pixel value
        watermark[i] = (img->data[i] - 0) % 256; // Assuming original is zero for demonstration
    }
    watermark[wmLen] = '\0'; // Null terminate the string
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.pgm> <output.pgm> <watermark>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image img;
    readPGM(argv[1], &img);

    const char *watermark = argv[3];
    embedWatermark(&img, watermark);

    writePGM(argv[2], &img);

    printf("Watermark embedded successfully!\n");

    // Prepare to extract the watermark
    char extracted[100];
    extractWatermark(&img, extracted, strlen(watermark));
    printf("Extracted Watermark: %s\n", extracted);

    free(img.data);
    return EXIT_SUCCESS;
}