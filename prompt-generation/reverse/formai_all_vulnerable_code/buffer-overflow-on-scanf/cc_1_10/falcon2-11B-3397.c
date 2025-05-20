//Falcon2-11B DATASET v1.0 Category: Image Classification system ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_HEIGHT 200
#define MAX_WIDTH 200
#define NUM_CLASSES 5

// Function to classify an image using K-means clustering
int classifyImage(int *image, int height, int width) {
    int classes[NUM_CLASSES][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}}; // Initialize centroids
    int clusterCount[NUM_CLASSES] = {0, 0, 0, 0, 0}; // Count of images in each cluster

    // K-means clustering algorithm
    int i, j, k;
    int minDist;
    double dist;
    int centroidIndex;
    int temp;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            dist = 1000000.0; // Initialize minimum distance as a very large number
            centroidIndex = -1; // Initialize centroid index as -1
            for (k = 0; k < NUM_CLASSES; k++) {
                temp = (int)sqrt((image[i * width + j] - classes[k][0]) * (image[i * width + j] - classes[k][0]) + (image[i * width + j] - classes[k][1]) * (image[i * width + j] - classes[k][1]));
                if (temp < dist) {
                    dist = temp;
                    centroidIndex = k;
                }
            }
            clusterCount[centroidIndex]++; // Increment cluster count
            classes[centroidIndex][0] += image[i * width + j]; // Update centroid position
            classes[centroidIndex][1] += image[i * width + j];
        }
    }

    // Find the class with the maximum number of images
    int maxCluster = 0;
    for (i = 0; i < NUM_CLASSES; i++) {
        if (clusterCount[i] > clusterCount[maxCluster]) {
            maxCluster = i;
        }
    }

    // Return the class with the maximum number of images
    return maxCluster;
}

int main() {
    int image[MAX_HEIGHT][MAX_WIDTH]; // Create an array to store the image
    int height, width; // Variables to store the height and width of the image

    // Get input for image dimensions
    printf("Enter the height of the image: ");
    scanf("%d", &height);
    printf("Enter the width of the image: ");
    scanf("%d", &width);

    // Get input for the pixels of the image
    printf("Enter the pixels of the image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    // Classify the image using K-means clustering
    int classification = classifyImage(image, height, width);

    // Print the classification result
    printf("Classification result: %d\n", classification);

    return 0;
}