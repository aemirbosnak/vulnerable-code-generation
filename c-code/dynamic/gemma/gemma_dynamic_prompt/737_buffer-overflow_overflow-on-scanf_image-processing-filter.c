#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char buffer[1024];
  scanf("%s", buffer);

  // Overflow the buffer
  buffer[1023] = 'a';

  printf("%s", buffer);

  return 0;
}
