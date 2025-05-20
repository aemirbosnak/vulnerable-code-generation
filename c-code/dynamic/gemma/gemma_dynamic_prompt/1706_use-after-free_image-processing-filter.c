#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int *arr = NULL;
  arr = malloc(10 * sizeof(int));
  free(arr);
  arr[0] = 10; // Use after free vulnerability
  printf("%d", arr[0]);
  return 0;
}
