#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char buffer[10] = "Hello, world!";
  int index = 12;

  // Out-of-bounds read
  printf("%c", buffer[index]);

  return 0;
}
