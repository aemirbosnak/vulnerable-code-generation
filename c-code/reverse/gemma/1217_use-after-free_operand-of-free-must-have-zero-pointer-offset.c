#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

void *my_malloc(size_t size) {
  // Allocate memory block
  void *ptr = malloc(size);

  // If allocation fails, return NULL
  if (ptr == NULL) {
    return NULL;
  }

  // Return the allocated memory block
  return ptr;
}

void my_free(void *ptr) {
  // Free the memory block
  free(ptr);
}

int main() {
  // Allocate and free memory blocks repeatedly, reaching the boundary of the allocated memory
  for (int i = 0; i < 100000; i++) {
    my_malloc(1);
    my_free(my_malloc(1));
  }

  // Allocate a large block of memory, exceeding the available memory
  void *large_block = my_malloc(1000000);

  // Free the large block, but the memory is not actually freed
  my_free(large_block);

  return 0;
}
