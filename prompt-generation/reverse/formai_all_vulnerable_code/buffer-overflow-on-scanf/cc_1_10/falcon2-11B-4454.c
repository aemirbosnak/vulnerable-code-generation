//Falcon2-11B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, k;
    int *arr, *clust;
    int i, j, c, num_clust;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the number of clusters: ");
    scanf("%d", &k);

    arr = (int*)malloc(n * sizeof(int));
    clust = (int*)malloc(k * sizeof(int));

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    num_clust = 0;
    while (num_clust < k) {
        for (c = 0; c < n; c++) {
            for (j = 0; j < n; j++) {
                if (fabs(arr[c] - arr[j]) < fabs(arr[c] - clust[num_clust])) {
                    clust[num_clust] = arr[j];
                    break;
                }
            }
            if (j == n) {
                clust[num_clust] = arr[c];
                num_clust++;
                break;
            }
        }
    }

    printf("Cluster 1: ");
    for (i = 0; i < k; i++) {
        printf("%d ", clust[i]);
    }
    printf("\n");

    for (i = 0; i < k; i++) {
        free(clust[i]);
    }
    free(clust);

    return 0;
}