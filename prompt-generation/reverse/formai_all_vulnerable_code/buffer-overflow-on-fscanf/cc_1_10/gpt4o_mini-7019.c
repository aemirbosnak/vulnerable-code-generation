//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_DATA 1000
#define MAX_FEATURES 10

typedef struct {
    double features[MAX_FEATURES];
    int label;
} DataPoint;

DataPoint dataSet[MAX_DATA];
int dataCount = 0;

void loadData(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    while (fscanf(file, "%lf %lf %d\n", &dataSet[dataCount].features[0], &dataSet[dataCount].features[1], &dataSet[dataCount].label) != EOF) {
        dataCount++;
        if (dataCount >= MAX_DATA) {
            break;
        }
    }
    fclose(file);
}

double euclideanDistance(DataPoint a, DataPoint b) {
    double sum = 0.0;
    for (int i = 0; i < MAX_FEATURES; i++) {
        sum += pow(a.features[i] - b.features[i], 2);
    }
    return sqrt(sum);
}

int findNearestNeighbor(DataPoint *testPoint) {
    double minDistance = INFINITY;
    int nearestLabel = -1;

    for (int i = 0; i < dataCount; i++) {
        double distance = euclideanDistance(*testPoint, dataSet[i]);
        if (distance < minDistance) {
            minDistance = distance;
            nearestLabel = dataSet[i].label;
        }
    }
    return nearestLabel;
}

void classifyData(const char *testFile) {
    FILE *file = fopen(testFile, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", testFile);
        exit(EXIT_FAILURE);
    }
    
    DataPoint testPoint;
    while (fscanf(file, "%lf %lf\n", &testPoint.features[0], &testPoint.features[1]) != EOF) {
        int predictedLabel = findNearestNeighbor(&testPoint);
        printf("Test Point: (%lf, %lf) Predicted Label: %d\n", testPoint.features[0], testPoint.features[1], predictedLabel);
    }
    fclose(file);
}

void printDataSet() {
    printf("Data Set:\n");
    for (int i = 0; i < dataCount; i++) {
        printf("Features: (%lf, %lf), Label: %d\n", 
               dataSet[i].features[0], dataSet[i].features[1], dataSet[i].label);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <data_file> <test_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    loadData(argv[1]);
    printDataSet();
    classifyData(argv[2]);

    return EXIT_SUCCESS;
}