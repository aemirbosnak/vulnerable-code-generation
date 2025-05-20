//FormAI DATASET v1.0 Category: Sorting ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two integers
void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Function to generate random integers
void generateRandomNumbers(int arr[], int n) {
  srand(time(0));
  for(int i = 0; i < n; i++) {
    arr[i] = rand() % 100;
  }
}

// Function to print an array
void printArray(int arr[], int n) {
  for(int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// Bubble Sort Algorithm
void bubbleSort(int arr[], int n) {
  for(int i = 0; i < n-1; i++) {
    for(int j = 0; j < n-i-1; j++) {
      if(arr[j] > arr[j+1]) {
        swap(&arr[j], &arr[j+1]);
      }
    }
  }
}

int main() {
  int n;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);
  
  int arr[n];
  generateRandomNumbers(arr, n);
  
  printf("Original Array: ");
  printArray(arr, n);
  
  bubbleSort(arr, n);
  
  printf("Sorted Array: ");
  printArray(arr, n);
  
  return 0;
}