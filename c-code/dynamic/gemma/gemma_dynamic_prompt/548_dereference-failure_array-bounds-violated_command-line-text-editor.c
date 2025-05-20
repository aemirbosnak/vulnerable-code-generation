#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char **arr = NULL;
  arr = (char**)malloc(10 * sizeof(char*));
  for (int i = 0; i < 10; i++) {
    arr[i] = (char*)malloc(10 * sizeof(char));
  }

  // Deliberate array bounds violation
  arr[10][0] = 'a';

  free(arr);
  return 0;
}
