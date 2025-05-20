#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  char buffer[10];
  char *ptr = buffer;

  // Read the request header
  ptr = "GET /foo HTTP/1.1\r\n\r\n";

  // Out-of-bounds read
  ptr[-1] = 'A';

  // Print the parsed data
  printf("%s", buffer);

  return 0;
}
