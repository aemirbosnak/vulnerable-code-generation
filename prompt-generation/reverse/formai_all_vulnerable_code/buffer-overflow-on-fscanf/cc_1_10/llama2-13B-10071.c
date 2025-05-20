//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DATASET_SIZE 1000
#define KMEANS_CLUSTERS 5

typedef struct {
    double x;
    double y;
} point_t;

point_t dataset[DATASET_SIZE];
int labels[DATASET_SIZE];

void read_dataset(const char* filename) {
    int i;
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error reading dataset");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < DATASET_SIZE; i++) {
        fscanf(file, "%lf %lf", &dataset[i].x, &dataset[i].y);
    }
    fclose(file);
}

void kmeans_cluster(point_t* dataset, int k) {
    int i, j;
    double x[k];
    double y[k];
    double dist[k];
    int assigned[k];
    for (i = 0; i < k; i++) {
        x[i] = 0;
        y[i] = 0;
        dist[i] = INFINITY;
        assigned[i] = -1;
    }
    for (i = 0; i < DATASET_SIZE; i++) {
        for (j = 0; j < k; j++) {
            double d = pow(dataset[i].x - x[j], 2) + pow(dataset[i].y - y[j], 2);
            if (d < dist[assigned[j]]) {
                dist[assigned[j]] = d;
                assigned[j] = i;
            }
        }
    }
    for (i = 0; i < k; i++) {
        if (assigned[i] == -1) {
            assigned[i] = i;
        }
    }
}

int main() {
    read_dataset("dataset.txt");
    int k = KMEANS_CLUSTERS;
    kmeans_cluster(dataset, k);
    for (int i = 0; i < DATASET_SIZE; i++) {
        printf("%d ", labels[i]);
    }
    printf("\n");
    return 0;
}