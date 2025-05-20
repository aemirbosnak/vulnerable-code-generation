//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define K 3 // Number of clusters

typedef struct {
    float x, y; // Coordinates of the point
    int cluster; // Cluster label
} Point;

Point points[MAX_POINTS]; // Array of points
Point centroids[K]; // Array of centroids

// Function prototypes
void generate_random_points(int n);
void initialize_centroids();
float calculate_distance(Point a, Point b);
void assign_clusters(int n);
void update_centroids(int n);
void print_result(int n);

int main() {
    int n;
    
    printf("Welcome to the K-Means Clustering Algorithm!\n");
    printf("Enter number of points to generate (max %d): ", MAX_POINTS);
    scanf("%d", &n);
    if (n > MAX_POINTS) {
        printf("Exceeding maximum points. Setting to %d.\n", MAX_POINTS);
        n = MAX_POINTS;
    }
    
    generate_random_points(n);
    initialize_centroids();
    
    for(int iter = 0; iter < 10; iter++) { // Limit to 10 iterations for simplicity
        assign_clusters(n);
        update_centroids(n);
        printf("Iteration %d completed!\n", iter + 1);
    }
    
    print_result(n);
    
    return 0;
}

// Generate random points
void generate_random_points(int n) {
    srand(time(NULL)); // Seed for random number generation
    for (int i = 0; i < n; i++) {
        points[i].x = (float)(rand() % 100); // X coordinates in range 0 to 99
        points[i].y = (float)(rand() % 100); // Y coordinates in range 0 to 99
        points[i].cluster = -1; // Assign no cluster initially
    }
    printf("Generated %d random points!\n", n);
}

// Initialize centroids randomly
void initialize_centroids() {
    for (int i = 0; i < K; i++) {
        centroids[i] = points[rand() % MAX_POINTS]; // Randomly select initial centroids
    }
    printf("Initialized centroids at random points!\n");
}

// Calculate distance between two points
float calculate_distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Assign each point to the closest centroid
void assign_clusters(int n) {
    for (int i = 0; i < n; i++) {
        float min_distance = INFINITY;
        int closest_centroid = -1;
        
        for (int j = 0; j < K; j++) {
            float distance = calculate_distance(points[i], centroids[j]);
            if (distance < min_distance) {
                min_distance = distance;
                closest_centroid = j;
            }
        }
        
        points[i].cluster = closest_centroid; // Assign point to the closest centroid
    }
    printf("Clusters assigned based on current centroids!\n");
}

// Update centroid positions
void update_centroids(int n) {
    int cluster_count[K] = {0}; // Count of points in each cluster
    for (int j = 0; j < K; j++) {
        centroids[j].x = 0;
        centroids[j].y = 0;
    }

    // Sum points in each cluster
    for (int i = 0; i < n; i++) {
        centroids[points[i].cluster].x += points[i].x;
        centroids[points[i].cluster].y += points[i].y;
        cluster_count[points[i].cluster]++;
    }

    // Calculate new centroid positions
    for (int j = 0; j < K; j++) {
        if (cluster_count[j] > 0) {
            centroids[j].x /= cluster_count[j];
            centroids[j].y /= cluster_count[j];
        }
    }
    printf("Centroids updated based on cluster assignments!\n");
}

// Print the final result
void print_result(int n) {
    printf("Final clustering results:\n");
    for (int i = 0; i < n; i++) {
        printf("Point (%.2f, %.2f) is in cluster %d\n", points[i].x, points[i].y, points[i].cluster);
    }
    printf("Final centroids:\n");
    for (int j = 0; j < K; j++) {
        printf("Centroid %d: (%.2f, %.2f)\n", j, centroids[j].x, centroids[j].y);
    }
}