#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  char *url = NULL;
  char *host = NULL;
  char *path = NULL;
  char *query_string = NULL;

  // Parse the HTTP request line
  char *line = "GET /foo?bar=baz HTTP/1.1";
  char *p = line;

  // Extract the host
  host = strchr(p, '/');
  if (host) {
    *host = '\0';
  }

  // Extract the path
  path = strchr(host, '/');
  if (path) {
    *path = '\0';
  }

  // Extract the query string
  query_string = strchr(path, '?');
  if (query_string) {
    *query_string = '\0';
  }

  // Print the parsed values
  printf("Host: %s\n", host);
  printf("Path: %s\n", path);
  printf("Query string: %s\n", query_string);

  return 0;
}
