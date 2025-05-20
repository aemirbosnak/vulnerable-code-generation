#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

char buffer[10];

int main() {
  gets(buffer);

  // Overflow the buffer
  for (int i = 0; i < 100; i++) {
    buffer[i] = 'a';
  }

  return 0;
}
