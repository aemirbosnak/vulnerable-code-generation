#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char **arr = NULL;
  arr = (char **)malloc(10 * sizeof(char *));
  arr[0] = "Hello";
  arr[1] = "World";
  arr[2] = NULL;

  printf("%s", arr[3]);
  free(arr);
  return 0;
}
