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
  buffer[1024 - 1] = 'a';

  printf("Cache eviction mechanism application\n");
  return 0;
}
