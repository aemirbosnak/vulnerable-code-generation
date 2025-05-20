//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000 // Maximum number of points allowed
#define CLUSTER_SIZE 20 // Minimum size of a cluster
#define RADIUS 0.1 // Maximum radius allowed for points to be in a same cluster

typedef struct point {
    double x, y; // Coordinates of a point
    int cluster; // Cluster ID this point belongs to
    int visited; // Flag to check if the point has been visited or not
    int noise;   // Flag to check if the point is a noise or not
} Point;

// Function to calculate Euclidean distance between two points
double euclidean_distance(Point p1, Point p2) {
    double x_diff = p1.x - p2.x;
    double y_diff = p1.y - p2.y;
    return sqrt(x_diff * x_diff + y_diff * y_diff);
}

// Function to find all points within a certain radius of another point
int region_query(Point dataset[], int n, int p_idx, double radius, int neighbours[]) {
    int num_neighbours = 0;
    for (int i = 0; i < n; i++) {
        if (i == p_idx) continue;
        double distance = euclidean_distance(dataset[i], dataset[p_idx]);
        if (distance <= radius) {
            neighbours[num_neighbours++] = i;
        }
    }
    return num_neighbours;
}

// Function to expand a cluster starting from a point
void expand_cluster(Point dataset[], int n, int p_idx, int cluster_id, double radius, int min_pts) {
    int neighbours[MAX_POINTS]; // Indexes of points within radius distance
    int num_neighbours = region_query(dataset, n, p_idx, radius, neighbours);
    if (num_neighbours < min_pts) {
        dataset[p_idx].noise = 1; // Mark point as noise
        return;
    }
    dataset[p_idx].cluster = cluster_id; // Assign cluster ID to the point
    for (int i = 0; i < num_neighbours; i++) {
        int n_idx = neighbours[i];
        if (!dataset[n_idx].visited) {
            dataset[n_idx].visited = 1;
            dataset[n_idx].cluster = cluster_id;
            int n_neighbours[MAX_POINTS];
            int n_num_neighbours = region_query(dataset, n, n_idx, radius, n_neighbours);
            if (n_num_neighbours >= min_pts) {
                for (int j = 0; j < n_num_neighbours; j++) {
                    int nn_idx = n_neighbours[j];
                    if (!dataset[nn_idx].visited) {
                        neighbours[num_neighbours++] = nn_idx;
                    }
                }
            }
        }
        // If the neighbour belongs to some cluster already, skip
        if (dataset[n_idx].cluster) continue;
        dataset[n_idx].cluster = cluster_id; // Assign cluster ID to the neighbour
        expand_cluster(dataset, n, n_idx, cluster_id, radius, min_pts);
    }
}

// Function to perform density-based clustering on a dataset
void dbscan_clustering(Point dataset[], int n, double radius, int min_pts) {
    // Initialize all points as unvisited
    for (int i = 0; i < n; i++) {
        dataset[i].visited = 0;
    }
    int cluster_id = 1;
    // Iterate over each point
    for (int i = 0; i < n; i++) {
        // If the point has already been visited, skip
        if (dataset[i].visited) continue;
        dataset[i].visited = 1;
        // Find the neighbouring points within radius distance
        int neighbours[MAX_POINTS];
        int num_neighbours = region_query(dataset, n, i, radius, neighbours);
        // If the point has less than min_pts neighbours, mark as noise
        if (num_neighbours < min_pts) {
            dataset[i].noise = 1;
        }
        // Otherwise, start a new cluster
        else {
            dataset[i].cluster = cluster_id;
            expand_cluster(dataset, n, i, cluster_id, radius, min_pts);
            cluster_id++;
        }
    }
}

int main() {
    int n; // Number of points in the dataset
    Point dataset[MAX_POINTS];
    printf("Enter the number of points (<= %d): ", MAX_POINTS);
    scanf("%d", &n);
    if (n > MAX_POINTS || n < 1) {
        printf("Invalid number of points. Exiting.\n");
        return 1;
    }
    // Input x, y coordinates of all points
    for (int i = 0; i < n; i++) {
        printf("Enter x, y coordinates of point %d: ", i+1);
        scanf("%lf %lf", &dataset[i].x, &dataset[i].y);
        dataset[i].cluster = 0;
        dataset[i].visited = 0;
        dataset[i].noise = 0;
    }
    // Perform clustering on the dataset
    dbscan_clustering(dataset, n, RADIUS, CLUSTER_SIZE);
    printf("DBSCAN clustering result:\n");
    // Print cluster assignments of all points
    for (int i = 0; i < n; i++) {
        if (dataset[i].noise) {
            printf("Point %d: Noise\n", i+1);
        } else {
            printf("Point %d: Cluster %d\n", i+1, dataset[i].cluster);
        }
    }
    return 0;
}