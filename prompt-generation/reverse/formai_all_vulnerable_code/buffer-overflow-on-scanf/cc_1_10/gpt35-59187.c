//FormAI DATASET v1.0 Category: Searching algorithm ; Style: innovative
#include <stdio.h>

#define MAX_SIZE 100

int linear_search(int arr[], int n, int key);

int main()
{
  int array[MAX_SIZE];
  int key, n, i, position;

  printf("\nEnter size of array: ");
  scanf("%d", &n);

  printf("\nEnter elements of array: \n");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &array[i]);
  }

  printf("\nEnter the element to search: ");
  scanf("%d", &key);

  position = linear_search(array, n, key);

  if (position == -1)
  {
    printf("\nElement not found.\n");
  }
  else
  {
    printf("\nElement found at position %d.\n", position + 1);
  }

  return 0;
}

int linear_search(int arr[], int n, int key)
{
  int i;

  for (i = 0; i < n; i++)
  {
    if (arr[i] == key)
    {
      return i;
    }
  }

  return -1;
}