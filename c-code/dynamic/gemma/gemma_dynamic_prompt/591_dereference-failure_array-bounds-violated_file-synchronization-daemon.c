#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char **arr = NULL;
  arr = malloc(5 * sizeof(char *));
  for (int i = 0; i < 5; i++) {
    arr[i] = malloc(10 * sizeof(char));
  }

  arr[5][0] = 'a';

  free(arr);
  return 0;
}
