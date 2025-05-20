#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

int main() {
  int *ptr1 = NULL, *ptr2 = NULL, *ptr3 = NULL;

  // Allocate memory for ptr1 and ptr2
  ptr1 = (int *)malloc(10 * sizeof(int));
  if (ptr1 == NULL) {
    return 1;
  }
  ptr2 = (int *)realloc(ptr1, 20 * sizeof(int));
  if (ptr2 == NULL) {
    return 1;
  }

  // Fill ptr1 and ptr2 with data
  for (int i = 0; i < 10; i++) {
    ptr1[i] = i + 1;
  }

  // Free part of ptr2 and attempt to access and print remaining data
  free(ptr1);
  ptr1 = (int *)realloc(ptr2, 10 * sizeof(int));
  if (ptr1 == NULL) {
    return 1;
  }
  for (int i = 0; i < 10; i++) {
    printf("%d ", ptr1[i]);
  }

  // Free remaining memory and return
  free(ptr1);
  return 0;
}
