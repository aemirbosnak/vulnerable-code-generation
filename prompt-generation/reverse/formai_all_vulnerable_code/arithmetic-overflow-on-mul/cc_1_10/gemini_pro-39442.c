//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512
#define WATERMARK_WIDTH 64
#define WATERMARK_HEIGHT 64

// Load the image from a file
unsigned char* load_image(char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Read the image header
    unsigned char header[54];
    fread(header, 1, 54, file);

    // Get the image width and height
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Allocate memory for the image data
    unsigned char* data = malloc(width * height * 3);
    if (data == NULL) {
        perror("Error allocating memory for image data");
        exit(1);
    }

    // Read the image data
    fread(data, 1, width * height * 3, file);

    // Close the file
    fclose(file);

    return data;
}

// Save the image to a file
void save_image(char* filename, unsigned char* data) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Write the image header
    unsigned char header[54];
    header[0] = 'B';
    header[1] = 'M';
    header[2] = (unsigned char)(54 + IMAGE_WIDTH * IMAGE_HEIGHT * 3);
    header[3] = 0;
    header[4] = 0;
    header[5] = 0;
    header[6] = 0;
    header[7] = 0;
    header[8] = 0;
    header[9] = 0;
    header[10] = 0;
    header[11] = 0;
    header[12] = (unsigned char)(IMAGE_WIDTH);
    header[13] = (unsigned char)(IMAGE_WIDTH >> 8);
    header[14] = (unsigned char)(IMAGE_HEIGHT);
    header[15] = (unsigned char)(IMAGE_HEIGHT >> 8);
    header[16] = 1;
    header[17] = 0;
    header[18] = 24;
    header[19] = 0;
    header[20] = 0;
    header[21] = 0;
    header[22] = (unsigned char)(IMAGE_WIDTH * IMAGE_HEIGHT * 3);
    header[23] = (unsigned char)(IMAGE_WIDTH * IMAGE_HEIGHT * 3 >> 8);
    header[24] = (unsigned char)(IMAGE_WIDTH * IMAGE_HEIGHT * 3 >> 16);
    header[25] = (unsigned char)(IMAGE_WIDTH * IMAGE_HEIGHT * 3 >> 24);
    header[26] = 0;
    header[27] = 0;
    header[28] = 0;
    header[29] = 0;
    header[30] = 0;
    header[31] = 0;
    fwrite(header, 1, 54, file);

    // Write the image data
    fwrite(data, 1, IMAGE_WIDTH * IMAGE_HEIGHT * 3, file);

    // Close the file
    fclose(file);
}

// Embed the watermark in the image
void embed_watermark(unsigned char* image, unsigned char* watermark) {
    // Get the mean and standard deviation of the image
    double mean = 0;
    double stddev = 0;
    for (int i = 0; i < IMAGE_WIDTH * IMAGE_HEIGHT * 3; i++) {
        mean += image[i];
    }
    mean /= IMAGE_WIDTH * IMAGE_HEIGHT * 3;
    for (int i = 0; i < IMAGE_WIDTH * IMAGE_HEIGHT * 3; i++) {
        stddev += pow(image[i] - mean, 2);
    }
    stddev = sqrt(stddev / (IMAGE_WIDTH * IMAGE_HEIGHT * 3 - 1));

    // Embed the watermark in the image
    for (int i = 0; i < WATERMARK_WIDTH * WATERMARK_HEIGHT; i++) {
        int x = i % WATERMARK_WIDTH;
        int y = i / WATERMARK_WIDTH;
        int index = (y * IMAGE_WIDTH + x) * 3;
        image[index] = (unsigned char)(mean + watermark[i] * stddev);
    }
}

// Extract the watermark from the image
unsigned char* extract_watermark(unsigned char* image) {
    // Get the mean and standard deviation of the image
    double mean = 0;
    double stddev = 0;
    for (int i = 0; i < IMAGE_WIDTH * IMAGE_HEIGHT * 3; i++) {
        mean += image[i];
    }
    mean /= IMAGE_WIDTH * IMAGE_HEIGHT * 3;
    for (int i = 0; i < IMAGE_WIDTH * IMAGE_HEIGHT * 3; i++) {
        stddev += pow(image[i] - mean, 2);
    }
    stddev = sqrt(stddev / (IMAGE_WIDTH * IMAGE_HEIGHT * 3 - 1));

    // Extract the watermark from the image
    unsigned char* watermark = malloc(WATERMARK_WIDTH * WATERMARK_HEIGHT);
    for (int i = 0; i < WATERMARK_WIDTH * WATERMARK_HEIGHT; i++) {
        int x = i % WATERMARK_WIDTH;
        int y = i / WATERMARK_WIDTH;
        int index = (y * IMAGE_WIDTH + x) * 3;
        watermark[i] = (unsigned char)((image[index] - mean) / stddev);
    }

    return watermark;
}

int main() {
    // Load the image
    unsigned char* image = load_image("image.bmp");

    // Load the watermark
    unsigned char* watermark = load_image("watermark.bmp");

    // Embed the watermark in the image
    embed_watermark(image, watermark);

    // Save the watermarked image
    save_image("watermarked_image.bmp", image);

    // Extract the watermark from the watermarked image
    unsigned char* extracted_watermark = extract_watermark(image);

    // Save the extracted watermark
    save_image("extracted_watermark.bmp", extracted_watermark);

    // Free the memory
    free(image);
    free(watermark);
    free(extracted_watermark);

    return 0;
}