#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char* buffer = malloc(1024);
  char* url = "GET /?foo=bar&baz=qux&param[0]=value&param[1]=another value";
  int i = 0;

  printf("Parsing URL: %s\n", url);

  // Allocate memory for the query string
  char* query = strchr(url, '?') + 1;

  // Loop over the query parameters
  while (query[i] != '\0') {
    char* name = malloc(256);
    char* value = malloc(256);

    // Extract the parameter name and value
    name = strchr(query, '=') + 1;
    value = strchr(name, '&') ? strchr(name, '&') - name : NULL;

    // Print the parameter name and value
    printf("Parameter: %s, Value: %s\n", name, value);

    // Free the memory allocated for name and value
    free(name);
    free(value);

    i++;
  }

  free(buffer);
  return 0;
}
