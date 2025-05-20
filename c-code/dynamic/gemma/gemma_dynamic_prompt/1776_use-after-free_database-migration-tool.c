#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

int main() {
  int *arr = NULL;
  arr = malloc(10);
  free(arr);
  arr[0] = 10; // Use after free vulnerability
  printf("%d", arr[0]);
  return 0;
}
