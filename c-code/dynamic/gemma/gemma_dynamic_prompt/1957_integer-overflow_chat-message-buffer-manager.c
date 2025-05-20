#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  int i = 0;
  char buffer[1024];

  // Overflow the buffer
  for (i = 0; i < 1024 * 2; i++) {
    buffer[i] = 'a';
  }

  // Print the result
  printf("The buffer is full.\n");

  return 0;
}
