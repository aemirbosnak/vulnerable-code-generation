//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for storing data points
typedef struct {
    int id;
    float feature1;
    float feature2;
} DataPoint;

// Function prototypes
void readDataFromFile(const char *filename, DataPoint **data, int *numDataPoints);
void performDataMining(DataPoint *data, int numDataPoints);
void cleanup(DataPoint *data);

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <data_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    DataPoint *data = NULL;
    int numDataPoints = 0;

    readDataFromFile(argv[1], &data, &numDataPoints);
    performDataMining(data, numDataPoints);

    cleanup(data);
    return EXIT_SUCCESS;
}

// Function to read data from a file
void readDataFromFile(const char *filename, DataPoint **data, int *numDataPoints) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d", numDataPoints);
    *data = (DataPoint *)malloc(*numDataPoints * sizeof(DataPoint));

    for (int i = 0; i < *numDataPoints; i++) {
        fscanf(file, "%d %f %f", &(*data)[i].id, &(*data)[i].feature1, &(*data)[i].feature2);
    }
    fclose(file);
}

// Function for performing a simple data mining operation
void performDataMining(DataPoint *data, int numDataPoints) {
    printf("Performing data mining...\n");
    float sumFeature1 = 0.0, sumFeature2 = 0.0;
    float maxFeature1 = -1e6, maxFeature2 = -1e6;
    float minFeature1 = 1e6, minFeature2 = 1e6;

    for (int i = 0; i < numDataPoints; i++) {
        sumFeature1 += data[i].feature1;
        sumFeature2 += data[i].feature2;

        if (data[i].feature1 > maxFeature1) {
            maxFeature1 = data[i].feature1;
        }
        if (data[i].feature2 > maxFeature2) {
            maxFeature2 = data[i].feature2;
        }
        if (data[i].feature1 < minFeature1) {
            minFeature1 = data[i].feature1;
        }
        if (data[i].feature2 < minFeature2) {
            minFeature2 = data[i].feature2;
        }
    }

    float avgFeature1 = sumFeature1 / numDataPoints;
    float avgFeature2 = sumFeature2 / numDataPoints;

    printf("Statistics:\n");
    printf("Average Feature 1: %.2f\n", avgFeature1);
    printf("Average Feature 2: %.2f\n", avgFeature2);
    printf("Max Feature 1: %.2f, Min Feature 1: %.2f\n", maxFeature1, minFeature1);
    printf("Max Feature 2: %.2f, Min Feature 2: %.2f\n", maxFeature2, minFeature2);
}

// Function to clean up allocated memory
void cleanup(DataPoint *data) {
    free(data);
}