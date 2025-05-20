#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *a = NULL;
  a = malloc(10);
  *a = 5;
  free(a);
  printf("%d", *a);
  return 0;
}
