//MISTRAL-7B DATASET v1.0 Category: Data mining ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE_LENGTH 1024
#define NUM_FEATURES 10
#define NUM_INSTANCES 500
#define FILENAME "trainingData.txt"

typedef struct {
    float features[NUM_FEATURES];
    int label;
} Instance;

Instance instances[NUM_INSTANCES];
float weights[NUM_FEATURES];
float bias;

int readDataFile(char *filename) {
    int i = 0;
    int j = 0;
    int lineNumber = 0;
    int featureNumber = 0;
    char line[MAX_LINE_LENGTH];
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        lineNumber++;
        if (lineNumber == 1) {
            // Skip header line
            continue;
        }

        sscanf(line, "%f,%d", &instances[i].features[0], &instances[i].label);
        for (featureNumber = 1; featureNumber < NUM_FEATURES; featureNumber++) {
            sscanf(line, "%*s %f,", &instances[i].features[featureNumber]);
        }
        i++;
    }

    fclose(file);

    return i;
}

void initializeWeights() {
    int i;
    for (i = 0; i < NUM_FEATURES; i++) {
        weights[i] = (float) rand() / RAND_MAX;
    }
}

void trainPerceptron() {
    int i;
    int correctPredictions = 0;

    for (i = 0; i < NUM_INSTANCES; i++) {
        float netInput = 0;
        for (int j = 0; j < NUM_FEATURES; j++) {
            netInput += instances[i].features[j] * weights[j];
        }
        netInput += bias;

        if (instances[i].label * (netInput > 0) > 0) {
            correctPredictions++;
        } else {
            for (int j = 0; j < NUM_FEATURES; j++) {
                weights[j] += instances[i].features[j] * (instances[i].label * (netInput > 0) - instances[i].label);
            }
            bias += instances[i].label * (netInput > 0) - instances[i].label;
        }
    }

    printf("Training completed. Correct predictions: %d\n", correctPredictions);
}

int main() {
    int numInstances = readDataFile(FILENAME);
    initializeWeights();
    trainPerceptron();

    return EXIT_SUCCESS;
}