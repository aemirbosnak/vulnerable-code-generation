#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_DATASET_SIZE 1000

typedef struct {
    int features[MAX_DATASET_SIZE][28*28];
    int labels[MAX_DATASET_SIZE];
} Dataset;

void load_dataset(const char *filename, Dataset *dataset) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }
    for (int i = 0; i < MAX_DATASET_SIZE; i++) {
        for (int j = 0; j < 28*28; j++) {
            fscanf(file, "%d", &dataset->features[i][j]);
        }
        fscanf(file, "%d", &dataset->labels[i]);
    }
    fclose(file);
}

double train_model(Dataset *train_data, int epochs) {
    // Placeholder for actual training logic
    return 0.95; // Example accuracy
}

double test_model(Dataset *test_data, double (*model)(Dataset *)) {
    int correct = 0;
    for (int i = 0; i < MAX_DATASET_SIZE; i++) {
        if (model(test_data) == test_data->labels[i]) {
            correct++;
        }
    }
    return (double)correct / MAX_DATASET_SIZE;
}

int main() {
    Dataset train_data, test_data;
    char train_filename[100], test_filename[100];

    printf("Enter the path to the training dataset file: ");
    scanf("%s", train_filename);
    printf("Enter the path to the test dataset file: ");
    scanf("%s", test_filename);

    load_dataset(train_filename, &train_data);
    load_dataset(test_filename, &test_data);

    double accuracy = train_model(&train_data, 10);
    printf("Model trained with an accuracy of %.2f%%\n", accuracy * 100);

    double test_accuracy = test_model(&test_data, train_model);
    printf("Test accuracy: %.2f%%\n", test_accuracy * 100);

    return 0;
}
