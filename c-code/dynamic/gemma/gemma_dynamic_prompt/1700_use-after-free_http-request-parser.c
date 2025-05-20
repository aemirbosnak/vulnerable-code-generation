#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buffer = NULL;
  int size = 0;

  // Allocate memory for the buffer
  buffer = malloc(1024);

  // Get the HTTP request header
  char *header = "GET /index.html HTTP/1.1";

  // Parse the header and extract the payload
  char *payload = strstr(header, "Payload:");
  payload = payload + 9;

  // Free the memory allocated for the buffer
  free(buffer);

  // Use the freed memory
  printf("%s", buffer);

  return 0;
}
