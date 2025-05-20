//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FEATURES 50
#define MAX_LENGTH 100

typedef struct {
    char name[MAX_LENGTH];
    float features[MAX_FEATURES];
    int target;
} Record;

Record dataset[MAX_RECORDS];
int totalRecords = 0;

// Function to load the dataset from a file
void loadData(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open the file %s for reading.\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s", dataset[totalRecords].name) != EOF) {
        for (int j = 0; j < MAX_FEATURES; j++) {
            fscanf(file, "%f", &dataset[totalRecords].features[j]);
        }
        fscanf(file, "%d", &dataset[totalRecords].target);
        totalRecords++;
    }
    fclose(file);
}

// Function to calculate the mean of a given feature
float calculateMean(int featureIndex) {
    float sum = 0.0;
    for (int i = 0; i < totalRecords; i++) {
        sum += dataset[i].features[featureIndex];
    }
    return sum / totalRecords;
}

// Function to output the data in a readable format
void printData() {
    for (int i = 0; i < totalRecords; i++) {
        printf("Name: %s | Features: ", dataset[i].name);
        for (int j = 0; j < MAX_FEATURES; j++) {
            printf("%f ", dataset[i].features[j]);
        }
        printf("| Target: %d\n", dataset[i].target);
    }
}

// Function to classify a new record based on the nearest neighbor
int classifyRecord(float features[]) {
    float minDistance = __FLT_MAX__;
    int predictedTarget = -1;

    for (int i = 0; i < totalRecords; i++) {
        float distance = 0.0;
        for (int j = 0; j < MAX_FEATURES; j++) {
            distance += (dataset[i].features[j] - features[j]) * (dataset[i].features[j] - features[j]);
        }
        distance = sqrt(distance);

        if (distance < minDistance) {
            minDistance = distance;
            predictedTarget = dataset[i].target;
        }
    }
    return predictedTarget;
}

// Main function
int main() {
    loadData("data.txt"); // Load dataset
    printData();          // Print dataset

    // Calculate and display mean of the first feature
    float meanFeature0 = calculateMean(0);
    printf("Mean of feature 0: %f\n", meanFeature0);

    // Example of classifying a new record
    float newRecordFeatures[MAX_FEATURES] = {0.5, 0.7, 0.2}; // Example features
    int predictedTarget = classifyRecord(newRecordFeatures);
    printf("Predicted target for the new record: %d\n", predictedTarget);

    return 0;
}