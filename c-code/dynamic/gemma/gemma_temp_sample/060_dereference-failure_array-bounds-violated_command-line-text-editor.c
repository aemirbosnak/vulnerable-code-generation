#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char **arr = NULL;
  arr = (char**)malloc(10 * sizeof(char*));
  arr[0] = "Hello, world!";

  // Array bounds violation - attempt to access an element beyond the bounds of the array
  arr[10] = "This is a dereference failure!";

  printf("%s\n", arr[0]);
  printf("%s\n", arr[10]);

  free(arr);
  return 0;
}
