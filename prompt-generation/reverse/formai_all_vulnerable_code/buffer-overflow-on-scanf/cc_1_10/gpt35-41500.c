//FormAI DATASET v1.0 Category: Image Classification system ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_FEATURES 1000 // Maximum number of image features
#define MAX_IMAGES 100 // Maximum number of images
#define FEATURE_VECTOR_LENGTH 20 // Length of feature vector
#define NUM_CLASSES 10 // Number of image classes

// Struct to store image features
typedef struct ImageFeatures {
    int id;
    double featureVector[FEATURE_VECTOR_LENGTH];
    int class;
} ImageFeatures;

// Function to load image features from text file
int loadFeaturesFromFile(char* fileName, ImageFeatures* imgFeatures) {
    FILE* fp = fopen(fileName, "r");
    if(fp == NULL) {
        printf("Error opening file!\n");
        return -1;
    }
    int numImages = 0;
    int numFeatures = 0;
    while(!feof(fp) && numImages < MAX_IMAGES) {
        fscanf(fp, "%d", &imgFeatures[numImages].id);
        numFeatures = 0;
        while(numFeatures < FEATURE_VECTOR_LENGTH) {
            fscanf(fp, "%lf", &imgFeatures[numImages].featureVector[numFeatures]);
            numFeatures++;
        }
        fscanf(fp, "%d", &imgFeatures[numImages].class);
        numImages++;
    }
    fclose(fp);
    return numImages;
}

// Function to classify image using k-nearest neighbors
int classifyImage(int k, ImageFeatures* imgFeatures, double* imageVector) {
    double distances[MAX_IMAGES];
    int nearestNeighbors[MAX_IMAGES];
    int classCount[NUM_CLASSES];
    memset(classCount, 0, sizeof(classCount));
    for(int i=0; i < MAX_IMAGES; i++) {
        distances[i] = 0;
        nearestNeighbors[i] = -1;
    }
    for(int i=0; i < MAX_IMAGES; i++) {
        for(int j=0; j < FEATURE_VECTOR_LENGTH; j++) {
            distances[i] += pow((imgFeatures[i].featureVector[j] - imageVector[j]), 2);
        }
        distances[i] = sqrt(distances[i]);
    }
    for(int i=0; i < k; i++) {
        double minDistance = INFINITY;
        int minDistanceIndex = -1;
        for(int j=0; j < MAX_IMAGES; j++) {
            if(distances[j] < minDistance && nearestNeighbors[j] == -1) {
                minDistance = distances[j];
                minDistanceIndex = j;
            }
        }
        nearestNeighbors[minDistanceIndex] = i;
    }
    for(int i=0; i < k; i++) {
        classCount[imgFeatures[nearestNeighbors[i]].class]++;
    }
    int maxClassCount = -1;
    int maxClass = -1;
    for(int i=0; i < NUM_CLASSES; i++) {
        if(classCount[i] > maxClassCount) {
            maxClassCount = classCount[i];
            maxClass = i;
        }
    }
    return maxClass;
}

int main() {
    ImageFeatures imgFeatures[MAX_IMAGES];
    int numImages = loadFeaturesFromFile("image_features.txt", imgFeatures);
    if(numImages < 0) {
        return -1;
    }
    double imageVector[FEATURE_VECTOR_LENGTH];
    printf("Enter image features:\n");
    for(int i=0; i < FEATURE_VECTOR_LENGTH; i++) {
        scanf("%lf", &imageVector[i]);
    }
    int k;
    printf("Enter value of k: ");
    scanf("%d", &k);
    int imgClass = classifyImage(k, imgFeatures, imageVector);
    printf("Image class: %d\n", imgClass);
    return 0;
}