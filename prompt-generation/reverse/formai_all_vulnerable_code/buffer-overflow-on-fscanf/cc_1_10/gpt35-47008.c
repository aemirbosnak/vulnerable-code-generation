//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: futuristic
//Futuristic C Clustering Algorithm Implementation Example Program

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CLUSTER_COUNT 5 //number of clusters to form
#define DATA_COUNT 10000 //number of data points
#define DIMENSION 2 //dimensions of data points

float data[DATA_COUNT][DIMENSION]; //2D array to store input data
float centroids[CLUSTER_COUNT][DIMENSION]; //2D array to store centroid coordinates
int labels[DATA_COUNT]; //array to store cluster labels for each data point

float euclidean_distance(float x[], float y[]) {
    //calculate euclidean distance between two points
    float distance = 0.0;
    for (int i = 0; i < DIMENSION; i++) {
        distance += pow((x[i] - y[i]), 2);
    }
    return sqrt(distance);
}

void initialize_centroids() {
    //randomly select initial centroids from data points
    for (int i = 0; i < CLUSTER_COUNT; i++) {
        int random_index = rand() % DATA_COUNT;
        for (int j = 0; j < DIMENSION; j++) {
            centroids[i][j] = data[random_index][j];
        }
    }
}

int assign_labels() {
    //assign each data point to the nearest centroid
    int changed = 0; //flag to indicate if any label has changed
    for (int i = 0; i < DATA_COUNT; i++) {
        float min_distance = 999999.0;
        int min_index = -1;
        for (int j = 0; j < CLUSTER_COUNT; j++) {
            float distance = euclidean_distance(data[i], centroids[j]);
            if (distance < min_distance) {
                min_distance = distance;
                min_index = j;
            }
        }
        if (labels[i] != min_index) {
            labels[i] = min_index;
            changed = 1;
        }
    }
    return changed;
}

void update_centroids() {
    //update centroid coordinates based on assigned data points
    int count[CLUSTER_COUNT] = {0}; //count of data points assigned to each cluster
    for (int i = 0; i < DATA_COUNT; i++) {
        int cluster_index = labels[i];
        for (int j = 0; j < DIMENSION; j++) {
            centroids[cluster_index][j] += data[i][j];
        }
        count[cluster_index]++;
    }
    for (int i = 0; i < CLUSTER_COUNT; i++) {
        if (count[i] != 0) {
            for (int j = 0; j < DIMENSION; j++) {
                centroids[i][j] /= count[i];
            }
        }
    }
}

void print_clusters() {
    //print cluster labels for each data point
    printf("Cluster labels:\n");
    for (int i = 0; i < DATA_COUNT; i++) {
        printf("%d ", labels[i]);
        if ((i+1) % 20 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    //input data points from file
    FILE *fp;
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error opening data file.\n");
        return 1;
    }
    for (int i = 0; i < DATA_COUNT; i++) {
        fscanf(fp, "%f %f", &data[i][0], &data[i][1]);
    }
    fclose(fp);

    //initialize centroids
    initialize_centroids();

    //repeat until no label changes
    int iteration = 0;
    while (assign_labels()) {
        update_centroids();
        iteration++;
    }

    //print cluster labels for data points
    print_clusters();
    printf("Iterations: %d\n", iteration);

    return 0;
}