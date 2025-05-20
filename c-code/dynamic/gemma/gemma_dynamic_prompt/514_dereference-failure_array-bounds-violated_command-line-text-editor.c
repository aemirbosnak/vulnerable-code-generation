#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char **arr = NULL;
  int i = 0;

  arr = malloc(5 * sizeof(char *));
  for (i = 0; i < 5; i++) {
    arr[i] = malloc(10 * sizeof(char));
  }

  arr[i][0] = 'a';
  printf("%c", arr[i][0]);

  free(arr);

  return 0;
}
