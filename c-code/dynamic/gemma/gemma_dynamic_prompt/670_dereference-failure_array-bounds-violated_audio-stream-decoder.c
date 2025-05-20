#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int buffer[10];
  buffer[20] = 42;
  printf("%d", buffer[20]);
  return 0;
}
