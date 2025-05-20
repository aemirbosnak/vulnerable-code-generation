//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define BMP_HEADER_SIZE 54
#define MAX_IMAGE_SIZE 1024 * 1024  // 1 MB maximum for simplicity
#define BMP_PIXEL_ARRAY_OFFSET 10  // Offset to the pixel array in BMP header
#define BMP_WIDTH_OFFSET 18         // Offset to the width in BMP header
#define BMP_HEIGHT_OFFSET 22        // Offset to the height in BMP header

// Function to read a BMP image
uint8_t* load_bmp(const char* filename, int* width, int* height) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("In the ruins of our world, I couldn't find the file: %s\n", filename);
        return NULL;
    }

    uint8_t header[BMP_HEADER_SIZE];
    fread(header, sizeof(uint8_t), BMP_HEADER_SIZE, file);

    *width = *(int*)&header[BMP_WIDTH_OFFSET];
    *height = *(int*)&header[BMP_HEIGHT_OFFSET];

    int row_padded = (*width * 3 + 3) & (~3);
    uint8_t* data = (uint8_t*)malloc(row_padded * (*height));
    fseek(file, *(int*)&header[BMP_PIXEL_ARRAY_OFFSET], SEEK_SET);
    fread(data, sizeof(uint8_t), row_padded * (*height), file);
    
    fclose(file);
    
    printf("From the ashes, I have unearthed a %dx%d BMP image.\n", *width, *height);
    return data;
}

// Function to save BMP image
void save_bmp(const char* filename, uint8_t* data, int width, int height) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        printf("The file cannot be saved, lost among the ruins: %s\n", filename);
        return;
    }

    uint8_t header[BMP_HEADER_SIZE] = { 0 };
    header[0] = 'B'; // 'B'
    header[1] = 'M'; // 'M'
    *(int*)&header[2] = BMP_HEADER_SIZE + width * height * 3; // File size
    *(int*)&header[BMP_PIXEL_ARRAY_OFFSET] = BMP_HEADER_SIZE; // Bitmap array offset

    *(int*)&header[BMP_WIDTH_OFFSET] = width;
    *(int*)&header[BMP_HEIGHT_OFFSET] = height;

    fwrite(header, sizeof(uint8_t), BMP_HEADER_SIZE, file);
    int row_padded = (width * 3 + 3) & (~3);
    fwrite(data, sizeof(uint8_t), row_padded * height, file);
    
    fclose(file);
    
    printf("I have restored the image to: %s in this barren wasteland.\n", filename);
}

// Function to apply grayscale filter on the image
void apply_grayscale(uint8_t* data, int width, int height) {
    int row_padded = (width * 3 + 3) & (~3);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            uint8_t* pixel = data + y * row_padded + x * 3;
            uint8_t gray = (pixel[0] + pixel[1] + pixel[2]) / 3;
            pixel[0] = pixel[1] = pixel[2] = gray; // Set RGB to the gray
        }
    }
    printf("The colors of this world have faded into shades of gray.\n");
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Fellow survivor, you must provide input and output file names!\n");
        return 1;
    }

    const char* input_file = argv[1];
    const char* output_file = argv[2];

    int width, height;
    uint8_t* image_data = load_bmp(input_file, &width, &height);
    if (!image_data) {
        return 1; // If image loading fails, we cannot proceed
    }

    apply_grayscale(image_data, width, height);
    save_bmp(output_file, image_data, width, height);
    
    free(image_data);
    printf("In this desolate world, we have brought forth beauty once more.\n");
    
    return 0;
}