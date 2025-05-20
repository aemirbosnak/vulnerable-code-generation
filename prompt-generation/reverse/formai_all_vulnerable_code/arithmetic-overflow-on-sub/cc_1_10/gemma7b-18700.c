//Gemma-7B DATASET v1.0 Category: Sorting ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void paranoid_sort(int **arr, int n)
{
  int i, j, k, l, m, flag = 0;

  for (i = 0; i < n - 1; i++)
  {
    for (j = i + 1; j < n; j++)
    {
      if (arr[i] > arr[j])
      {
        flag = 1;
        l = arr[i];
        m = arr[j];
        arr[i] = arr[j];
        arr[j] = l;
      }
    }
  }

  if (flag)
  {
    printf("Data modified.\n");
  }
  else
  {
    printf("No changes.\n");
  }
}

int main()
{
  int **arr = NULL;
  int n = 0;

  printf("Enter the number of elements: ");
  scanf("%d", &n);

  arr = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++)
  {
    arr[i] = (int *)malloc(MAX_SIZE * sizeof(int));
  }

  printf("Enter the elements: ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", arr[i]);
  }

  paranoid_sort(arr, n);

  printf("The sorted data is: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }

  return 0;
}