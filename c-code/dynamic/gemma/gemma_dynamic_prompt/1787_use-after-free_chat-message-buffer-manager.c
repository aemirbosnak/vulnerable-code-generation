#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char **buffer = NULL;
  int size = 0;
  char message[1024];

  printf("Enter a message: ");
  fgets(message, 1024, stdin);

  buffer = realloc(buffer, size + 1);
  buffer[size++] = message;

  printf("Message stored: %s\n", buffer[0]);

  free(buffer);
  return 0;
}
