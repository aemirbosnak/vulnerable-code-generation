#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char *url = NULL;
  url = malloc(10);
  url[0] = 'a';
  url[1] = 'b';
  url[2] = '\0';

  char *path = url + 10;
  printf("%s", path);

  free(url);
  return 0;
}
