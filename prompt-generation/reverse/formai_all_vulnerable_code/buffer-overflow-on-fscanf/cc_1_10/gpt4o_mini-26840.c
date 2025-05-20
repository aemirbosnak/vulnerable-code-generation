//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_POINTS 1000
#define MAX_FEATURES 20
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float features[MAX_FEATURES];
    float label;
} DataPoint;

typedef struct {
    DataPoint data[MAX_DATA_POINTS];
    int count;
} DataSet;

void load_data(const char *filename, DataSet *dataset) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    dataset->count = 0;
    while (fscanf(file, "%s", dataset->data[dataset->count].name) != EOF) {
        for (int i = 0; i < MAX_FEATURES; i++) {
            fscanf(file, "%f", &dataset->data[dataset->count].features[i]);
        }
        fscanf(file, "%f", &dataset->data[dataset->count].label);
        dataset->count++;
    }
    
    fclose(file);
}

void print_dataset(const DataSet *dataset) {
    for (int i = 0; i < dataset->count; i++) {
        printf("DataPoint %d: %s, Features: ", i + 1, dataset->data[i].name);
        for (int j = 0; j < MAX_FEATURES; j++) {
            printf("%f ", dataset->data[i].features[j]);
        }
        printf(", Label: %f\n", dataset->data[i].label);
    }
}

float calculate_mean(const DataSet *dataset, int feature_index) {
    float sum = 0.0;
    for (int i = 0; i < dataset->count; i++) {
        sum += dataset->data[i].features[feature_index];
    }
    return sum / dataset->count;
}

void normalize_data(DataSet *dataset) {
    for (int i = 0; i < MAX_FEATURES; i++) {
        float mean = calculate_mean(dataset, i);
        for (int j = 0; j < dataset->count; j++) {
            dataset->data[j].features[i] -= mean;
        }
    }
}

float euclidean_distance(const float *features1, const float *features2, int feature_size) {
    float sum = 0.0;
    for (int i = 0; i < feature_size; i++) {
        sum += (features1[i] - features2[i]) * (features1[i] - features2[i]);
    }
    return sqrt(sum);
}

void classify(const DataSet *training_data, DataPoint *test_point, int k) {
    float distances[MAX_DATA_POINTS];
    int indices[MAX_DATA_POINTS];
    
    for (int i = 0; i < training_data->count; i++) {
        distances[i] = euclidean_distance(training_data->data[i].features, test_point->features, MAX_FEATURES);
        indices[i] = i;
    }
    
    // Sort distances and indices
    for (int i = 0; i < training_data->count - 1; i++) {
        for (int j = 0; j < training_data->count - i - 1; j++) {
            if (distances[j] > distances[j + 1]) {
                float temp_distance = distances[j];
                distances[j] = distances[j + 1];
                distances[j + 1] = temp_distance;

                int temp_index = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp_index;
            }
        }
    }
    
    // Majority voting for classification
    int label_count[2] = {0, 0}; // Assuming binary classification for simplicity
    for (int i = 0; i < k; i++) {
        int label = (int)training_data->data[indices[i]].label;
        label_count[label]++;
    }
    
    test_point->label = (label_count[0] > label_count[1]) ? 0 : 1;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <data_file> <test_point>\n", argv[0]);
        return EXIT_FAILURE;
    }

    DataSet dataset;
    load_data(argv[1], &dataset);
    printf("Loaded Dataset:\n");
    print_dataset(&dataset);
    
    normalize_data(&dataset);
    printf("\nNormalized Dataset:\n");
    print_dataset(&dataset);
    
    DataPoint test_point;
    strcpy(test_point.name, argv[2]);
    printf("Enter features for test point %s:\n", test_point.name);
    for (int i = 0; i < MAX_FEATURES; i++) {
        printf("Feature %d: ", i + 1);
        scanf("%f", &test_point.features[i]);
    }

    classify(&dataset, &test_point, 5);
    printf("Classified label for test point %s: %f\n", test_point.name, test_point.label);
    
    return EXIT_SUCCESS;
}