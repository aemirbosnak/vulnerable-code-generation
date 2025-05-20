#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[1024];
  gets(buffer);
  buffer[1024 - 1] = 'a';
  printf("%s", buffer);
  return 0;
}
