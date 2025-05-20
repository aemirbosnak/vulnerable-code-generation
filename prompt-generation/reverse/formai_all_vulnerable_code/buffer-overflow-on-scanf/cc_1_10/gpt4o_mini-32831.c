//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <string.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 10
#define DIMENSIONS 2
#define MAX_ITERATIONS 100

typedef struct {
    float point[DIMENSIONS];
    int cluster_id;
} DataPoint;

typedef struct {
    float centroid[DIMENSIONS];
    int count;
} Cluster;

typedef struct {
    DataPoint *data;
    Cluster *clusters;
    int num_points;
    int num_clusters;
    int thread_id;
} ThreadData;

DataPoint data_points[MAX_POINTS];
Cluster clusters[MAX_CLUSTERS];
int num_points = 0, num_clusters = 0;

float euclidean_distance(float *a, float *b) {
    float sum = 0.0;
    for (int i = 0; i < DIMENSIONS; i++) {
        sum += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return sqrt(sum);
}

void *assign_clusters(void *arg) {
    ThreadData *td = (ThreadData *)arg;
    int thread_id = td->thread_id;

    for (int i = thread_id; i < td->num_points; i += 4) { // Assuming 4 threads for simplicity
        float min_distance = INFINITY;
        int closest_cluster = -1;

        for (int j = 0; j < td->num_clusters; j++) {
            float distance = euclidean_distance(td->data[i].point, td->clusters[j].centroid);
            if (distance < min_distance) {
                min_distance = distance;
                closest_cluster = j;
            }
        }
        td->data[i].cluster_id = closest_cluster;
    }
    pthread_exit(NULL);
}

void update_centroids() {
    for (int j = 0; j < num_clusters; j++) {
        memset(clusters[j].centroid, 0, sizeof(clusters[j].centroid));
        clusters[j].count = 0;
    }

    for (int i = 0; i < num_points; i++) {
        int cluster_id = data_points[i].cluster_id;
        clusters[cluster_id].count++;
        for (int d = 0; d < DIMENSIONS; d++) {
            clusters[cluster_id].centroid[d] += data_points[i].point[d];
        }
    }

    for (int j = 0; j < num_clusters; j++) {
        if (clusters[j].count != 0) {
            for (int d = 0; d < DIMENSIONS; d++) {
                clusters[j].centroid[d] /= clusters[j].count;
            }
        }
    }
}

int main() {
    printf("Enter the number of data points: ");
    scanf("%d", &num_points);
    printf("Enter the number of clusters: ");
    scanf("%d", &num_clusters);

    for (int i = 0; i < num_points; i++) {
        printf("Enter point %d (x y): ", i + 1);
        scanf("%f %f", &data_points[i].point[0], &data_points[i].point[1]);
    }

    // Randomly initialize centroids
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].centroid[0] = rand() % 10;
        clusters[i].centroid[1] = rand() % 10;
    }

    pthread_t threads[4];
    for (int iter = 0; iter < MAX_ITERATIONS; iter++) {
        // Assign clusters
        ThreadData td[4];
        for (int t = 0; t < 4; t++) {
            td[t].data = data_points;
            td[t].clusters = clusters;
            td[t].num_points = num_points;
            td[t].num_clusters = num_clusters;
            td[t].thread_id = t;
            pthread_create(&threads[t], NULL, assign_clusters, (void *)&td[t]);
        }

        for (int t = 0; t < 4; t++) {
            pthread_join(threads[t], NULL);
        }

        // Update centroids
        update_centroids();

        printf("Iteration %d\n", iter + 1);
        for (int j = 0; j < num_clusters; j++) {
            printf("Cluster %d centroid: (%.2f, %.2f)\n", j, clusters[j].centroid[0], clusters[j].centroid[1]);
        }
        printf("\n");
    }

    printf("Final clusters:\n");
    for (int i = 0; i < num_points; i++) {
        printf("Point (%.2f, %.2f) assigned to Cluster %d\n", 
            data_points[i].point[0], data_points[i].point[1], data_points[i].cluster_id);
    }

    return 0;
}