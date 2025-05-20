//FormAI DATASET v1.0 Category: Sorting ; Style: imaginative
#include<stdio.h>

// Function to swap two elements
void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

// Function to perform Quick sort
void quicksort(int arr[], int low, int high)
{
  if (low < high)
  {
    // select a pivot element
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
      // If current element is smaller than or equal to pivot
      if (arr[j] <= pivot)
      {
        i++;    // increment index of smaller element
        swap(&arr[i], &arr[j]);
      }
    }
    swap(&arr[i + 1], &arr[high]);
    int pi = i + 1;   // partition index
    // Recursive call to quicksort
    quicksort(arr, low, pi - 1);
    quicksort(arr, pi + 1, high);
  }
}

int main()
{
  int size;
  printf("Enter the size of the array: ");
  scanf("%d", &size);
  int arr[size];
  printf("Enter the elements of the array: ");
  for(int i=0;i<size;i++)
  {
    scanf("%d", &arr[i]);
  }
  printf("Before sorting: ");
  for(int i=0;i<size;i++)
  {
    printf("%d ", arr[i]);
  }
  quicksort(arr, 0, size-1);   // calling quicksort function
  printf("\nAfter sorting: ");
  for(int i=0;i<size;i++)
  {
    printf("%d ", arr[i]);
  }
  return 0;
}