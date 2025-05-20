//FormAI DATASET v1.0 Category: Data mining ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ATTRIBUTES 10
#define MAX_INSTANCES 100
#define MAX_CLUSTER_SIZE 10

// Object representing an instance of the dataset
typedef struct Instance {
    double attributes[MAX_ATTRIBUTES];
} Instance;

// Object representing a cluster of instances
typedef struct Cluster {
    Instance centroid;
    Instance instances[MAX_CLUSTER_SIZE];
    int size;
} Cluster;

// Function to compute the distance between two instances using Euclidean distance
double distance(Instance a, Instance b) {
    double sum = 0.0;
    for (int i = 0; i < MAX_ATTRIBUTES; i++) {
        sum += pow(a.attributes[i] - b.attributes[i], 2);
    }
    return sqrt(sum);
}

// Function to find the nearest cluster centroid to a given instance
int find_nearest_centroid(Instance instance, Cluster* clusters, int num_clusters) {
    double min_distance = distance(instance, clusters[0].centroid);
    int min_index = 0;
    for (int i = 1; i < num_clusters; i++) {
        double d = distance(instance, clusters[i].centroid);
        if (d < min_distance) {
            min_distance = d;
            min_index = i;
        }
    }
    return min_index;
}

// Function to update the centroids of the clusters
void update_centroids(Cluster* clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        if (clusters[i].size == 0) continue;
        for (int j = 0; j < MAX_ATTRIBUTES; j++) {
            double sum = 0.0;
            for (int k = 0; k < clusters[i].size; k++) {
                sum += clusters[i].instances[k].attributes[j];
            }
            clusters[i].centroid.attributes[j] = sum / clusters[i].size;
        }
    }
}

int main() {

    // Read in the dataset
    Instance dataset[MAX_INSTANCES];
    int num_instances = 0;
    FILE* file = fopen("dataset.txt", "r");
    if (file == NULL) {
        printf("Error: dataset file not found");
        return -1;
    }
    while (!feof(file) && num_instances < MAX_INSTANCES) {
        for (int i = 0; i < MAX_ATTRIBUTES; i++) {
            fscanf(file, "%lf", &dataset[num_instances].attributes[i]);
        }
        num_instances++;
    }
    fclose(file);

    // Initialize the clusters
    Cluster clusters[3];
    clusters[0].centroid = dataset[0];
    clusters[1].centroid = dataset[1];
    clusters[2].centroid = dataset[2];
    clusters[0].size = 0;
    clusters[1].size = 0;
    clusters[2].size = 0;

    // Perform the clustering algorithm
    int num_iterations = 0;
    while (num_iterations < 10) {
        // Assign instances to nearest clusters
        for (int i = 0; i < num_instances; i++) {
            int cluster_index = find_nearest_centroid(dataset[i], clusters, 3);
            clusters[cluster_index].instances[clusters[cluster_index].size++] = dataset[i];
        }
        // Update the centroids
        update_centroids(clusters, 3);
        // Clear the instances from the clusters
        for (int i = 0; i < 3; i++) {
            clusters[i].size = 0;
        }
        // Increment the iteration counter
        num_iterations++;
    }

    // Print out the final clusters
    printf("Cluster 1:\n");
    for (int i = 0; i < clusters[0].size; i++) {
        printf("(%lf, %lf, %lf, %lf)\n",
               clusters[0].instances[i].attributes[0],
               clusters[0].instances[i].attributes[1],
               clusters[0].instances[i].attributes[2],
               clusters[0].instances[i].attributes[3]);
    }
    printf("Cluster 2:\n");
    for (int i = 0; i < clusters[1].size; i++) {
        printf("(%lf, %lf, %lf, %lf)\n",
               clusters[1].instances[i].attributes[0],
               clusters[1].instances[i].attributes[1],
               clusters[1].instances[i].attributes[2],
               clusters[1].instances[i].attributes[3]);
    }
    printf("Cluster 3:\n");
    for (int i = 0; i < clusters[2].size; i++) {
        printf("(%lf, %lf, %lf, %lf)\n",
               clusters[2].instances[i].attributes[0],
               clusters[2].instances[i].attributes[1],
               clusters[2].instances[i].attributes[2],
               clusters[2].instances[i].attributes[3]);
    }

    return 0;
}