//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to hold a point in 2D space
typedef struct {
    double x;
    double y;
} Point;

// Structure to hold a cluster
typedef struct {
    Point centroid;
    int point_count;
} Cluster;

// Function prototypes
void init_clusters(Cluster *clusters, int k);
void assign_points_to_clusters(Point *points, Cluster *clusters, int n, int k);
void update_centroids(Cluster *clusters, Point *points, int n, int k);
double calculate_distance(Point a, Point b);
int is_converged(Cluster *clusters, Cluster *prev_clusters, int k);
void print_clusters(Cluster *clusters, int k);
void generate_random_points(Point *points, int n);

int main() {
    int n = 10; // Number of points
    int k; // Number of clusters
    Cluster *clusters;
    Point *points;

    printf("Enter the number of clusters (k): ");
    scanf("%d", &k);

    // Allocate memory for points and clusters
    points = (Point *)malloc(n * sizeof(Point));
    clusters = (Cluster *)malloc(k * sizeof(Cluster));

    // Generate random points for clustering
    generate_random_points(points, n);

    // Initialize clusters
    init_clusters(clusters, k);

    // K-means algorithm implementation
    int iteration = 0;
    do {
        printf("Iteration %d:\n", iteration);
        Cluster *prev_clusters = malloc(k * sizeof(Cluster));
        for (int i = 0; i < k; i++) {
            prev_clusters[i] = clusters[i]; // Save previous centroids
        }

        // Assign points to the nearest cluster
        assign_points_to_clusters(points, clusters, n, k);
        // Update cluster centroids based on current assignments
        update_centroids(clusters, points, n, k);
        
        print_clusters(clusters, k);
        iteration++;
        
        // Check for convergence
        if (is_converged(clusters, prev_clusters, k)) {
            break;
        }

        free(prev_clusters);
    } while (1);

    // Free allocated memory
    free(points);
    free(clusters);

    return 0;
}

// Function to generate random points
void generate_random_points(Point *points, int n) {
    for (int i = 0; i < n; i++) {
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
    }
}

// Function to initialize clusters with random centroids
void init_clusters(Cluster *clusters, int k) {
    for (int i = 0; i < k; i++) {
        clusters[i].centroid.x = rand() % 100;
        clusters[i].centroid.y = rand() % 100;
        clusters[i].point_count = 0;
    }
}

// Function to assign points to the nearest cluster
void assign_points_to_clusters(Point *points, Cluster *clusters, int n, int k) {
    for (int i = 0; i < k; i++) {
        clusters[i].point_count = 0; // Reset point count for each cluster
    }

    for (int i = 0; i < n; i++) {
        int closest_cluster = 0;
        double min_distance = calculate_distance(points[i], clusters[0].centroid);

        for (int j = 1; j < k; j++) {
            double distance = calculate_distance(points[i], clusters[j].centroid);
            if (distance < min_distance) {
                min_distance = distance;
                closest_cluster = j;
            }
        }

        clusters[closest_cluster].point_count++;
    }
}

// Function to update centroids based on assigned points
void update_centroids(Cluster *clusters, Point *points, int n, int k) {
    double *sums_x = (double *)malloc(k * sizeof(double));
    double *sums_y = (double *)malloc(k * sizeof(double));

    for (int i = 0; i < k; i++) {
        sums_x[i] = 0;
        sums_y[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int closest_cluster = 0;
        double min_distance = calculate_distance(points[i], clusters[0].centroid);

        for (int j = 1; j < k; j++) {
            double distance = calculate_distance(points[i], clusters[j].centroid);
            if (distance < min_distance) {
                min_distance = distance;
                closest_cluster = j;
            }
        }

        sums_x[closest_cluster] += points[i].x;
        sums_y[closest_cluster] += points[i].y;
    }

    for (int i = 0; i < k; i++) {
        if (clusters[i].point_count > 0) {
            clusters[i].centroid.x = sums_x[i] / clusters[i].point_count;
            clusters[i].centroid.y = sums_y[i] / clusters[i].point_count;
        }
    }

    free(sums_x);
    free(sums_y);
}

// Function to calculate the distance between two points
double calculate_distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// Function to check if the clusters have converged
int is_converged(Cluster *clusters, Cluster *prev_clusters, int k) {
    for (int i = 0; i < k; i++) {
        if (clusters[i].centroid.x != prev_clusters[i].centroid.x ||
            clusters[i].centroid.y != prev_clusters[i].centroid.y) {
            return 0; // Not converged
        }
    }
    return 1; // Converged
}

// Function to print clusters' centroids
void print_clusters(Cluster *clusters, int k) {
    for (int i = 0; i < k; i++) {
        printf("Cluster %d: Centroid(%.2lf, %.2lf), Points Assigned: %d\n",
               i, clusters[i].centroid.x, clusters[i].centroid.y, clusters[i].point_count);
    }
}