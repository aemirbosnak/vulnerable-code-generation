//Falcon2-11B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to initialize the data
void initialize(int data[], int n, int k) {
    int i;
    for (i = 0; i < n; i++) {
        data[i] = rand() % 100;
    }
}

// Function to find the closest data point for each cluster
void closest(int data[], int n, int k, int *closest_data, int *closest_distances) {
    int i, j;
    int min_dist, min_idx;
    int distances[k];

    // Initialize distances array
    for (i = 0; i < k; i++) {
        distances[i] = 1000; // Initialize to a large value
    }

    // Find closest data point for each cluster
    for (i = 0; i < n; i++) {
        min_dist = 1000;
        min_idx = -1;

        for (j = 0; j < k; j++) {
            if (distances[j] < min_dist) {
                min_dist = distances[j];
                min_idx = j;
            }
        }

        closest_distances[i] = min_dist;
        closest_data[i] = data[min_idx];
    }
}

// Function to calculate the centroid of each cluster
void average(int data[], int n, int k, int *centroids) {
    int i, sum;
    int avg[k];

    // Calculate the sum of all data points
    sum = 0;
    for (i = 0; i < n; i++) {
        sum += data[i];
    }

    // Calculate the average of each cluster
    for (i = 0; i < k; i++) {
        avg[i] = (int) (sum / n);
    }

    // Update the centroids
    for (i = 0; i < k; i++) {
        centroids[i] = avg[i];
    }
}

// Function to print the data
void print(int data[], int n, int k) {
    int i, j;
    int closest_distances[n];
    int closest_data[n];
    int centroids[k];

    initialize(data, n, k);
    closest(data, n, k, closest_data, closest_distances);
    average(data, n, k, centroids);

    // Print the data
    printf("Input data:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // Print the closest data points for each cluster
    printf("Closest data points for each cluster:\n");
    for (i = 0; i < n; i++) {
        printf("%d %d %d\n", i + 1, closest_data[i], closest_distances[i]);
    }

    // Print the centroids
    printf("Centroids:\n");
    for (i = 0; i < k; i++) {
        printf("%d ", centroids[i]);
    }
    printf("\n");
}

int main() {
    int n, k;
    int data[100];
    int closest_data[100];
    int closest_distances[100];
    int centroids[100];

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the number of clusters: ");
    scanf("%d", &k);

    print(data, n, k);

    return 0;
}