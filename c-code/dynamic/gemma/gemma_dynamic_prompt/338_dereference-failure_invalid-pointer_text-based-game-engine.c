#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int *ptr = NULL;
  int value = 10;

  *ptr = &value;

  printf("The value is: %d", *ptr);

  return 0;
}
