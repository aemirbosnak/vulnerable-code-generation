//FormAI DATASET v1.0 Category: Memory management ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main() {
  int size;
  printf("Enter the size of array: ");
  scanf("%d", &size);
  
  int* arr = (int*) malloc(size * sizeof(int));
  
  if (arr == NULL) {
    printf("Memory allocation failed\n");
    return 0;
  }
  
  printf("Memory allocated successfully\n");
  
  for (int i = 0; i < size; i++) {
    printf("Enter element %d: ", i+1);
    scanf("%d", &arr[i]);
  }
  
  printf("Array elements: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  
  printf("\n");
  
  int newSize;
  printf("Enter the new size of array: ");
  scanf("%d", &newSize);
  
  int* newArr = realloc(arr, newSize * sizeof(int));
  
  if (newArr == NULL) {
    printf("Memory reallocation failed\n");
    return 0;
  }
  
  printf("Memory reallocated successfully\n");
  
  for (int i = size; i < newSize; i++) {
    printf("Enter element %d: ", i+1);
    scanf("%d", &newArr[i]);
  }
  
  printf("Array elements: ");
  for (int i = 0; i < newSize; i++) {
    printf("%d ", newArr[i]);
  }
  
  printf("\n");
  
  free(newArr);
  
  return 0;
}