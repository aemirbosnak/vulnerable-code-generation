#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

int main() {
  int *ptr = NULL;
  *ptr = 10;
  printf("%d", *ptr);
  return 0;
}
