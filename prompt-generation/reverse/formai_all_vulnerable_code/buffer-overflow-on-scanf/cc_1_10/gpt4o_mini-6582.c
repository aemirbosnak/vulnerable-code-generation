//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DATA_POINTS 100
#define MAX_CLUSTERS 10
#define DIMENSIONS 2
#define MAX_ITERATIONS 100

typedef struct {
    double data[DIMENSIONS];
    int cluster;  // The cluster it belongs to
} DataPoint;

typedef struct {
    double centroid[DIMENSIONS];
    int clusterSize;  // Number of points in this cluster
} Cluster;

void init_data(DataPoint *dataPoints, int n);
void print_data(DataPoint *dataPoints, int n);
void kmeans(DataPoint *dataPoints, int n, int k);
void assign_clusters(DataPoint *dataPoints, int n, Cluster *clusters, int k);
void update_centroids(DataPoint *dataPoints, int n, Cluster *clusters, int k);
double euclidean_distance(double *a, double *b);

int main() {
    int n, k;
    
    printf("Enter the number of data points (max %d): ", MAX_DATA_POINTS);
    scanf("%d", &n);
    
    if (n > MAX_DATA_POINTS) {
        printf("Error: Number of data points exceeds maximum limit.\n");
        return -1;
    }
    
    printf("Enter the number of clusters (max %d): ", MAX_CLUSTERS);
    scanf("%d", &k);
    
    if (k > MAX_CLUSTERS || k > n) {
        printf("Error: Number of clusters exceeds maximum limit or is greater than data points.\n");
        return -1;
    }
    
    DataPoint dataPoints[MAX_DATA_POINTS];
    init_data(dataPoints, n);
    
    printf("Initial Data Points:\n");
    print_data(dataPoints, n);
    
    kmeans(dataPoints, n, k);
    
    printf("Final Clusters:\n");
    print_data(dataPoints, n);
    
    return 0;
}

void init_data(DataPoint *dataPoints, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter coordinates for data point %d (%d dimensions): ", i + 1, DIMENSIONS);
        for (int j = 0; j < DIMENSIONS; j++) {
            scanf("%lf", &dataPoints[i].data[j]);
        }
        dataPoints[i].cluster = -1;  // Unassigned cluster
    }
}

void print_data(DataPoint *dataPoints, int n) {
    for (int i = 0; i < n; i++) {
        printf("Data Point %d: (", i + 1);
        for (int j = 0; j < DIMENSIONS; j++) {
            printf("%lf", dataPoints[i].data[j]);
            if (j < DIMENSIONS - 1) printf(", ");
        }
        printf(") - Cluster: %d\n", dataPoints[i].cluster);
    }
}

void kmeans(DataPoint *dataPoints, int n, int k) {
    Cluster clusters[MAX_CLUSTERS];
    
    // Initialize clusters randomly
    for (int i = 0; i < k; i++) {
        clusters[i].centroid[0] = dataPoints[rand() % n].data[0];
        clusters[i].centroid[1] = dataPoints[rand() % n].data[1];
        clusters[i].clusterSize = 0;
    }

    int iterations = 0;
    int changed = 1;

    while (changed && iterations < MAX_ITERATIONS) {
        changed = 0;
        assign_clusters(dataPoints, n, clusters, k);
        update_centroids(dataPoints, n, clusters, k);
        iterations++;
    }
}

void assign_clusters(DataPoint *dataPoints, int n, Cluster *clusters, int k) {
    for (int i = 0; i < n; i++) {
        int closest = -1;
        double minDist = HUGE_VAL;
        for (int j = 0; j < k; j++) {
            double dist = euclidean_distance(dataPoints[i].data, clusters[j].centroid);
            if (dist < minDist) {
                minDist = dist;
                closest = j;
            }
        }
        if (dataPoints[i].cluster != closest) {
            dataPoints[i].cluster = closest;
        }
    }
}

void update_centroids(DataPoint *dataPoints, int n, Cluster *clusters, int k) {
    // Reset cluster sizes and centroids
    for (int i = 0; i < k; i++) {
        clusters[i].clusterSize = 0;
        clusters[i].centroid[0] = 0.0;
        clusters[i].centroid[1] = 0.0;
    }

    // Accumulate values for centroids
    for (int i = 0; i < n; i++) {
        int clusterId = dataPoints[i].cluster;
        if (clusterId != -1) {
            clusters[clusterId].centroid[0] += dataPoints[i].data[0];
            clusters[clusterId].centroid[1] += dataPoints[i].data[1];
            clusters[clusterId].clusterSize++;
        }
    }

    // Update centroids
    for (int i = 0; i < k; i++) {
        if (clusters[i].clusterSize > 0) {
            clusters[i].centroid[0] /= clusters[i].clusterSize;
            clusters[i].centroid[1] /= clusters[i].clusterSize;
        }
    }
}

double euclidean_distance(double *a, double *b) {
    double dist = 0.0;
    for (int i = 0; i < DIMENSIONS; i++) {
        dist += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return sqrt(dist);
}