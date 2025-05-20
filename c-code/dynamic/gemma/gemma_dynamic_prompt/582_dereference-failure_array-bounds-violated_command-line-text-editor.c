#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char **arr = NULL;
  arr = (char**)malloc(10 * sizeof(char *));
  for (int i = 0; i < 10; i++) {
    arr[i] = (char *)malloc(20 * sizeof(char));
  }

  char *ptr = arr[5][10];
  *ptr = 'a';

  free(arr);
  return 0;
}
