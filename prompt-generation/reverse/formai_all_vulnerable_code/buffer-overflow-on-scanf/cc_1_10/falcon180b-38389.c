//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define MAX_WATERMARK_SIZE 20

// Function to display the image with watermark
void display_image(int image[MAX_HEIGHT][MAX_WIDTH], int watermark[MAX_HEIGHT][MAX_WIDTH], int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (watermark[i][j] == 1) {
                printf("* ");
            } else {
                printf("%d ", image[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to add watermark to the image
void add_watermark(int image[MAX_HEIGHT][MAX_WIDTH], int watermark[MAX_HEIGHT][MAX_WIDTH], int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (watermark[i][j] == 1) {
                image[i][j] += 20;
            }
        }
    }
}

// Function to generate random image and watermark
void generate_random_image(int image[MAX_HEIGHT][MAX_WIDTH], int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] = rand() % 256;
        }
    }
}

// Function to generate random watermark
void generate_random_watermark(int watermark[MAX_HEIGHT][MAX_WIDTH], int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (rand() % 2 == 0) {
                watermark[i][j] = 1;
            } else {
                watermark[i][j] = 0;
            }
        }
    }
}

int main() {
    int image[MAX_HEIGHT][MAX_WIDTH], watermark[MAX_HEIGHT][MAX_WIDTH];
    int height, width;

    // Get image dimensions from user
    printf("Enter image height: ");
    scanf("%d", &height);
    printf("Enter image width: ");
    scanf("%d", &width);

    // Generate random image and watermark
    generate_random_image(image, height, width);
    generate_random_watermark(watermark, height, width);

    // Add watermark to the image
    add_watermark(image, watermark, height, width);

    // Display the image with watermark
    display_image(image, watermark, height, width);

    return 0;
}