#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  int *ptr = NULL;
  *ptr = 10;
  free(ptr);
  return 0;
}
