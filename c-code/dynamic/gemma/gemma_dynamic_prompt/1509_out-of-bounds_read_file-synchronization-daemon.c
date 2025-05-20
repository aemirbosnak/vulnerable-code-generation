#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE* file = fopen("file.txt", "r");
  if (file == NULL)
  {
    perror("Error opening file");
    return 1;
  }

  // Out of bounds read
  char buffer[10];
  int read_size = fread(buffer, 1, 11, file);
  if (read_size > 10)
  {
    printf("Read more than the buffer size!\n");
  }

  fclose(file);
  return 0;
}
