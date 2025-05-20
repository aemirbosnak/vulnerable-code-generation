#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char **arr = NULL;
  int i = 0;

  arr = malloc(10 * sizeof(char *));
  for (i = 0; i < 10; i++) {
    arr[i] = malloc(10 * sizeof(char));
  }

  arr[i][0] = 'H';
  printf("%c", arr[i][0]);

  for (i = 0; i < 10; i++) {
    free(arr[i]);
  }
  free(arr);

  return 0;
}
