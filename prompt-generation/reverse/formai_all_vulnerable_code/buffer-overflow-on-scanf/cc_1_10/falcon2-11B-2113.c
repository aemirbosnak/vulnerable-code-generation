//Falcon2-11B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ITEMS 100
#define MAX_CLUSTERS 10

int main() {
    int items[MAX_ITEMS];
    int numItems = 0;
    int clusters[MAX_CLUSTERS];
    int numClusters = 0;
    int clusterSize[MAX_CLUSTERS];

    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    for (int i = 0; i < numItems; i++) {
        printf("Enter item %d: ", i + 1);
        scanf("%d", &items[i]);
    }

    printf("Enter the number of clusters: ");
    scanf("%d", &numClusters);

    for (int i = 0; i < numClusters; i++) {
        printf("Enter cluster size for cluster %d: ", i + 1);
        scanf("%d", &clusterSize[i]);
    }

    for (int i = 0; i < numItems; i++) {
        int minDistance = 1000000000;
        int minIndex = -1;

        for (int j = 0; j < numClusters; j++) {
            int distance = fabs(items[i] - clusters[j]);
            if (distance < minDistance) {
                minDistance = distance;
                minIndex = j;
            }
        }

        clusters[minIndex] += items[i];
        items[i] = -1;
    }

    for (int i = 0; i < numClusters; i++) {
        int sum = 0;
        for (int j = 0; j < clusterSize[i]; j++) {
            sum += items[j];
        }
        printf("Cluster %d: %d\n", i + 1, sum);
    }

    return 0;
}