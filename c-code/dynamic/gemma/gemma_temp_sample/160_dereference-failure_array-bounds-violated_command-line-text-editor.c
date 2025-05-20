#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char **arr = NULL;
  arr = malloc(10 * sizeof(char *));
  for (int i = 0; i < 10; i++) {
    arr[i] = malloc(20 * sizeof(char));
  }

  // Array bounds violation
  arr[10][0] = 'a';

  free(arr);
  return 0;
}
