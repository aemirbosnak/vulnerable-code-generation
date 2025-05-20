//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: post-apocalyptic
// Amidst the desolate wasteland, where mutated code roams free, a renegade programmer wields an ancient tool—the Sorting Algorithm.

#include <stdio.h>
#include <stdlib.h>

// The Heap of Skulls—a brutal but efficient sorting technique
void heapify(int *arr, int n, int i) {
  int largest = i, left = 2 * i + 1, right = 2 * i + 2;
  if (left < n && arr[left] > arr[largest])
    largest = left;
  if (right < n && arr[right] > arr[largest])
    largest = right;
  if (largest != i) {
    int temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;
    heapify(arr, n, largest);
  }
}

void heapSort(int *arr, int n) {
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);
  for (int i = n - 1; i >= 0; i--) {
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    heapify(arr, i, 0);
  }
}

// Main—the battlefield where the algorithm wages war
int main() {
  int n, i;
  int *arr = NULL;

  // Gather the spoils of war—an array of scavenged numbers
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  arr = (int *)malloc(n * sizeof(int));
  printf("Enter the elements:\n");
  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  // unleash the horrors of Heap Sort upon the array
  printf("The wasteland before the storm:\n");
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
  heapSort(arr, n);

  // Behold, the spoils of victory—a sorted array
  printf("The wasteland after the storm:\n");
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}