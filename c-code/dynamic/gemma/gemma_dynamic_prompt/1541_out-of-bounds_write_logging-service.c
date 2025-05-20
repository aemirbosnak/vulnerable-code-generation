#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *log_buffer = NULL;
  int log_size = 0;

  // Allocate memory for the log buffer
  log_buffer = malloc(log_size);

  // Write out of bounds
  log_buffer[log_size - 1] = 'A';

  // Free the memory
  free(log_buffer);

  return 0;
}
