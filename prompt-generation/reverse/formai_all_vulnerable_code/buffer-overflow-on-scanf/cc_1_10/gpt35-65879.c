//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ARRAY_SIZE 50 // Maximum number of data points
#define MAX_ITERATIONS 10 // Maximum number of iterations for algorithm

// Define data point structure
typedef struct data_point {
    float x;
    float y;
} data_point;

// Define cluster structure
typedef struct cluster {
    data_point centroid;
    int num_points;
    data_point points[MAX_ARRAY_SIZE];
} cluster;

// Function to calculate Euclidean distance between two points
float calc_distance(data_point p1, data_point p2) {
    float distance = sqrtf(powf(p1.x - p2.x, 2) + powf(p1.y - p2.y, 2));
    return distance;
}

// Function to initialize clusters
void init_clusters(cluster* clusters, int num_clusters, data_point* data, int num_data_points) {
    // Randomly assign data points to clusters
    for (int i = 0; i < num_data_points; i++) {
        int random_cluster_index = rand() % num_clusters;
        cluster* random_cluster = &clusters[random_cluster_index];
        random_cluster->points[random_cluster->num_points] = data[i];
        random_cluster->num_points++;
    }
    
    // Calculate initial centroid positions
    for (int i = 0; i < num_clusters; i++) {
        cluster* current_cluster = &clusters[i];
        float x_sum = 0;
        float y_sum = 0;
        for (int j = 0; j < current_cluster->num_points; j++) {
            x_sum += current_cluster->points[j].x;
            y_sum += current_cluster->points[j].y;
        }
        current_cluster->centroid.x = x_sum / current_cluster->num_points;
        current_cluster->centroid.y = y_sum / current_cluster->num_points;
    }
}

// Function to update cluster centroids
void update_centroids(cluster* clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        cluster* current_cluster = &clusters[i];
        float x_sum = 0;
        float y_sum = 0;
        for (int j = 0; j < current_cluster->num_points; j++) {
            x_sum += current_cluster->points[j].x;
            y_sum += current_cluster->points[j].y;
        }
        current_cluster->centroid.x = x_sum / current_cluster->num_points;
        current_cluster->centroid.y = y_sum / current_cluster->num_points;
    }
}

// Function to assign data points to nearest cluster
void assign_points_to_clusters(cluster* clusters, int num_clusters, data_point* data, int num_data_points) {
    for (int i = 0; i < num_data_points; i++) {
        float min_distance = INFINITY;
        int min_cluster_index = 0;
        for (int j = 0; j < num_clusters; j++) {
            float distance = calc_distance(data[i], clusters[j].centroid);
            if (distance < min_distance) {
                min_distance = distance;
                min_cluster_index = j;
            }
        }
        clusters[min_cluster_index].points[clusters[min_cluster_index].num_points] = data[i];
        clusters[min_cluster_index].num_points++;
    }
}

// Function to initialize data points
void init_data_points(data_point* data, int num_data_points) {
    // Randomly generate data points
    for (int i = 0; i < num_data_points; i++) {
        data[i].x = ((float) rand() / RAND_MAX) * 100;
        data[i].y = ((float) rand() / RAND_MAX) * 100;
    }
}

// Function to print cluster information
void print_clusters(cluster* clusters, int num_clusters) {
    printf("**** CLUSTER INFORMATION ****\n");
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d\n", i);
        printf("\tCentroid: (%.2f, %.2f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
        printf("\tNum Points: %d\n", clusters[i].num_points);
        printf("\tPoints:\n");
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("\t\t(%.2f, %.2f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
    }
}

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Initialize data and cluster variables
    data_point data[MAX_ARRAY_SIZE];
    cluster clusters[MAX_ARRAY_SIZE];
    int num_clusters;
    int num_data_points;
    
    // Get user input for number of clusters and data points
    printf("Enter number of clusters: ");
    scanf("%d", &num_clusters);
    printf("Enter number of data points: ");
    scanf("%d", &num_data_points);
    
    // Check that user input is not greater than maximum array size
    if (num_clusters > MAX_ARRAY_SIZE || num_data_points > MAX_ARRAY_SIZE) {
        printf("Error: number of clusters and data points must be less than or equal to %d.\n", MAX_ARRAY_SIZE);
        return 1;
    }
    
    // Initialize data points
    init_data_points(data, num_data_points);
    
    // Initialize clusters
    init_clusters(clusters, num_clusters, data, num_data_points);
    
    // Run clustering algorithm for a maximum of MAX_ITERATIONS iterations
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        // Assign data points to nearest cluster
        assign_points_to_clusters(clusters, num_clusters, data, num_data_points);
        
        // Update cluster centroids
        update_centroids(clusters, num_clusters);
    }
    
    // Print cluster information
    print_clusters(clusters, num_clusters);
    
    return 0;
}