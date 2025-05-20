#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char* buffer = "GET /foo HTTP/1.1\r\n\r\n";
  size_t size = strlen(buffer) + 1;
  buffer = realloc(buffer, size);
  buffer[size - 1] = '\0';

  printf("%s", buffer);
  free(buffer);

  return 0;
}
