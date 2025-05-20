#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[1024] = "Hello, world!";
  int index = 1024;

  // Out-of-bounds read
  printf("%c", buffer[index]);

  return 0;
}
