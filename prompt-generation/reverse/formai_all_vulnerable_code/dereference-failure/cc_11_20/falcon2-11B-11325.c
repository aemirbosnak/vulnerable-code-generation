//Falcon2-11B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_CLUSTERS 100

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <k>\n", argv[0]);
        exit(1);
    }
    
    int k = atoi(argv[1]);
    int n = 0;
    
    int *data = (int *)malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++) {
        data[i] = rand() % 100;
    }
    
    int *centers = (int *)malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++) {
        centers[i] = rand() % 100;
    }
    
    int *cluster_count = (int *)malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++) {
        cluster_count[i] = 0;
    }
    
    while (1) {
        int min_dist = 100000;
        int min_index = -1;
        
        for (int i = 0; i < n; i++) {
            int dist = abs(data[i] - centers[0]);
            if (dist < min_dist) {
                min_dist = dist;
                min_index = 0;
            } else if (dist == min_dist) {
                min_index = -1;
            }
            
            for (int j = 1; j < k; j++) {
                int dist = abs(data[i] - centers[j]);
                if (dist < min_dist) {
                    min_dist = dist;
                    min_index = j;
                } else if (dist == min_dist) {
                    min_index = -1;
                }
            }
            
            if (min_index == -1) {
                cluster_count[0]++;
            } else {
                cluster_count[min_index]++;
            }
        }
        
        for (int i = 0; i < k; i++) {
            centers[i] = 0;
            for (int j = 0; j < cluster_count[i]; j++) {
                centers[i] += data[j];
            }
            centers[i] /= cluster_count[i];
        }
        
        int changed = 0;
        for (int i = 0; i < k; i++) {
            if (centers[i]!= data[i]) {
                changed = 1;
                break;
            }
        }
        
        if (!changed) {
            break;
        }
    }
    
    printf("Number of clusters: %d\n", k);
    for (int i = 0; i < k; i++) {
        printf("Cluster %d: %d\n", i, centers[i]);
    }
    
    free(data);
    free(centers);
    free(cluster_count);
    
    return 0;
}