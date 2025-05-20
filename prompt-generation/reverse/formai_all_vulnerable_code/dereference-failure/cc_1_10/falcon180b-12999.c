//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WATERMARK_SIZE 32

void generate_watermark(char* watermark, int size) {
    int i;
    char ch;
    for (i = 0; i < size; i++) {
        ch = rand() % 26 + 'a';
        watermark[i] = ch;
    }
}

void embed_watermark(char* image, char* watermark, int size) {
    int i;
    for (i = 0; i < size; i++) {
        image[i] ^= watermark[i];
    }
}

void extract_watermark(char* image, char* watermark, int size) {
    int i;
    for (i = 0; i < size; i++) {
        watermark[i] = image[i] ^ watermark[i];
    }
}

int main() {
    char image[WATERMARK_SIZE];
    char watermark[WATERMARK_SIZE];
    char extracted_watermark[WATERMARK_SIZE];

    // Generate watermark
    generate_watermark(watermark, WATERMARK_SIZE);

    // Embed watermark in image
    strcpy(image, "Hello, world!");
    embed_watermark(image, watermark, WATERMARK_SIZE);

    // Simulate transmission or storage of watermarked image
    printf("Watermarked image: %s\n", image);

    // Extract watermark from image
    extract_watermark(image, extracted_watermark, WATERMARK_SIZE);

    // Verify that extracted watermark matches original watermark
    if (strcmp(watermark, extracted_watermark) == 0) {
        printf("Watermark successfully extracted!\n");
    } else {
        printf("Watermark extraction failed.\n");
    }

    return 0;
}