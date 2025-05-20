#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char buffer[10] = "";
  gets(buffer);

  // Overflow the buffer
  int i = 0;
  while (buffer[i] != '\0') {
    buffer[i] = 'a';
    i++;
  }

  buffer[i] = '\0';

  printf("The modified buffer is: %s", buffer);

  return 0;
}
