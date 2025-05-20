//FormAI DATASET v1.0 Category: Memory management ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  printf("Enter number of integers to be allocated: ");
  scanf("%d", &n);

  // allocate memory dynamically using malloc
  int *ptr = (int *)malloc(n * sizeof(int));
  if (ptr == NULL) {
    printf("Memory allocation failed\n");
    return 1;
  }

  printf("Enter %d integers: ", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &ptr[i]);
  }

  printf("The integers you entered are: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", ptr[i]);
  }
  printf("\n");

  // reallocate memory dynamically using realloc
  int newSize;
  printf("Enter new size for the array: ");
  scanf("%d", &newSize);
  ptr = (int *)realloc(ptr, newSize * sizeof(int));
  if (ptr == NULL) {
    printf("Memory reallocation failed\n");
    return 1;
  }

  printf("Enter %d new integers: ", newSize);
  for (int i = n; i < newSize; i++) {
    scanf("%d", &ptr[i]);
  }

  printf("The integers you entered are: ");
  for (int i = 0; i < newSize; i++) {
    printf("%d ", ptr[i]);
  }
  printf("\n");

  // free dynamically allocated memory
  free(ptr);
  return 0;
}