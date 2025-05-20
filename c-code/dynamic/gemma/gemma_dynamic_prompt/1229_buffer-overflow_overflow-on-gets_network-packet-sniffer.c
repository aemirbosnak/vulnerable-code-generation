#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buf[1024];
  gets(buf);

  // Overflow the buffer to trigger the vulnerability
  buf[1024 - 1] = '\x0a';

  printf("Data received: %s", buf);

  return 0;
}
