#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[1024];
  scanf("%s", buffer);

  // Overflow the buffer
  buffer[1024 - 1] = 'A';

  printf("The buffer overflowed!\n");
  printf("The captured data is: %s\n", buffer);

  return 0;
}
