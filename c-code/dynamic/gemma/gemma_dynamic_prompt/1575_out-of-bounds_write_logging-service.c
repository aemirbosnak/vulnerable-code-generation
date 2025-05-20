#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char *log_buffer = malloc(1024);
  log_buffer[1023] = 'a'; // Out of bounds write

  printf("Log message: %s\n", log_buffer);

  free(log_buffer);
  return 0;
}
