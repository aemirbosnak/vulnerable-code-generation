#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

int main() {
  int size = 0;
  int alloc_size = 0;
  int *arr = NULL;

  while (1) {
    printf("Enter the size of the block to allocate: ");
    scanf("%d", &size);

    if (size == 0) {
      break;
    }

    alloc_size += size;
    arr = realloc(arr, alloc_size * sizeof(int));

    arr[alloc_size - 1] = size;
  }

  printf("The total allocated size is: %d\n", alloc_size);

  return 0;
}
