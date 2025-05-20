//GPT-4o-mini DATASET v1.0 Category: Image Classification system ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXELS 1000
#define MAX_DATA_TYPES 3

typedef struct {
    int r;
    int g;
    int b;
} Pixel;

void classifyImage(int pixelCount, Pixel pixels[]) {
    long totalR = 0, totalG = 0, totalB = 0;
    int i;

    // Calculate average RGB values
    for (i = 0; i < pixelCount; i++) {
        totalR += pixels[i].r;
        totalG += pixels[i].g;
        totalB += pixels[i].b;
    }

    double avgR = totalR / (double)pixelCount;
    double avgG = totalG / (double)pixelCount;
    double avgB = totalB / (double)pixelCount;

    // Classify based on average values
    printf("Average RGB: (%.2f, %.2f, %.2f) -> ", avgR, avgG, avgB);
    
    if (avgR > 200 && avgG > 200 && avgB > 200) {
        printf("Classification: Bright\n");
    } else if (avgR < 50 && avgG < 50 && avgB < 50) {
        printf("Classification: Dark\n");
    } else if ((avgR > 100 && avgG < 100 && avgB < 100) ||
               (avgG > 100 && avgR < 100 && avgB < 100) ||
               (avgB > 100 && avgR < 100 && avgG < 100)) {
        printf("Classification: Colorful\n");
    } else {
        printf("Classification: Neutral\n");
    }
}

void readImageData(char *filename, Pixel pixels[], int *pixelCount) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    *pixelCount = 0;
    while (fscanf(file, "%d %d %d", &pixels[*pixelCount].r,
                                  &pixels[*pixelCount].g,
                                  &pixels[*pixelCount].b) == 3) {
        (*pixelCount)++;
        if (*pixelCount >= MAX_PIXELS) {
            break;
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image_data_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Pixel pixels[MAX_PIXELS];
    int pixelCount = 0;

    readImageData(argv[1], pixels, &pixelCount);

    if (pixelCount == 0) {
        fprintf(stderr, "No valid pixel data found in the file.\n");
        return EXIT_FAILURE;
    }

    classifyImage(pixelCount, pixels);

    return EXIT_SUCCESS;
}