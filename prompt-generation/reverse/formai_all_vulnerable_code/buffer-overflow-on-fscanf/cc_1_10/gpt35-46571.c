//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void distance_mat(float** mat, float** data, int rows, int cols) {
    //Create a matrix of distances between all data points
    for(int i=0; i<rows; i++) {
        for(int j=0; j<rows; j++) {
            float distance = 0;
            for(int k=0; k<cols; k++) {
                distance += powf((data[i][k] - data[j][k]), 2);
            }
            mat[i][j] = sqrtf(distance);
        }
    }
}

void cluster(float** mat, int rows, float threshold) {
    int* cluster_labels = malloc(rows * sizeof(int)); //Array to store final cluster labels
    int curr_label = 1; //Start labeling clusters from 1
    for(int i=0; i<rows; i++) {
        if(cluster_labels[i] == 0) { //If data point has not been assigned to a cluster yet
            cluster_labels[i] = curr_label; //Assign label to current data point
            for(int j=i+1; j<rows; j++) {
                if(mat[i][j] < threshold) { //If distance between two data points is less than threshold
                    if(cluster_labels[j] == 0) { //If second data point has not been assigned to a cluster yet
                        cluster_labels[j] = curr_label; //Assign label to second data point
                    }
                    else if(cluster_labels[j] != curr_label) { //If second data point is already assigned to a different cluster
                        int to_change = cluster_labels[j];
                        for(int k=0; k<rows; k++) {
                            if(cluster_labels[k] == to_change) {
                                cluster_labels[k] = curr_label; //Change label of all points in second cluster to match first cluster
                            }
                        }
                    }
                }
            }
            curr_label++; //Move on to next cluster
        }
    }
    printf("Final cluster labels: ");
    for(int i=0; i<rows; i++) {
        printf("%d ", cluster_labels[i]);
    }
    free(cluster_labels); //Free memory
}

int main() {
    //Read data from input file
    FILE* fp = fopen("input.txt", "r");
    if(fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    int rows, cols;
    fscanf(fp, "%d %d", &rows, &cols);
    float** data = malloc(rows * sizeof(float*));
    for(int i=0; i<rows; i++) {
        data[i] = malloc(cols * sizeof(float));
        for(int j=0; j<cols; j++) {
            fscanf(fp, "%f", &data[i][j]);
        }
    }
    fclose(fp);

    //Allocate memory for distance matrix
    float** dist_mat = malloc(rows * sizeof(float*));
    for(int i=0; i<rows; i++) {
        dist_mat[i] = malloc(rows * sizeof(float));
    }

    distance_mat(dist_mat, data, rows, cols); //Calculate distance matrix
    cluster(dist_mat, rows, 2.5); //Cluster data with threshold distance of 2.5

    //Free memory
    for(int i=0; i<rows; i++) {
        free(data[i]);
        free(dist_mat[i]);
    }
    free(data);
    free(dist_mat);

    return 0;
}