#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char *url = "GET /foo HTTP/1.1";
  char **headers = NULL;
  char **body = NULL;

  // Parse the URL
  char *host = strchr(url, "/") + 1;
  char *path = strchr(host, "?") ? strchr(host, "?") : host;

  // Allocate memory for headers and body
  headers = malloc(1024);
  body = malloc(1024);

  // Free the memory
  free(headers);
  free(body);

  return 0;
}
