//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef unsigned char byte;

// Discrete Cosine Transform (DCT)
void dct(byte *block, int n) {
    double pi = 3.14159265358979323846;
    double c1 = 1 / sqrt(2);
    double c2 = sqrt(2 / n);

    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            double sum = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    sum += block[i * n + j] *
                           cos((2 * i + 1) * u * pi / (2 * n)) *
                           cos((2 * j + 1) * v * pi / (2 * n));
                }
            }
            block[u * n + v] = c1 * c2 * sum;
        }
    }
}

// Inverse Discrete Cosine Transform (IDCT)
void idct(byte *block, int n) {
    double pi = 3.14159265358979323846;
    double c1 = 1 / sqrt(2);
    double c2 = sqrt(2 / n);

    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            double sum = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    sum += block[i * n + j] *
                           cos((2 * i + 1) * u * pi / (2 * n)) *
                           cos((2 * j + 1) * v * pi / (2 * n));
                }
            }
            block[u * n + v] = c1 * c2 * sum;
        }
    }
}

// Embed watermark into DCT coefficients
void embed_watermark(byte *image, byte *watermark, int n, int d) {
    for (int i = 0; i < n / 8; i++) {
        for (int j = 0; j < n / 8; j++) {
            byte *block = image + i * n * 8 + j * 8;
            dct(block, 8);
            block[d] += watermark[i * n / 8 + j];
            idct(block, 8);
        }
    }
}

// Extract watermark from DCT coefficients
void extract_watermark(byte *image, byte *watermark, int n, int d) {
    for (int i = 0; i < n / 8; i++) {
        for (int j = 0; j < n / 8; j++) {
            byte *block = image + i * n * 8 + j * 8;
            dct(block, 8);
            watermark[i * n / 8 + j] = block[d];
            idct(block, 8);
        }
    }
}

int main() {
    // Read image and watermark
    FILE *image_file = fopen("image.jpg", "rb");
    FILE *watermark_file = fopen("watermark.jpg", "rb");

    int image_width, image_height;
    fread(&image_width, sizeof(int), 1, image_file);
    fread(&image_height, sizeof(int), 1, image_file);
    byte *image = malloc(image_width * image_height);
    fread(image, sizeof(byte), image_width * image_height, image_file);
    fclose(image_file);

    int watermark_width, watermark_height;
    fread(&watermark_width, sizeof(int), 1, watermark_file);
    fread(&watermark_height, sizeof(int), 1, watermark_file);
    byte *watermark = malloc(watermark_width * watermark_height);
    fread(watermark, sizeof(byte), watermark_width * watermark_height, watermark_file);
    fclose(watermark_file);

    // Embed watermark into image
    embed_watermark(image, watermark, image_width, 10);

    // Save watermarked image
    FILE *watermarked_image_file = fopen("watermarked_image.jpg", "wb");
    fwrite(&image_width, sizeof(int), 1, watermarked_image_file);
    fwrite(&image_height, sizeof(int), 1, watermarked_image_file);
    fwrite(image, sizeof(byte), image_width * image_height, watermarked_image_file);
    fclose(watermarked_image_file);

    // Extract watermark from watermarked image
    byte *extracted_watermark = malloc(watermark_width * watermark_height);
    extract_watermark(image, extracted_watermark, image_width, 10);

    // Compare extracted watermark with original watermark
    int error = 0;
    for (int i = 0; i < watermark_width * watermark_height; i++) {
        if (extracted_watermark[i] != watermark[i]) {
            error++;
        }
    }

    printf("Error: %d\n", error);

    // Free memory
    free(image);
    free(watermark);
    free(extracted_watermark);

    return 0;
}