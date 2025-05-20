#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char buffer[1024];
  gets(buffer);
  buffer[1023] = 'A';
  printf("%s", buffer);
  return 0;
}
