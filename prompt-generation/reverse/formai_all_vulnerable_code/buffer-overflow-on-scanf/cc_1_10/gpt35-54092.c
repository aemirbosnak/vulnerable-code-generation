//FormAI DATASET v1.0 Category: Memory management ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

void allocate_memory(int **ptr, int size)
{
  *ptr = (int *) malloc(size * sizeof(int));

  if (*ptr == NULL) {
    printf("Failed to allocate memory.\n");
    exit(EXIT_FAILURE);
  }
}

void initialize_values(int *arr, int size)
{
  for (int i = 0; i < size; i++) {
    *(arr + i) = i + 1;  // Initialize values from 1 to size
  }
}

void print_values(int *arr, int size)
{
  printf("The array values are: ");

  for (int i = 0; i < size; i++) {
    printf("%d ", *(arr + i));
  }

  printf("\n");
}

void deallocate_memory(int **ptr)
{
  free(*ptr);
  *ptr = NULL;  // Reset the pointer to NULL after deallocation
}

int main()
{
  int *ptr = NULL;
  int size;

  printf("Enter the size of the array: ");
  scanf("%d", &size);

  allocate_memory(&ptr, size);
  initialize_values(ptr, size);
  print_values(ptr, size);
  deallocate_memory(&ptr);

  return 0;
}