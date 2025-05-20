#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *log_buffer = malloc(1024);
  int log_size = 0;

  // Write out of bounds
  log_buffer[log_size] = 'a';
  log_size++;

  printf("Log buffer: %s\n", log_buffer);

  free(log_buffer);
  return 0;
}
