#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *buffer = NULL;
  int size = 0;
  char ch;

  printf("Enter text: ");

  // Loop until the user enters a newline character or Ctrl+D
  while ((ch = getchar()) != '\n' && ch != 4) {
    if (size == 0) {
      buffer = malloc(size);
    } else {
      buffer = realloc(buffer, size * 2);
    }

    buffer[size++] = ch;
  }

  printf("Your text: %s", buffer);

  free(buffer);

  return 0;
}
