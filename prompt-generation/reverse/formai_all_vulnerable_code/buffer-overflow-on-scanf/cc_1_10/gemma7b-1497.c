//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void cluster(int **arr, int n, int k)
{
  int i, j, d, minDist, clusterSize = 0, center = 0;
  float sum = 0.0, dist = 0.0;

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      if (i != j)
      {
        d = abs(arr[i] - arr[j]);
        minDist = d;
        if (minDist < dist)
        {
          dist = minDist;
          center = j;
        }
      }
    }
  }

  clusterSize = 1 + center;

  printf("The cluster size is: %d\n", clusterSize);
  printf("The center of the cluster is: %d\n", center);
}

int main()
{
  int **arr = NULL;
  int n, k;

  printf("Enter the number of elements: ");
  scanf("%d", &n);

  arr = (int **)malloc(n * sizeof(int *));

  printf("Enter the elements: ");
  for (int i = 0; i < n; i++)
  {
    arr[i] = (int *)malloc(n * sizeof(int));
    scanf("%d", arr[i]);
  }

  printf("Enter the number of clusters: ");
  scanf("%d", &k);

  cluster(arr, n, k);

  return 0;
}