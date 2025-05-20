//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DATA_POINTS 100
#define MAX_FEATURES 10

typedef struct {
    double features[MAX_FEATURES];
    int label;
} DataPoint;

DataPoint dataset[MAX_DATA_POINTS];
int num_data_points = 0;

void loadData(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    while (num_data_points < MAX_DATA_POINTS && fscanf(file, "%lf", &dataset[num_data_points].features[0]) != EOF) {
        for (int i = 1; i < MAX_FEATURES; i++) {
            fscanf(file, "%lf", &dataset[num_data_points].features[i]);
        }
        fscanf(file, "%d", &dataset[num_data_points].label);
        num_data_points++;
    }
    fclose(file);
}

double euclideanDistance(const DataPoint *a, const DataPoint *b) {
    double sum = 0.0;
    for (int i = 0; i < MAX_FEATURES; i++) {
        sum += pow(a->features[i] - b->features[i], 2);
    }
    return sqrt(sum);
}

void classify(DataPoint *queryPoint, int k) {
    double distances[MAX_DATA_POINTS];
    int labels[MAX_DATA_POINTS];
    
    for (int i = 0; i < num_data_points; i++) {
        distances[i] = euclideanDistance(queryPoint, &dataset[i]);
        labels[i] = dataset[i].label;
    }

    // Sort distances and keep track of their corresponding labels
    for (int i = 0; i < num_data_points - 1; i++) {
        for (int j = 0; j < num_data_points - i - 1; j++) {
            if (distances[j] > distances[j + 1]) {
                double tempDist = distances[j];
                distances[j] = distances[j + 1];
                distances[j + 1] = tempDist;

                int tempLabel = labels[j];
                labels[j] = labels[j + 1];
                labels[j + 1] = tempLabel;
            }
        }
    }

    // Count the number of votes for each label among the k nearest neighbors
    int voteCount[MAX_FEATURES] = {0};
    for (int i = 0; i < k && i < num_data_points; i++) {
        voteCount[labels[i]]++;
    }

    // Determine the label with the most votes
    int maxVotes = 0;
    int predictedLabel = -1;
    for (int i = 0; i < MAX_FEATURES; i++) {
        if (voteCount[i] > maxVotes) {
            maxVotes = voteCount[i];
            predictedLabel = i;
        }
    }

    printf("Predicted label for the query point: %d\n", predictedLabel);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <data_file> <k>\n", argv[0]);
        return EXIT_FAILURE;
    }

    loadData(argv[1]);
    int k = atoi(argv[2]);
    
    DataPoint queryPoint;
    printf("Enter the features for the query point:\n");
    for (int i = 0; i < MAX_FEATURES; i++) {
        printf("Feature %d: ", i + 1);
        scanf("%lf", &queryPoint.features[i]);
    }

    classify(&queryPoint, k);

    return EXIT_SUCCESS;
}