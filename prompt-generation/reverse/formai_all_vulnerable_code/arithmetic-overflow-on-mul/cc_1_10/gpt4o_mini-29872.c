//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define WATERMARK "WATERMARK"
#define WATERMARK_LEN (sizeof(WATERMARK) - 1)
#define INPUT_IMAGE "input.ppm"
#define OUTPUT_IMAGE "output.ppm"

// Function to read PPM file and return pixel data
uint8_t* read_ppm(const char* filename, int* width, int* height) {
    FILE *file = fopen(filename, "rb");
    if(!file) {
        perror("Failed to open input file");
        return NULL;
    }

    char format[3];
    fscanf(file, "%2s\n%d %d\n255\n", format, width, height);
    
    uint8_t* pixel_data = malloc((*width) * (*height) * 3); // Allocate 3 bytes per pixel
    fread(pixel_data, 3, (*width) * (*height), file);
    fclose(file);
    return pixel_data;
}

// Function to write PPM file from pixel data
void write_ppm(const char* filename, uint8_t* pixel_data, int width, int height) {
    FILE *file = fopen(filename, "wb");
    if(!file) {
        perror("Failed to open output file");
        return;
    }
    
    fprintf(file, "P6\n%d %d\n255\n", width, height);
    fwrite(pixel_data, 3, width * height, file);
    fclose(file);
}

// Function to embed watermark using LSB technique
void embed_watermark(uint8_t* pixel_data, const char* watermark, int width, int height) {
    int watermark_index = 0;
    int watermark_length = strlen(watermark);
    
    for(int i = 0; i < width * height * 3; i++) {
        if(watermark_index < watermark_length) {
            // Modify least significant bit of the pixel (R component)
            pixel_data[i] = (pixel_data[i] & 0xFE) | ((watermark[watermark_index] >> (i % 8)) & 1);
            watermark_index++;
        } else {
            break;
        }
    }
}

// Function to extract watermark from pixel data
void extract_watermark(uint8_t* pixel_data, char* watermark, int width, int height) {
    int watermark_index = 0;
    
    for(int i = 0; i < width * height * 3 && watermark_index < WATERMARK_LEN; i++) {
        if(i % 8 == 0) {
            watermark[watermark_index] = 0; // Start a new character
        }
        
        // Extract least significant bit
        watermark[watermark_index] |= (pixel_data[i] & 1) << (i % 8);
        
        if(i % 8 == 7) {
            watermark_index++;
        }
    }
    watermark[watermark_index] = '\0'; // Null-terminate the extracted watermark
}

int main() {
    int width, height;
    
    // Read input image
    uint8_t* pixel_data = read_ppm(INPUT_IMAGE, &width, &height);
    if(pixel_data == NULL) return 1;
    
    // Embed watermark into image
    embed_watermark(pixel_data, WATERMARK, width, height);
    
    // Write output image with watermark
    write_ppm(OUTPUT_IMAGE, pixel_data, width, height);
    printf("Watermark embedded successfully!\n");

    // Prepare to extract the watermark
    char extracted_watermark[WATERMARK_LEN + 1];
    memset(extracted_watermark, 0, sizeof(extracted_watermark));

    // Extract watermark from modified image
    extract_watermark(pixel_data, extracted_watermark, width, height);

    // Output the extracted watermark
    printf("Extracted Watermark: %s\n", extracted_watermark);

    // Cleanup
    free(pixel_data);
    return 0;
}