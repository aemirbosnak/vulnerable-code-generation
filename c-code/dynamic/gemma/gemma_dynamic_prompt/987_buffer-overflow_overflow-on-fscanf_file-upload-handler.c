#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char buffer[1024];

  printf("Enter file contents: ");
  scanf("%s", buffer);

  // Deliberate buffer overflow
  buffer[1024 - 1] = 'a';

  printf("File contents: %s", buffer);

  return 0;
}
