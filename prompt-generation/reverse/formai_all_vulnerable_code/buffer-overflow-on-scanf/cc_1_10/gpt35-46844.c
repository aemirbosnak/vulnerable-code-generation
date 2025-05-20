//FormAI DATASET v1.0 Category: Sorting ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void insertion_sort(int arr[], int n);
void selection_sort(int arr[], int n);
void bubble_sort(int arr[], int n);
void merge_sort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void quick_sort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void print_array(int arr[], int n);

int main() {
  int n, i, choice;
  // Take input from user for number of elements in array
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  // Take input from user for the elements of the array
  int arr[n];
  printf("Enter the elements of the array: ");
  for (i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }

  // Display the menu to the user
  printf("\nSorting Algorithms:\n1. Insertion Sort\n2. Selection Sort\n3. Bubble Sort\n4. Merge Sort\n5. Quick Sort\n");
  printf("Choose a sorting algorithm to use: ");
  scanf("%d", &choice);

  // Call the appropriate sorting function based on the user's choice
  switch (choice) {
    case 1:
      insertion_sort(arr, n);
      break;
    case 2:
      selection_sort(arr, n);
      break;
    case 3:
      bubble_sort(arr, n);
      break;
    case 4:
      merge_sort(arr, 0, n - 1);
      break;
    case 5:
      quick_sort(arr, 0, n - 1);
      break;
    default:
      printf("Invalid choice! Please choose between 1-5.\n");
      return 1;
  }

  // Display the sorted array to the user
  printf("\nThe sorted array is:\n");
  print_array(arr, n);

  return 0;
}

// Function to perform insertion sort on an array
void insertion_sort(int arr[], int n) {
  int i, j, temp;
  for (i = 1; i < n; ++i) {
    temp = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > temp) {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = temp;
  }
}

// Function to perform selection sort on an array
void selection_sort(int arr[], int n) {
  int i, j, min, temp;
  for (i = 0; i < n - 1; ++i) {
    min = i;
    for (j = i + 1; j < n; ++j) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
  }
}

// Function to perform bubble sort on an array
void bubble_sort(int arr[], int n) {
  int i, j, temp;
  for (i = 0; i < n - 1; ++i) {
    for (j = 0; j < n - i - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

// Function to perform merge sort on an array
void merge_sort(int arr[], int l, int r) {
  if (l < r) {
    int m = (l + r) / 2;
    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

void merge(int arr[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  // Create temporary arrays
  int L[n1], R[n2];

  // Copy data to temporary arrays
  for (i = 0; i < n1; ++i) {
    L[i] = arr[l + i];
  }
  for (j = 0; j < n2; ++j) {
    R[j] = arr[m + 1 + j];
  }

  // Merge the temporary arrays back into arr[l..r]
  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      ++i;
    }
    else {
      arr[k] = R[j];
      ++j;
    }
    ++k;
  }

  // Copy the remaining elements of L[], if there are any
  while (i < n1) {
    arr[k] = L[i];
    ++i;
    ++k;
  }

  // Copy the remaining elements of R[], if there are any
  while (j < n2) {
    arr[k] = R[j];
    ++j;
    ++k;
  }
}

// Function to perform quick sort on an array
void quick_sort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quick_sort(arr, low, pi - 1);
    quick_sort(arr, pi + 1, high);
  }
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1, j, temp;
  for (j = low; j < high; ++j) {
    if (arr[j] < pivot) {
      ++i;
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp;
  return i + 1;
}

// Function to print the elements of an array
void print_array(int arr[], int n) {
  int i;
  for (i = 0; i < n; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}