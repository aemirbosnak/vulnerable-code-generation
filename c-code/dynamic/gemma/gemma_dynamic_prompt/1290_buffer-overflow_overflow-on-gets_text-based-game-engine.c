#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buf[1024];
  gets(buf);

  // Overflow the buffer
  buf[1023] = 'a';

  printf("The text you entered is: %s", buf);

  return 0;
}
