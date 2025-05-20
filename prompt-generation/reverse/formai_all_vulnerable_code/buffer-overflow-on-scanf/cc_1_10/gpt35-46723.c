//FormAI DATASET v1.0 Category: Sorting ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to print an array */
void printArray(int A[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", A[i]);
  printf("\n");
}

/* Function to swap two elements of an array */
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

/* Function to generate random numbers */
void generateRandomNumbers(int A[], int n) {
  srand(time(NULL)); // Seed the random number generator
  for (int i = 0; i < n; i++)
     A[i] = rand() % 100 + 1; // Generate a random number between 1 and 100
}

/* Function to sort an array using Quick Sort algorithm */
void quickSort(int A[], int left, int right) {
  int index = partition(A, left, right);
  if (left < index - 1)
    quickSort(A, left, index - 1);
  if (index < right)
    quickSort(A, index, right);
}

/* Function to partition the array */
int partition(int A[], int left, int right) {
  int pivot = A[(left + right) / 2];
  while (left <= right) {
    while (A[left] < pivot)
      left++;
    while (A[right] > pivot)
      right--;
    if (left <= right) {
      swap(&A[left], &A[right]);
      left++;
      right--;
    }
  }
  return left;
}

int main() {
  int n;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  int A[n];

  // Generate random numbers and print the unsorted array
  generateRandomNumbers(A, n);
  printf("\nUnsorted array:\n");
  printArray(A, n);

  // Sort the array and print the sorted array
  quickSort(A, 0, n - 1);
  printf("\nSorted array:\n");
  printArray(A, n);

  return 0;
}