//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DATA_POINTS 1000
#define MAX_FEATURES 10

typedef struct {
    double features[MAX_FEATURES];
    double label;
} data_point;

data_point data[MAX_DATA_POINTS];
int num_data_points;

void read_data(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening data file");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while (fscanf(fp, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
        &data[i].features[0], &data[i].features[1], &data[i].features[2],
        &data[i].features[3], &data[i].features[4], &data[i].features[5],
        &data[i].features[6], &data[i].features[7], &data[i].features[8],
        &data[i].features[9], &data[i].label) == 11) {
        i++;
    }

    num_data_points = i;

    fclose(fp);
}

void print_data() {
    for (int i = 0; i < num_data_points; i++) {
        printf("%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\n",
            data[i].features[0], data[i].features[1], data[i].features[2],
            data[i].features[3], data[i].features[4], data[i].features[5],
            data[i].features[6], data[i].features[7], data[i].features[8],
            data[i].features[9], data[i].label);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <data file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    read_data(argv[1]);
    print_data();

    return 0;
}