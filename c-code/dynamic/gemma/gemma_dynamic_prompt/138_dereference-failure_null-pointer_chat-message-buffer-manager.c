#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char *message_buffer = NULL;
  int message_length = 0;

  // Allocate memory for the message buffer.
  message_buffer = malloc(1024);

  // Attempt to dereference the null pointer.
  *message_buffer = "Hello, world!";

  // Print the message.
  printf("%s", message_buffer);

  // Free the memory.
  free(message_buffer);

  return 0;
}
