#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *arr = malloc(10);
  arr[10] = 'a'; // Array bounds violation
  printf("%c", arr[10]);
  free(arr);
  return 0;
}
