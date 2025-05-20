//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function to calculate Euclidean distance between two points
float calculateDistance(float x1, float y1, float x2, float y2) {
    float distance;
    distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return distance;
}

int main() {
    int k, i, j, old_assigned_cluster, new_assigned_cluster, iterations;
    float x[10], y[10], centroids[3][2], distances[3], min_distance;
    
    // input the data points
    for(i = 0; i < 10; i++) {
        printf("Enter x and y coordinates of point %d: ", i+1);
        scanf("%f %f", &x[i], &y[i]);
    }
    
    // input the number of clusters
    printf("\nEnter the number of clusters (limit 3): ");
    scanf("%d", &k);
    
    // initialize the centroids randomly
    for(i = 0; i < k; i++) {
        centroids[i][0] = x[rand() % 10];
        centroids[i][1] = y[rand() % 10];
    }
    
    // assign each point to the nearest centroid
    int assigned_cluster[10];
    for(i = 0; i < 10; i++) {
        min_distance = calculateDistance(x[i], y[i], centroids[0][0], centroids[0][1]);
        assigned_cluster[i] = 0;
        for(j = 1; j < k; j++) {
            distances[j] = calculateDistance(x[i], y[i], centroids[j][0], centroids[j][1]);
            if(distances[j] < min_distance) {
                min_distance = distances[j];
                assigned_cluster[i] = j;
            }
        }
    }
    
    // iterate until convergence
    iterations = 0;
    do {
        // update centroids
        for(i = 0; i < k; i++) {
            float sum_x = 0, sum_y = 0;
            int count = 0;
            for(j = 0; j < 10; j++) {
                if(assigned_cluster[j] == i) {
                    sum_x += x[j];
                    sum_y += y[j];
                    count++;
                }
            }
            centroids[i][0] = sum_x / count;
            centroids[i][1] = sum_y / count;
        }
        
        // re-assign points to nearest centroid
        for(i = 0; i < 10; i++) {
            old_assigned_cluster = assigned_cluster[i];
            min_distance = calculateDistance(x[i], y[i], centroids[0][0], centroids[0][1]);
            assigned_cluster[i] = 0;
            for(j = 1; j < k; j++) {
                distances[j] = calculateDistance(x[i], y[i], centroids[j][0], centroids[j][1]);
                if(distances[j] < min_distance) {
                    min_distance = distances[j];
                    assigned_cluster[i] = j;
                }
            }
            if(old_assigned_cluster != assigned_cluster[i]) {
                // point was re-assigned, increase iteration count
                iterations++;
            }
        }
    } while(iterations > 0);
    
    // output the results
    printf("\nCluster 1:\n");
    for(i = 0; i < 10; i++) {
        if(assigned_cluster[i] == 0) {
            printf("(%f, %f)\n", x[i], y[i]);
        }
    }
    printf("\nCluster 2:\n");
    for(i = 0; i < 10; i++) {
        if(assigned_cluster[i] == 1) {
            printf("(%f, %f)\n", x[i], y[i]);
        }
    }
    if(k == 3) {
        printf("\nCluster 3:\n");
        for(i = 0; i < 10; i++) {
            if(assigned_cluster[i] == 2) {
                printf("(%f, %f)\n", x[i], y[i]);
            }
        }
    }
    
    return 0;
}