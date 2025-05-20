//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DATA 1000
#define MAX_ATTRIBUTES 100
#define MAX_CLASSES 10

typedef struct {
    int num_data;
    int num_attributes;
    int num_classes;
    double data[MAX_DATA][MAX_ATTRIBUTES];
    int classes[MAX_DATA];
} dataset_t;

dataset_t* load_dataset(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    dataset_t* dataset = malloc(sizeof(dataset_t));
    if (dataset == NULL) {
        fprintf(stderr, "Error allocating memory for dataset\n");
        fclose(fp);
        return NULL;
    }

    fscanf(fp, "%d %d %d", &dataset->num_data, &dataset->num_attributes, &dataset->num_classes);

    for (int i = 0; i < dataset->num_data; i++) {
        for (int j = 0; j < dataset->num_attributes; j++) {
            fscanf(fp, "%lf", &dataset->data[i][j]);
        }
        fscanf(fp, "%d", &dataset->classes[i]);
    }

    fclose(fp);

    return dataset;
}

void print_dataset(dataset_t* dataset) {
    printf("Number of data: %d\n", dataset->num_data);
    printf("Number of attributes: %d\n", dataset->num_attributes);
    printf("Number of classes: %d\n", dataset->num_classes);

    for (int i = 0; i < dataset->num_data; i++) {
        for (int j = 0; j < dataset->num_attributes; j++) {
            printf("%lf ", dataset->data[i][j]);
        }
        printf("%d\n", dataset->classes[i]);
    }
}

int main() {
    dataset_t* dataset = load_dataset("data.txt");
    if (dataset == NULL) {
        return 1;
    }

    print_dataset(dataset);

    free(dataset);

    return 0;
}