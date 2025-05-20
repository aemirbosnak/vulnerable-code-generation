//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

void cluster(int **arr, int n, int k)
{
    int i, j, l, d, min, centroid[k], ctr[k], cluster[n];
    double dis[n][n];
    
    for(i = 0; i < n; i++)
    {
        cluster[i] = -1;
    }
    
    // Calculate the distance matrix
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            dis[i][j] = sqrt(pow(arr[i] - arr[j], 2) + pow(arr[i] - arr[j], 2));
        }
    }
    
    // Find the centroid for each cluster
    for(l = 0; l < k; l++)
    {
        centroid[l] = -1;
    }
    
    for(i = 0; i < n; i++)
    {
        min = MAX;
        for(j = 0; j < k; j++)
        {
            if(centroid[j] == -1)
            {
                ctr[j] = i;
                centroid[j] = arr[i];
                min = dis[i][j];
            }
        }
        cluster[i] = ctr[j];
    }
    
    // Print the cluster membership
    for(i = 0; i < n; i++)
    {
        printf("Cluster membership of %d: %d\n", i, cluster[i]);
    }
}

int main()
{
    int **arr, n, k;
    
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    
    arr = (int *)malloc(n * sizeof(int));
    printf("Enter the data points: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the number of clusters: ");
    scanf("%d", &k);
    
    cluster(arr, n, k);
    
    return 0;
}