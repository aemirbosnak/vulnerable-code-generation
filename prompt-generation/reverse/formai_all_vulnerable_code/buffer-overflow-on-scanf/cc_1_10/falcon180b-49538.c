//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK_SIZE 8
#define IMAGE_SIZE 100

// Function to add watermark
void add_watermark(char* image, char* watermark) {
    int i, j;

    // Convert watermark to uppercase
    for (i = 0; watermark[i]!= '\0'; i++) {
        watermark[i] = toupper(watermark[i]);
    }

    // Add watermark to image
    for (i = 0; i < IMAGE_SIZE; i++) {
        if (i % WATERMARK_SIZE == 0) {
            for (j = 0; j < WATERMARK_SIZE && watermark[j]!= '\0'; j++) {
                image[i + j] = watermark[j];
            }
        } else {
            image[i] = image[i - WATERMARK_SIZE];
        }
    }
}

int main() {
    char image[IMAGE_SIZE];
    char watermark[WATERMARK_SIZE];

    // Get input image
    printf("Enter the input image: ");
    scanf("%s", image);

    // Get watermark
    printf("Enter the watermark: ");
    scanf("%s", watermark);

    // Add watermark to image
    add_watermark(image, watermark);

    // Print watermarked image
    printf("Watermarked image: ");
    for (int i = 0; i < IMAGE_SIZE; i++) {
        printf("%c", image[i]);
    }

    return 0;
}