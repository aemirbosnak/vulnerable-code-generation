//Falcon-180B DATASET v1.0 Category: Data mining ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_DATA_POINTS 1000
#define MAX_NUM_ATTRIBUTES 10

typedef struct {
    int num_data_points;
    int num_attributes;
    double **data_points;
} DataSet;

DataSet *create_dataset(int num_data_points, int num_attributes) {
    DataSet *dataset = (DataSet *)malloc(sizeof(DataSet));
    dataset->num_data_points = num_data_points;
    dataset->num_attributes = num_attributes;
    dataset->data_points = (double **)malloc(num_data_points * sizeof(double *));
    for (int i = 0; i < num_data_points; i++) {
        dataset->data_points[i] = (double *)malloc(num_attributes * sizeof(double));
    }
    return dataset;
}

void destroy_dataset(DataSet *dataset) {
    for (int i = 0; i < dataset->num_data_points; i++) {
        free(dataset->data_points[i]);
    }
    free(dataset->data_points);
    free(dataset);
}

void generate_random_dataset(DataSet *dataset) {
    srand(time(NULL));
    for (int i = 0; i < dataset->num_data_points; i++) {
        for (int j = 0; j < dataset->num_attributes; j++) {
            dataset->data_points[i][j] = rand() % 100;
        }
    }
}

void print_dataset(DataSet *dataset) {
    for (int i = 0; i < dataset->num_data_points; i++) {
        for (int j = 0; j < dataset->num_attributes; j++) {
            printf("%f ", dataset->data_points[i][j]);
        }
        printf("\n");
    }
}

int main() {
    DataSet *dataset = create_dataset(MAX_NUM_DATA_POINTS, MAX_NUM_ATTRIBUTES);
    generate_random_dataset(dataset);
    print_dataset(dataset);
    destroy_dataset(dataset);
    return 0;
}