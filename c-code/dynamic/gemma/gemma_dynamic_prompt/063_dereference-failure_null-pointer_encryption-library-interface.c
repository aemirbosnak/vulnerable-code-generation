#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  void *ptr = NULL;
  int value = *(int *)ptr;
  printf("%d", value);
  return 0;
}
