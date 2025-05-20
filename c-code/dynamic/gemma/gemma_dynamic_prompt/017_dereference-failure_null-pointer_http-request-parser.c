#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char *url = NULL;
  url = malloc(10);
  *url = 'a';
  printf("%s", url);
  free(url);
  return 0;
}
