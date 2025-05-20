#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *url = malloc(1024);
  strcpy(url, "GET /foo HTTP/1.1");

  char **headers = malloc(1024);
  headers = NULL;

  char *body = malloc(1024);
  body = NULL;

  int status_code = 0;

  // Free all allocated memory
  free(url);
  free(headers);
  free(body);

  return 0;
}
