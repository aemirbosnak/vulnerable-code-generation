//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIMENSIONS 2
#define CENTROIDS_NUM 3
#define THRESHOLD 0.001

double* calculate_centroid(double** data_points, int* grouping, int group_size, int dimensionality) {
    double* centroid = calloc(dimensionality, sizeof(double));
    int i, j;
    for (i=0; i<group_size; i++) {
        for (j=0; j<dimensionality; j++) {
            centroid[j] += data_points[grouping[i]][j];
        }
    }
    for (j=0; j<dimensionality; j++) {
        centroid[j] /= group_size;
    }
    return centroid;
}

double calculate_distance(double* point1, double* point2, int dimensionality) {
    double distance_squared = 0;
    int i;
    for (i=0; i<dimensionality; i++) {
        double difference = point1[i] - point2[i];
        distance_squared += difference * difference;
    }
    return sqrt(distance_squared);
}

int main(int argc, char** argv) {
    int num_points, dimensionality;
    printf("Please enter the number of points:\n");
    scanf("%d", &num_points);
    printf("Please enter the dimensionality of the data:\n");
    scanf("%d", &dimensionality);
    
    double** data_points = calloc(num_points, sizeof(double*));
    int i, j;
    for (i=0; i<num_points; i++) {
        data_points[i] = calloc(dimensionality, sizeof(double));
        printf("Enter the coordinates of point %d:\n", i+1);
        for (j=0; j<dimensionality; j++) {
            scanf("%lf", &data_points[i][j]);
        }
    }
    
    int num_groups, max_iterations;
    printf("Please enter the number of groups/centroids:\n");
    scanf("%d", &num_groups);
    printf("Please enter the maximum number of iterations:\n");
    scanf("%d", &max_iterations);
    
    double** centroids = calloc(num_groups, sizeof(double*));
    for (i=0; i<num_groups; i++) {
        centroids[i] = calloc(dimensionality, sizeof(double));
        printf("Enter the coordinates of centroid %d:\n", i+1);
        for (j=0; j<dimensionality; j++) {
            scanf("%lf", &centroids[i][j]);
        }
    }
    
    int* grouping = calloc(num_points, sizeof(int));
    int iteration = 0, changed = 1;
    while (iteration < max_iterations && changed) {
        changed = 0;
        for (i=0; i<num_points; i++) {
            int nearest_centroid = 0;
            double min_distance = calculate_distance(data_points[i], centroids[0], dimensionality);
            for (j=1; j<num_groups; j++) {
                double distance = calculate_distance(data_points[i], centroids[j], dimensionality);
                if (distance < min_distance) {
                    nearest_centroid = j;
                    min_distance = distance;
                }
            }
            if (grouping[i] != nearest_centroid) {
                grouping[i] = nearest_centroid;
                changed = 1;
            }
        }
        
        for (i=0; i<num_groups; i++) {
            int group_size = 0;
            for (j=0; j<num_points; j++) {
                if (grouping[j] == i) {
                    group_size++;
                }
            }
            double* new_centroid = calculate_centroid(data_points, grouping, group_size, dimensionality);
            double distance = calculate_distance(new_centroid, centroids[i], dimensionality);
            if (distance > THRESHOLD) {
                centroids[i] = new_centroid;
                changed = 1;
            } else {
                free(new_centroid);
            }
        }
        
        iteration++;
    }
    
    printf("\nFinal grouping:\n");
    for (i=0; i<num_groups; i++) {
        printf("Group %d:", i+1);
        for (j=0; j<num_points; j++) {
            if (grouping[j] == i) {
                printf(" %d", j+1);
            }
        }
        printf("\nCentroid %d: (", i+1);
        for (j=0; j<dimensionality; j++) {
            printf("%.2lf", centroids[i][j]);
            if (j != dimensionality-1) {
                printf(", ");
            }
        }
        printf(")\n");
    }
    
    for (i=0; i<num_points; i++) {
        free(data_points[i]);
    }
    free(data_points);
    for (i=0; i<num_groups; i++) {
        free(centroids[i]);
    }
    free(centroids);
    free(grouping);
    
    return 0;
}