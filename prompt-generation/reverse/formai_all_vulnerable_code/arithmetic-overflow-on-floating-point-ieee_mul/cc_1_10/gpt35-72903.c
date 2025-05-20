//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define DIMENSIONS 2
#define NUM_POINTS 10
#define CLUSTERS 2
#define MAX_ITERATIONS 10000

float euclidean_distance(float *a, float *b) { // calculate Euclidean distance between two points
    float distance = 0;
    for(int i=0; i<DIMENSIONS; i++) {
        distance += pow(a[i]-b[i], 2);
    }
    return sqrt(distance);
}

int main() {
    float points[NUM_POINTS][DIMENSIONS] = {{1,2}, {2,4}, {5,3}, {6,3}, {8,3}, {1,5}, {2,6}, {3,11}, {5,9}, {6,11}}; // sample data
    float centroids[CLUSTERS][DIMENSIONS] = {{1,5}, {8,3}}; // initialize centroids
    int belongs_to_cluster[NUM_POINTS]; // keep track of which cluster each point belongs to
    int iteration_count = 0;
    int has_converged = 0;

    while(iteration_count < MAX_ITERATIONS && has_converged == 0) {
        for(int i=0; i<NUM_POINTS; i++) {
            int closest_cluster_index = 0;
            float closest_cluster_distance = euclidean_distance(points[i], centroids[0]);
            for(int j=1; j<CLUSTERS; j++) { // find closest centroid
                float distance_to_centroid = euclidean_distance(points[i], centroids[j]);
                if(distance_to_centroid < closest_cluster_distance) {
                    closest_cluster_index = j;
                    closest_cluster_distance = distance_to_centroid;
                }
            }
            belongs_to_cluster[i] = closest_cluster_index; // assign point to closest cluster
        }

        int cluster_size[CLUSTERS] = {0};
        float new_centroids[CLUSTERS][DIMENSIONS] = {0};
        for(int i=0; i<NUM_POINTS; i++) { // calculate new centroids
            int cluster_index = belongs_to_cluster[i];
            for(int j=0; j<DIMENSIONS; j++) {
                new_centroids[cluster_index][j] += points[i][j];
            }
            cluster_size[cluster_index]++;
        }
        for(int i=0; i<CLUSTERS; i++) {
            for(int j=0; j<DIMENSIONS; j++) {
                new_centroids[i][j] /= cluster_size[i];
            }
        }

        float distance_from_old_centroids = 0;
        for(int i=0; i<CLUSTERS; i++) { // check if centroids have converged
            distance_from_old_centroids += euclidean_distance(centroids[i], new_centroids[i]);
        }
        if(distance_from_old_centroids == 0) {
            has_converged = 1;
        } else {
            for(int i=0; i<CLUSTERS; i++) { // update centroids
                for(int j=0; j<DIMENSIONS; j++) {
                    centroids[i][j] = new_centroids[i][j];
                }
            }
            iteration_count++;
        }
    }

    printf("Final centroids:\n");
    for(int i=0; i<CLUSTERS; i++) {
        printf("%d: (%.2f, %.2f)\n", i, centroids[i][0], centroids[i][1]);
    }

    return 0;
}