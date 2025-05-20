#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char *buffer = malloc(10);
  char *payload = "This is a large payload that will cause an out-of-bounds write";
  int payload_length = strlen(payload);

  // Write beyond the bounds of the buffer
  buffer[payload_length] = '\0';
  strcpy(buffer, payload);

  printf("The modified buffer is: %s", buffer);

  free(buffer);
  return 0;
}
