//FormAI DATASET v1.0 Category: Image Classification system ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define IMAGE_SIZE 28 // Define image size
#define MAX_IMAGES 10 // Define maximum number of images, will be used for testing purposes

// Function to normalize pixel values between 0 and 1
void normalize(float image[IMAGE_SIZE][IMAGE_SIZE]) {
    float max = 0;
    for (int i = 0; i < IMAGE_SIZE; i++) {
        for (int j = 0; j < IMAGE_SIZE; j++) {
            if (image[i][j] > max) {
                max = image[i][j];
            }
        }
    }

    for (int i = 0; i < IMAGE_SIZE; i++) {
        for (int j = 0; j < IMAGE_SIZE; j++) {
            image[i][j] /= max;
        }
    }
}

int main() {
    // Initialize image arrays
    float images[MAX_IMAGES][IMAGE_SIZE][IMAGE_SIZE] = {0};
    int labels[MAX_IMAGES] = {0};

    // Read data from file into image arrays
    FILE *fp = fopen("image_data.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.");
        return -1;
    }

    int count = 0;

    while (count < MAX_IMAGES && !feof(fp)) {
        fscanf(fp, "%d", &labels[count]);

        for (int i = 0; i < IMAGE_SIZE; i++) {
            for (int j = 0; j < IMAGE_SIZE; j++) {
                fscanf(fp, "%f", &images[count][i][j]);
            }
        }

        normalize(images[count]);

        count++;
    }

    fclose(fp);

    // Initialize testing image
    float testImage[IMAGE_SIZE][IMAGE_SIZE] = {0};

    // Read testing image from file
    fp = fopen("test_image.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.");
        return -1;
    }

    for (int i = 0; i < IMAGE_SIZE; i++) {
        for (int j = 0; j < IMAGE_SIZE; j++) {
            fscanf(fp, "%f", &testImage[i][j]);
        }
    }

    normalize(testImage);

    fclose(fp);

    // Calculate euclidean distance between testing image and each training image
    float distances[MAX_IMAGES];

    for (int i = 0; i < MAX_IMAGES; i++) {
        float d = 0;
        for (int j = 0; j < IMAGE_SIZE; j++) {
            for (int k = 0; k < IMAGE_SIZE; k++) {
                float diff = images[i][j][k] - testImage[j][k];
                d += diff * diff;
            }
        }

        distances[i] = sqrt(d);
    }

    // Find image with shortest euclidean distance
    float minDistance = distances[0];
    int minIndex = 0;

    for (int i = 1; i < MAX_IMAGES; i++) {
        if (distances[i] < minDistance) {
            minDistance = distances[i];
            minIndex = i;
        }
    }

    // Print predicted label for testing image
    printf("Predicted label: %d\n", labels[minIndex]);

    return 0;
}