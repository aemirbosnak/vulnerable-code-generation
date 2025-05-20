#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int file_size = 1000000000; // 1GB file size
  int buffer_size = file_size * 2;

  // Allocate memory for the buffer
  int* buffer = malloc(buffer_size);

  // Integer overflow: Multiply file size by 2 and store in buffer
  buffer[0] = file_size * 2;

  // Free the memory
  free(buffer);

  return 0;
}
