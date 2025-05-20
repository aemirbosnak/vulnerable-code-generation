#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *buf = NULL;
  size_t size = 0;

  while (1) {
    // Allocate memory for the buffer
    buf = malloc(size);

    // Read data from the user
    printf("Enter text: ");
    getline(&buf, &size, stdin);

    // Free the memory allocated for the buffer
    free(buf);

    // Increment the size of the buffer
    size++;

    // Repeat the process until the user enters an empty line
    if (strcmp(buf, "") == 0) {
      break;
    }
  }

  return 0;
}
