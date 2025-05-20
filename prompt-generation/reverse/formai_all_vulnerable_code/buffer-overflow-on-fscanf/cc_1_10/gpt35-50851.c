//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10000 // maximum number of data points
#define K 5 // number of clusters

// function to calculate euclidean distance between two points
float distance(float x1, float y1, float x2, float y2) {
    float dx = x1 - x2;
    float dy = y1 - y2;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    int n, i, j, k, closest_cluster;
    float x[N], y[N], cx[K], cy[K], min_dist, total_dist;
    int assigned_cluster[N], cluster_size[K];
    
    // read data points from file
    FILE *fp;
    fp = fopen("data.txt", "r");
    if(fp == NULL) {
        printf("Error opening file\n");
        return 0;
    }
    n = 0;
    while(fscanf(fp, "%f %f", &x[n], &y[n]) != EOF) {
        n++;
    }
    
    // initialize cluster centroids randomly
    for(i=0; i<K; i++) {
        cx[i] = x[rand()%n];
        cy[i] = y[rand()%n];
    }
    
    // run k-means algorithm
    int max_iterations = 1000;
    for(i=0; i<max_iterations; i++) {
        // reset sizes and distances
        for(j=0; j<K; j++) {
            cluster_size[j] = 0;
        }
        total_dist = 0;
        // assign each point to closest cluster
        for(j=0; j<n; j++) {
            min_dist = INFINITY;
            for(k=0; k<K; k++) {
                float dist = distance(x[j], y[j], cx[k], cy[k]);
                if(dist < min_dist) {
                    min_dist = dist;
                    closest_cluster = k;
                }
            }
            assigned_cluster[j] = closest_cluster;
            cluster_size[closest_cluster]++;
            total_dist += min_dist;
        }
        // update cluster centroids
        for(j=0; j<K; j++) {
            if(cluster_size[j] > 0) {
                float sum_x = 0, sum_y = 0;
                for(k=0; k<n; k++) {
                    if(assigned_cluster[k] == j) {
                        sum_x += x[k];
                        sum_y += y[k];
                    }
                }
                cx[j] = sum_x / cluster_size[j];
                cy[j] = sum_y / cluster_size[j];
            }
        }
        // check convergence
        float prev_dist = total_dist;
        total_dist = 0;
        for(j=0; j<n; j++) {
            float dist = distance(x[j], y[j], cx[assigned_cluster[j]], cy[assigned_cluster[j]]);
            total_dist += dist;
        }
        float diff = fabs(total_dist - prev_dist);
        if(diff < 0.1) {
            break;
        }
    }
    
    // print results
    for(i=0; i<K; i++) {
        printf("Cluster %d: centroid at (%.2f, %.2f), size = %d\n", i+1, cx[i], cy[i], cluster_size[i]);
    }
    
    return 0;
}