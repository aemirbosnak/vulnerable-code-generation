//FormAI DATASET v1.0 Category: Searching algorithm ; Style: complex
#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int n, int x);

int main()
{
  int num, index, i;
  int arr[10] = {10, 22, 33, 45, 56, 67, 78, 89, 90, 99};

  printf("Enter the number you want to search: ");
  scanf("%d", &num);

  index = binarySearch(arr, 10, num);

  if (index == -1)
  {
    printf("The number is not present in the array.\n");
  }
  else
  {
    printf("The number %d is found at index %d.\n", num, index);
  }

  return 0;
}

int binarySearch(int arr[], int n, int x)
{
  int first = 0, last = n - 1, mid;

  while (first <= last)
  {
    mid = (first + last) / 2;

    if (arr[mid] == x)
    {
      return mid;
    }

    if (arr[mid] < x)
    {
      first = mid + 1;
    }
    else
    {
      last = mid - 1;
    }
  }
  return -1;
}