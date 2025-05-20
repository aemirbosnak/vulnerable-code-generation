//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_ITER 1000

// Function to calculate distance between two points
double getDistance(double *a, double *b, int n) {
    double sum = 0;
    for (int i=0; i<n; i++) {
        sum += pow((a[i] - b[i]), 2);
    }
    return sqrt(sum);
}

// Function to assign points to clusters
void assignToClusters(double **points, double **centroids, int *assignments, int k, int n) {
    for (int i=0; i<n; i++) {
        double min_dist = INFINITY;
        for (int j=0; j<k; j++) {
            double dist = getDistance(points[i], centroids[j], k);
            if (dist < min_dist) {
                min_dist = dist;
                assignments[i] = j;
            }
        }
    }
}

// Function to update centroids
void updateCentroids(double **points, double **centroids, int *assignments, int k, int n) {
    for (int i=0; i<k; i++) {
        double mean[k];
        int count = 0;
        for (int j=0; j<n; j++) {
            if (assignments[j] == i) {
                count++;
                for (int l=0; l<k; l++) {
                    mean[l] += points[j][l];
                }
            }
        }
        for (int l=0; l<k; l++) {
            centroids[i][l] = mean[l] / count;
        }
    }
}

// Function to perform clustering
void performClustering(double **points, double **centroids, int *assignments, int k, int n) {
    for (int i=0; i<MAX_ITER; i++) {
        assignToClusters(points, centroids, assignments, k, n);
        updateCentroids(points, centroids, assignments, k, n);
    }
}

int main() {
    int n, k;
    printf("Enter the number of points: ");
    scanf("%d", &n);
    printf("Enter the number of clusters: ");
    scanf("%d", &k);
    
    double **points = (double**) malloc(n*sizeof(double*));
    for (int i=0; i<n; i++) {
        points[i] = (double*) malloc(k*sizeof(double));
    }
    int *assignments = (int*) malloc(n*sizeof(int));
    double **centroids = (double**) malloc(k*sizeof(double*));
    for (int i=0; i<k; i++) {
        centroids[i] = (double*) malloc(k*sizeof(double));
    }
    
    printf("Enter the points:\n");
    for (int i=0; i<n; i++) {
        printf("Point %d: ", (i+1));
        for (int j=0; j<k; j++) {
            scanf("%lf", &points[i][j]);
        }
    }
    printf("\nEnter the initial centroids:\n");
    for (int i=0; i<k; i++) {
        printf("Centroid %d: ", (i+1));
        for (int j=0; j<k; j++) {
            scanf("%lf", &centroids[i][j]);
        }
    }
    
    performClustering(points, centroids, assignments, k, n);
    printf("\nFinal Cluster Assignments:\n");
    for (int i=0; i<n; i++) {
        printf("Point %d -> Cluster %d\n", (i+1), (assignments[i]+1));
    }
    
    free(points);
    free(centroids);
    free(assignments);
    return 0;
}