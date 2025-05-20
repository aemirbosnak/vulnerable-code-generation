//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 10

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point centroid;
    int count;
} Cluster;

// Function to calculate Euclidean distance
double euclidean_distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Function to initialize clusters
void initialize_clusters(Cluster clusters[], int k, Point points[], int n) {
    for (int i = 0; i < k; i++) {
        clusters[i].centroid = points[i % n]; // Assign initial centroids
        clusters[i].count = 0;
    }
}

// Function to assign points to the nearest cluster
void assign_clusters(Point points[], Cluster clusters[], int k, int n) {
    for (int i = 0; i < n; i++) {
        double min_dist = INFINITY;
        int cluster_index = 0;
        
        for (int j = 0; j < k; j++) {
            double dist = euclidean_distance(points[i], clusters[j].centroid);
            if (dist < min_dist) {
                min_dist = dist;
                cluster_index = j;
            }
        }
        clusters[cluster_index].count++;
    }
}

// Function to update cluster centroids
void update_centroids(Cluster clusters[], int k, Point points[], int n) {
    for (int j = 0; j < k; j++) {
        clusters[j].centroid.x = 0;
        clusters[j].centroid.y = 0;
        clusters[j].count = 0;
    }

    for (int i = 0; i < n; i++) {
        double min_dist = INFINITY;
        int cluster_index = 0;

        for (int j = 0; j < k; j++) {
            double dist = euclidean_distance(points[i], clusters[j].centroid);
            if (dist < min_dist) {
                min_dist = dist;
                cluster_index = j;
            }
        }
        clusters[cluster_index].centroid.x += points[i].x;
        clusters[cluster_index].centroid.y += points[i].y;
        clusters[cluster_index].count++;
    }

    for (int j = 0; j < k; j++) {
        if (clusters[j].count > 0) {
            clusters[j].centroid.x /= clusters[j].count;
            clusters[j].centroid.y /= clusters[j].count;
        }
    }
}

// Function to read data from CSV file
int read_data(const char* filename, Point points[]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        return -1;
    }
    
    char line[256];
    // Skip the header line
    fgets(line, sizeof(line), file);
    
    int count = 0;
    while (fgets(line, sizeof(line), file) && count < MAX_POINTS) {
        sscanf(line, "%lf,%lf", &points[count].x, &points[count].y);
        count++;
    }
    
    fclose(file);
    return count;
}

// K-means clustering algorithm
void k_means(Point points[], int n, int k) {
    Cluster clusters[MAX_CLUSTERS];
    initialize_clusters(clusters, k, points, n);

    for (int iteration = 0; iteration < 100; iteration++) {
        assign_clusters(points, clusters, k, n);
        update_centroids(clusters, k, points, n);
    }

    // Output results
    for (int j = 0; j < k; j++) {
        printf("Cluster %d: Centroid (%.2f, %.2f) Count: %d\n", j + 1, clusters[j].centroid.x, clusters[j].centroid.y, clusters[j].count);
    }
}

int main() {
    Point points[MAX_POINTS];
    int n = read_data("data.csv", points);
    if (n < 0) {
        return EXIT_FAILURE;
    }

    int k = 3; // Number of clusters
    k_means(points, n, k);
    
    return EXIT_SUCCESS;
}