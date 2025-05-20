//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void print_array(int *array, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubble_sort(int *array, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        swap(&array[j], &array[j + 1]);
      }
    }
  }
}

int main() {
  int array[MAX_SIZE];
  int size;

  printf("Enter the size of the array: ");
  scanf("%d", &size);

  printf("Enter the elements of the array: ");
  for (int i = 0; i < size; i++) {
    scanf("%d", &array[i]);
  }

  printf("Unsorted array: ");
  print_array(array, size);

  bubble_sort(array, size);

  printf("Sorted array: ");
  print_array(array, size);

  return 0;
}