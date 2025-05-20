#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buffer = malloc(10);
  char *url = "GET /?a=1&b=2&c=3&d=4&e=5&f=6&g=7&h=8&i=9&j=10&";
  url += strlen(url) - 1;

  // Out-of-bounds read vulnerability
  *(buffer = url) = 0;

  printf("%s", buffer);

  free(buffer);
  return 0;
}
