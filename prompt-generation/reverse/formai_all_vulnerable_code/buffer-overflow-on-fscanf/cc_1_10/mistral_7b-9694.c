//MISTRAL-7B DATASET v1.0 Category: Data mining ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_INSTANCES 1000
#define MAX_ATTRIBUTES 5
#define NUM_CLASSES 2

typedef struct {
    float values[MAX_ATTRIBUTES];
    int label;
} Instance;

typedef struct {
    Instance instances[MAX_INSTANCES];
    int num_instances;
} Dataset;

void read_data(Dataset *dataset, const char *filename) {
    FILE *file = fopen(filename, "r");

    fscanf(file, "%d", &dataset->num_instances);

    for (int i = 0; i < dataset->num_instances; i++) {
        Instance *instance = &dataset->instances[i];

        for (int j = 0; j < MAX_ATTRIBUTES; j++)
            fscanf(file, "%f", &instance->values[j]);

        fscanf(file, "%d", &instance->label);
    }

    fclose(file);
}

float euclidean_distance(Instance a, Instance b) {
    float sum_of_squared_differences = 0.0;

    for (int i = 0; i < MAX_ATTRIBUTES; i++)
        sum_of_squared_differences += pow(a.values[i] - b.values[i], 2);

    return sqrt(sum_of_squared_differences);
}

int predict(Instance test, Dataset training_data, int k) {
    int *nearest_labels = calloc(k, sizeof(int));
    Instance *nearest_instances = malloc(k * sizeof(Instance));

    for (int i = 0; i < training_data.num_instances; i++) {
        Instance current = training_data.instances[i];
        float distance = euclidean_distance(test, current);

        for (int j = 0; j < k; j++) {
            if (distance > nearest_labels[j] || j == 0) {
                for (int l = k; l > j; l--)
                    nearest_instances[l] = nearest_instances[l - 1];

                nearest_instances[j] = current;
                nearest_labels[j] = current.label;
                distance = -distance;
                break;
            }
        }
    }

    int predicted_label = nearest_labels[0];

    for (int i = 1; i < k; i++)
        predicted_label += nearest_labels[i];

    predicted_label /= k;

    free(nearest_instances);
    free(nearest_labels);

    return predicted_label;
}

int main() {
    Dataset dataset;
    read_data(&dataset, "data.csv");

    Instance test = {{1.0, 2.0, 3.0, 4.0, 5.0}, 0};
    int k = 3;

    int predicted_label = predict(test, dataset, k);
    printf("Predicted label: %d\n", predicted_label);

    return 0;
}