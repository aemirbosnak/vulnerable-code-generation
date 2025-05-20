#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int *arr = malloc(10);
  arr[0] = 5;
  free(arr);
  printf("%d", arr[0]); // Use after free vulnerability
  return 0;
}
