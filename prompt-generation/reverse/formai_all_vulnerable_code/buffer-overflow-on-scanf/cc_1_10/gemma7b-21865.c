//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

// Define the distance function
int distance(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

// Define the cluster function
void cluster(int **arr, int n)
{
    int i, j, k, minDistance, minIndex;
    for (i = 0; i < n; i++)
    {
        minDistance = MAX;
        minIndex = -1;
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                k = distance(arr[i][0], arr[i][1], arr[j][0], arr[j][1]);
                if (k < minDistance)
                {
                    minDistance = k;
                    minIndex = j;
                }
            }
        }
        arr[i][2] = minIndex;
    }
}

int main()
{
    int n, i, j, k;
    int **arr;

    printf("Enter the number of players: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(4 * sizeof(int));
    }

    // Get the players' coordinates and assign them to the array
    for (i = 0; i < n; i++)
    {
        printf("Enter the coordinates of player %d (x, y): ", i + 1);
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    // Cluster the players
    cluster(arr, n);

    // Print the clusters
    for (i = 0; i < n; i++)
    {
        printf("Player %d is in cluster %d\n", i + 1, arr[i][2] + 1);
    }

    return 0;
}