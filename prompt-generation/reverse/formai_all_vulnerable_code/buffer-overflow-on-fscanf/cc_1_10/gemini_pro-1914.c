//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX_ATTRIBUTES 100
#define MAX_INSTANCES 1000

typedef struct {
    int num_attributes;
    int num_instances;
    double attributes[MAX_ATTRIBUTES];
    double instances[MAX_INSTANCES][MAX_ATTRIBUTES];
} dataset;

dataset* read_dataset(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    dataset* data = malloc(sizeof(dataset));
    if (data == NULL) {
        printf("Error allocating memory for dataset\n");
        fclose(fp);
        return NULL;
    }

    fscanf(fp, "%d %d", &data->num_attributes, &data->num_instances);

    for (int i = 0; i < data->num_attributes; i++) {
        fscanf(fp, "%lf", &data->attributes[i]);
    }

    for (int i = 0; i < data->num_instances; i++) {
        for (int j = 0; j < data->num_attributes; j++) {
            fscanf(fp, "%lf", &data->instances[i][j]);
        }
    }

    fclose(fp);

    return data;
}

void print_dataset(dataset* data) {
    printf("Number of attributes: %d\n", data->num_attributes);
    printf("Number of instances: %d\n", data->num_instances);

    printf("Attributes:\n");
    for (int i = 0; i < data->num_attributes; i++) {
        printf("%d: %lf\n", i, data->attributes[i]);
    }

    printf("Instances:\n");
    for (int i = 0; i < data->num_instances; i++) {
        for (int j = 0; j < data->num_attributes; j++) {
            printf("%lf ", data->instances[i][j]);
        }
        printf("\n");
    }
}

int main() {
    dataset* data = read_dataset("data.txt");
    if (data == NULL) {
        return 1;
    }

    print_dataset(data);

    return 0;
}