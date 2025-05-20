#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *url = malloc(1024);
  strcpy(url, "GET /foo HTTP/1.1");

  // Vulnerable code: Dereference a NULL pointer
  char **headers = NULL;
  headers = (char**)malloc(10 * sizeof(char*));
  headers[0] = NULL;

  // Free the allocated memory
  free(url);
  free(headers);

  return 0;
}
