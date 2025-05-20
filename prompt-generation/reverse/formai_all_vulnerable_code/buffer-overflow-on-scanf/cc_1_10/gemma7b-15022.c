//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void search(int **arr, int n, int target)
{
  int i, j, found = 0;

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < MAX; j++)
    {
      if (arr[i][j] == target)
      {
        found = 1;
        break;
      }
    }
  }

  if (found)
  {
    printf("Target found.\n");
  }
  else
  {
    printf("Target not found.\n");
  }
}

int main()
{
  int n, target;
  int **arr;

  printf("Enter the number of rows: ");
  scanf("%d", &n);

  arr = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++)
  {
    arr[i] = (int *)malloc(MAX * sizeof(int));
  }

  printf("Enter the target: ");
  scanf("%d", &target);

  search(arr, n, target);

  return 0;
}