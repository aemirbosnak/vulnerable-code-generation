//FormAI DATASET v1.0 Category: Data mining ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// define the maximum number of records to be analyzed
#define MAX_RECORDS 10000

// define the maximum number of features
#define MAX_FEATURES 100

// define the maximum length of a feature name
#define MAX_NAME_LEN 50

// structure to hold a record
typedef struct {
    char name[MAX_NAME_LEN];
    double features[MAX_FEATURES];
} Record;

// function declarations
int read_records(FILE *fp, Record *records);
void print_records(Record *records, int size);
double mean(double *values, int size);
double standard_deviation(double *values, int size, double mean);

int main() {
    // seed the random number generator
    srand(time(NULL));

    // open the data file
    FILE *fp = fopen("data.txt", "r");

    // read the records from the file
    Record records[MAX_RECORDS];
    int num_records = read_records(fp, records);

    // print the records
    printf("Original Data:\n");
    print_records(records, num_records);

    // compute the mean and standard deviation for each feature
    double means[MAX_FEATURES];
    double sds[MAX_FEATURES];

    for (int i = 0; i < MAX_FEATURES; i++) {
        double values[MAX_RECORDS];
        for (int j = 0; j < num_records; j++) {
            values[j] = records[j].features[i];
        }
        means[i] = mean(values, num_records);
        sds[i] = standard_deviation(values, num_records, means[i]);
    }

    // normalize the data
    for (int i = 0; i < num_records; i++) {
        for (int j = 0; j < MAX_FEATURES; j++) {
            records[i].features[j] = (records[i].features[j] - means[j]) / sds[j];
        }
    }

    // print the normalized data
    printf("\nNormalized Data:\n");
    print_records(records, num_records);

    // close the data file
    fclose(fp);

    return 0;
}

int read_records(FILE *fp, Record *records) {
    int i = 0;
    while (!feof(fp) && i < MAX_RECORDS) {
        Record record;
        fscanf(fp, "%s", record.name);
        for (int j = 0; j < MAX_FEATURES; j++) {
            record.features[j] = (double)rand() / RAND_MAX;
        }
        records[i++] = record;
    }
    return i;
}

void print_records(Record *records, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s: [", records[i].name);
        for (int j = 0; j < MAX_FEATURES; j++) {
            printf("%f, ", records[i].features[j]);
        }
        printf("]\n");
    }
}

double mean(double *values, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += values[i];
    }
    return sum / size;
}

double standard_deviation(double *values, int size, double mean) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += (values[i] - mean) * (values[i] - mean);
    }
    return sqrt(sum / size);
}