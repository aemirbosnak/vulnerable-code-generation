#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char* buffer = "GET /foo HTTP/1.1\r\n\r\n";
  int index = 0;
  int size = strlen(buffer);

  for (index = 0; index < size; index++) {
    if (buffer[index] == '\r' && buffer[index-1] == '\n') {
      printf("Header: %s\n", buffer + index - 2);
    }
  }

  return 0;
}
