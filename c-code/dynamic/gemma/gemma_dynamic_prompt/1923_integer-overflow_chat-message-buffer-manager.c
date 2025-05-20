#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int message_size = 1000000000;
  char *message_buffer = (char *)malloc(message_size);

  message_buffer[0] = 'H';
  message_buffer[1] = 'E';
  message_buffer[2] = 'L';
  message_buffer[3] = 'O';

  printf("%s", message_buffer);

  free(message_buffer);

  return 0;
}
