//Falcon-180B DATASET v1.0 Category: Data mining ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

struct DataSet {
    int rows;
    int cols;
    double **data;
};

struct DataSet *createDataSet(int rows, int cols) {
    struct DataSet *dataset = (struct DataSet *)malloc(sizeof(struct DataSet));
    dataset->rows = rows;
    dataset->cols = cols;
    dataset->data = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        dataset->data[i] = (double *)malloc(cols * sizeof(double));
    }
    return dataset;
}

void destroyDataSet(struct DataSet *dataset) {
    for (int i = 0; i < dataset->rows; i++) {
        free(dataset->data[i]);
    }
    free(dataset->data);
    free(dataset);
}

void fillDataSet(struct DataSet *dataset, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dataset->data[i][j] = rand() % 100;
        }
    }
}

void printDataSet(struct DataSet *dataset) {
    for (int i = 0; i < dataset->rows; i++) {
        for (int j = 0; j < dataset->cols; j++) {
            printf("%f ", dataset->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    struct DataSet *dataset = createDataSet(MAX_ROWS, MAX_COLS);
    fillDataSet(dataset, MAX_ROWS, MAX_COLS);
    printDataSet(dataset);
    destroyDataSet(dataset);
    return 0;
}