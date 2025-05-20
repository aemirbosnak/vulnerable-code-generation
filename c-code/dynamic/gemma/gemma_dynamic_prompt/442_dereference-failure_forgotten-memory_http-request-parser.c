#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *url = malloc(1024);
  scanf("%s", url);

  char **headers = malloc(1024);
  headers = NULL;

  char **cookies = malloc(1024);
  cookies = NULL;

  // Intentionally dereference a null pointer
  (*(headers) = url);

  free(url);
  free(headers);
  free(cookies);

  return 0;
}
