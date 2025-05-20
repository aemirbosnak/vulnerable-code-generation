//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK_SIZE 8
#define IMAGE_SIZE 4096

typedef struct {
    char watermark[WATERMARK_SIZE+1];
    int watermark_length;
    int watermark_index;
} Watermark;

void init_watermark(Watermark *watermark, char *watermark_str) {
    strncpy(watermark->watermark, watermark_str, WATERMARK_SIZE);
    watermark->watermark_length = strlen(watermark->watermark);
    watermark->watermark_index = 0;
}

void add_watermark(Watermark *watermark, char *image, int image_size) {
    int i;
    for (i = 0; i < image_size; i++) {
        if (image[i] >= 'A' && image[i] <= 'Z') {
            image[i] += watermark->watermark[watermark->watermark_index];
            if (watermark->watermark_index == watermark->watermark_length - 1) {
                watermark->watermark_index = 0;
            } else {
                watermark->watermark_index++;
            }
        }
    }
}

int main() {
    Watermark watermark;
    char image[IMAGE_SIZE];
    int image_size;

    init_watermark(&watermark, "MYWATERMARK");

    printf("Enter the image data: ");
    scanf("%s", image);
    image_size = strlen(image);

    add_watermark(&watermark, image, image_size);

    printf("Watermarked image data: ");
    for (int i = 0; i < image_size; i++) {
        printf("%c", image[i]);
    }
    printf("\n");

    return 0;
}