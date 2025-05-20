//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <time.h>

#define MAX_PLAYERS 5
#define MAX_POINTS 100
#define DIMENSIONS 2
#define K 3

typedef struct {
    double points[MAX_POINTS][DIMENSIONS];
    int count;
} PlayerData;

PlayerData playerData[MAX_PLAYERS];
pthread_mutex_t mutex;

double distance(double a[], double b[]) {
    double sum = 0.0;
    for (int i = 0; i < DIMENSIONS; i++) {
        sum += pow(a[i] - b[i], 2);
    }
    return sqrt(sum);
}

void *add_points(void *arg) {
    int player_id = *((int *)arg);
    printf("Player %d, enter number of points to add (max %d): ", player_id, MAX_POINTS);
    int points_to_add;
    scanf("%d", &points_to_add);
    
    if (points_to_add > MAX_POINTS - playerData[player_id].count) {
        printf("Not enough space for all points. Only adding %d points.\n", MAX_POINTS - playerData[player_id].count);
        points_to_add = MAX_POINTS - playerData[player_id].count;
    }

    for (int i = 0; i < points_to_add; i++) {
        printf("Enter the coordinates for point %d (x y): ", i + 1);
        scanf("%lf %lf", &playerData[player_id].points[playerData[player_id].count][0], 
              &playerData[player_id].points[playerData[player_id].count][1]);
        playerData[player_id].count++;
    }
    return NULL;
}

void kmeans_clustering() {
    double centroids[K][DIMENSIONS];
    double new_centroids[K][DIMENSIONS];
    int cluster_assignments[MAX_POINTS];
    int iterations = 10;
    int total_points = 0;

    // Combine all player points
    for (int player = 0; player < MAX_PLAYERS; player++) {
        for (int i = 0; i < playerData[player].count; i++) {
            centroids[total_points][0] = playerData[player].points[i][0];
            centroids[total_points][1] = playerData[player].points[i][1];
            total_points++;
        }
    }

    // Initialize centroids randomly
    srand(time(NULL)); 
    for (int i = 0; i < K; i++) {
        centroids[i][0] = centroids[rand() % total_points][0];
        centroids[i][1] = centroids[rand() % total_points][1];
    }

    // K-means algorithm
    for (int it = 0; it < iterations; it++) {
        // Assign clusters
        for (int i = 0; i < total_points; i++) {
            int closest = 0;
            double min_distance = distance(centroids[0], centroids[i]);
            for (int j = 1; j < K; j++) {
                double dist = distance(centroids[j], centroids[i]);
                if (dist < min_distance) {
                    min_distance = dist;
                    closest = j;
                }
            }
            cluster_assignments[i] = closest;
        }

        // Update centroids
        int counts[K] = {0};
        for (int j = 0; j < K; j++) {
            new_centroids[j][0] = 0;
            new_centroids[j][1] = 0;
        }
        
        for (int i = 0; i < total_points; i++) {
            new_centroids[cluster_assignments[i]][0] += centroids[i][0];
            new_centroids[cluster_assignments[i]][1] += centroids[i][1];
            counts[cluster_assignments[i]]++;
        }

        for (int j = 0; j < K; j++) {
            if (counts[j] > 0) {
                new_centroids[j][0] /= counts[j];
                new_centroids[j][1] /= counts[j];
            }
            centroids[j][0] = new_centroids[j][0];
            centroids[j][1] = new_centroids[j][1];
        }
    }
    
    // Print results
    printf("Cluster assignments:\n");
    for (int i = 0; i < total_points; i++) {
        printf("Point (%lf, %lf) assigned to cluster %d\n", 
               centroids[i][0], centroids[i][1], cluster_assignments[i]);
    }
}

int main() {
    pthread_t threads[MAX_PLAYERS];
    int player_ids[MAX_PLAYERS];
    
    pthread_mutex_init(&mutex, NULL);
    
    for (int i = 0; i < MAX_PLAYERS; i++) {
        player_ids[i] = i;
        playerData[i].count = 0;
        pthread_create(&threads[i], NULL, add_points, (void *)&player_ids[i]);
    }

    for (int i = 0; i < MAX_PLAYERS; i++) {
        pthread_join(threads[i], NULL);
    }

    kmeans_clustering();

    pthread_mutex_destroy(&mutex);
    
    return 0;
}