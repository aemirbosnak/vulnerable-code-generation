#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int file_size = 0;
  FILE *file = fopen("test.txt", "w");

  // Malicious integer overflow
  file_size = 2147483647; // This value will cause an integer overflow

  // Write data to the file
  fwrite(file_size, sizeof(int), 1, file);

  fclose(file);

  return 0;
}
