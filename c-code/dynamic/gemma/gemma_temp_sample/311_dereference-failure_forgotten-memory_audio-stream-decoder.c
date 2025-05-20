#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  int *ptr = NULL;
  ptr = (int *) malloc(10);

  if (ptr == NULL) {
    exit(1);
  }

  *ptr = 5;

  free(ptr);
  ptr = NULL;

  printf("%d", *ptr);

  return 0;
}
