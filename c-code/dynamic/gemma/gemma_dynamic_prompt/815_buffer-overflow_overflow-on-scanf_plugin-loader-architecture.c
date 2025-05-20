#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void main() {
  char buffer[1024];
  scanf("%s", buffer);
  buffer[1023] = 'A';
  printf("%s", buffer);
}
