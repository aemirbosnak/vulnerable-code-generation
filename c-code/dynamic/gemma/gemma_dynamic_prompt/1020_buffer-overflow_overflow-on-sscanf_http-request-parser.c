#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[1024];
  char *ptr = buffer;

  printf("Enter an HTTP request: ");
  scanf("%s", buffer);

  // Overflow the buffer with a long string
  sprintf(ptr, "GET /foo/bar?query=%s&junk=AAAA", buffer);

  // Print the modified request
  printf("Modified request: %s\n", ptr);

  return 0;
}
