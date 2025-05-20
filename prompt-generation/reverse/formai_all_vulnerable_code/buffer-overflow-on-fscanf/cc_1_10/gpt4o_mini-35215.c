//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_FEATURES 10
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    double features[MAX_FEATURES];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Dataset;

void load_data(Dataset *dataset, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    dataset->count = 0;
    while (fscanf(file, "%s", dataset->records[dataset->count].name) != EOF) {
        for (int i = 0; i < MAX_FEATURES; i++) {
            fscanf(file, "%lf", &dataset->records[dataset->count].features[i]);
        }
        dataset->count++;
        if (dataset->count >= MAX_RECORDS) break;
    }

    fclose(file);
}

void print_dataset(Dataset *dataset) {
    for (int i = 0; i < dataset->count; i++) {
        printf("%s: ", dataset->records[i].name);
        for (int j = 0; j < MAX_FEATURES; j++) {
            printf("%lf ", dataset->records[i].features[j]);
        }
        printf("\n");
    }
}

double calculate_average_feature(Dataset *dataset, int feature_index) {
    if (dataset->count == 0 || feature_index < 0 || feature_index >= MAX_FEATURES) {
        fprintf(stderr, "Invalid dataset or feature index\n");
        return 0.0;
    }

    double sum = 0.0;
    for (int i = 0; i < dataset->count; i++) {
        sum += dataset->records[i].features[feature_index];
    }
    return sum / dataset->count;
}

void find_closest_to_average(Dataset *dataset, int feature_index) {
    double average = calculate_average_feature(dataset, feature_index);
    printf("Average feature %d: %lf\n", feature_index, average);

    double closest_distance = -1;
    Record closest_record;

    for (int i = 0; i < dataset->count; i++) {
        double distance = fabs(dataset->records[i].features[feature_index] - average);
        if (closest_distance == -1 || distance < closest_distance) {
            closest_distance = distance;
            closest_record = dataset->records[i];
        }
    }

    printf("Record closest to average feature %d: %s with value %lf\n", feature_index, closest_record.name, closest_record.features[feature_index]);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <datafile>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Dataset dataset;
    load_data(&dataset, argv[1]);
    print_dataset(&dataset);

    for (int i = 0; i < MAX_FEATURES; i++) {
        find_closest_to_average(&dataset, i);
    }

    return EXIT_SUCCESS;
}