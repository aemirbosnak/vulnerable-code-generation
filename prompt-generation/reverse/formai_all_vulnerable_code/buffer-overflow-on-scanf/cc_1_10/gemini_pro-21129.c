//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: paranoid
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

// Define the maximum number of clusters and data points
#define MAX_CLUSTERS 100
#define MAX_DATA_POINTS 1000

// Define the data point structure
typedef struct {
    int x;
    int y;
} data_point;

// Define the cluster structure
typedef struct {
    int centroid_x;
    int centroid_y;
    int num_data_points;
    data_point* data_points;
} cluster;

// Define the global variables
int num_clusters;
int num_data_points;
data_point data_points[MAX_DATA_POINTS];
cluster clusters[MAX_CLUSTERS];

// Function to initialize the clusters
void initialize_clusters() {
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].centroid_x = rand() % 100;
        clusters[i].centroid_y = rand() % 100;
        clusters[i].num_data_points = 0;
        clusters[i].data_points = malloc(sizeof(data_point) * MAX_DATA_POINTS);
    }
}

// Function to assign data points to clusters
void assign_data_points_to_clusters() {
    for (int i = 0; i < num_data_points; i++) {
        int min_distance = INT_MAX;
        int closest_cluster = -1;
        for (int j = 0; j < num_clusters; j++) {
            int distance = (data_points[i].x - clusters[j].centroid_x) * (data_points[i].x - clusters[j].centroid_x) +
                           (data_points[i].y - clusters[j].centroid_y) * (data_points[i].y - clusters[j].centroid_y);
            if (distance < min_distance) {
                min_distance = distance;
                closest_cluster = j;
            }
        }
        clusters[closest_cluster].data_points[clusters[closest_cluster].num_data_points] = data_points[i];
        clusters[closest_cluster].num_data_points++;
    }
}

// Function to update the centroids of the clusters
void update_centroids() {
    for (int i = 0; i < num_clusters; i++) {
        int sum_x = 0;
        int sum_y = 0;
        for (int j = 0; j < clusters[i].num_data_points; j++) {
            sum_x += clusters[i].data_points[j].x;
            sum_y += clusters[i].data_points[j].y;
        }
        clusters[i].centroid_x = sum_x / clusters[i].num_data_points;
        clusters[i].centroid_y = sum_y / clusters[i].num_data_points;
    }
}

// Function to print the clusters
void print_clusters() {
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < clusters[i].num_data_points; j++) {
            printf("(%d, %d)\n", clusters[i].data_points[j].x, clusters[i].data_points[j].y);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Get the number of clusters and data points from the user
    printf("Enter the number of clusters: ");
    scanf("%d", &num_clusters);
    printf("Enter the number of data points: ");
    scanf("%d", &num_data_points);

    // Initialize the data points
    for (int i = 0; i < num_data_points; i++) {
        data_points[i].x = rand() % 100;
        data_points[i].y = rand() % 100;
    }

    // Initialize the clusters
    initialize_clusters();

    // Assign data points to clusters
    assign_data_points_to_clusters();

    // Update the centroids of the clusters
    update_centroids();

    // Print the clusters
    print_clusters();

    return 0;
}