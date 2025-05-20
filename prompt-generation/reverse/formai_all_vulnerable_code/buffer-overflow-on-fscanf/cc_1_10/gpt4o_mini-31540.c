//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ENTRIES 1000
#define MAX_LENGTH 100

typedef struct {
    char name[MAX_LENGTH];
    float value;
} DataEntry;

DataEntry dataset[MAX_ENTRIES];
int totalEntries = 0;

void loadData(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %f", dataset[totalEntries].name, &dataset[totalEntries].value) != EOF) {
        totalEntries++;
    }
    fclose(file);
}

void displayData() {
    printf("\n\tData Entries:\n");
    printf("\t-------------------\n");
    for (int i = 0; i < totalEntries; i++) {
        printf("\t%s: %.2f\n", dataset[i].name, dataset[i].value);
    }
    printf("\t-------------------\n");
}

float computeMean() {
    float sum = 0.0;
    for (int i = 0; i < totalEntries; i++) {
        sum += dataset[i].value;
    }
    return sum / totalEntries;
}

float computeStandardDeviation(float mean) {
    float sum = 0.0;
    for (int i = 0; i < totalEntries; i++) {
        sum += pow(dataset[i].value - mean, 2);
    }
    return sqrt(sum / totalEntries);
}

void saveResults(const char *filename, float mean, float stddev) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Could not open file to save results");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "Mean: %.2f\n", mean);
    fprintf(file, "Standard Deviation: %.2f\n", stddev);
    fclose(file);
}

void peacefulAnalysis(const char *inputFile, const char *outputFile) {
    loadData(inputFile);
    displayData();

    float mean = computeMean();
    float stddev = computeStandardDeviation(mean);

    printf("\n\tAnalysis Results:\n");
    printf("\tMean: %.2f\n", mean);
    printf("\tStandard Deviation: %.2f\n", stddev);

    saveResults(outputFile, mean, stddev);
    printf("\nResults saved to %s\n", outputFile);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    peacefulAnalysis(argv[1], argv[2]);
    return EXIT_SUCCESS;
}