//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <limits.h>

#define MAX_SIZE 4096
#define MAX_WATERMARK_SIZE 4096
#define BLOCK_SIZE 8

// Function to generate watermark
void generateWatermark(char *watermark, int watermarkSize) {
    srand(time(NULL));
    for (int i = 0; i < watermarkSize; i++) {
        watermark[i] = rand() % 26 + 'a';
    }
    watermark[watermarkSize - 1] = '\0';
}

// Function to embed watermark
void embedWatermark(char *host, char *watermark, int hostSize, int watermarkSize, int blockSize) {
    int watermarkIndex = 0;
    for (int i = 0; i < hostSize; i += blockSize) {
        for (int j = 0; j < blockSize && watermarkIndex < watermarkSize; j++) {
            host[i + j] ^= watermark[watermarkIndex++];
        }
    }
}

// Function to extract watermark
char *extractWatermark(char *host, int hostSize) {
    char *watermark = (char *)malloc(MAX_WATERMARK_SIZE);
    int watermarkSize = 0;
    int blockSize = 8;
    for (int i = 0; i < hostSize; i += blockSize) {
        for (int j = 0; j < blockSize; j++) {
            if (host[i + j] == 'a' + j) {
                watermark[watermarkSize++] = host[i + j];
            }
        }
    }
    watermark[watermarkSize] = '\0';
    return watermark;
}

int main() {
    char *host = (char *)malloc(MAX_SIZE);
    char *watermark = (char *)malloc(MAX_WATERMARK_SIZE);
    int hostSize, watermarkSize;

    // Read host file
    FILE *fp = fopen("host.txt", "rb");
    if (fp == NULL) {
        printf("Error: Could not open host file.\n");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    hostSize = ftell(fp);
    rewind(fp);
    fread(host, hostSize, 1, fp);
    fclose(fp);

    // Generate watermark
    generateWatermark(watermark, MAX_WATERMARK_SIZE);

    // Embed watermark
    embedWatermark(host, watermark, hostSize, strlen(watermark), BLOCK_SIZE);

    // Write watermarked file
    FILE *outfp = fopen("watermarked.txt", "wb");
    if (outfp == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }
    fwrite(host, hostSize, 1, outfp);
    fclose(outfp);

    // Extract watermark
    char *extractedWatermark = extractWatermark(host, hostSize);
    printf("Extracted watermark: %s\n", extractedWatermark);

    free(host);
    free(watermark);
    free(extractedWatermark);

    return 0;
}