#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char **arr = NULL;
  *arr = malloc(10);
  *(*arr) = "Hello, world!";
  free(arr);
  printf("%s\n", *arr);
  return 0;
}
