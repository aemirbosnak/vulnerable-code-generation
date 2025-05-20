#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int file_size = 0;
  FILE *fp = NULL;

  // Maliciously large file size
  file_size = 2147483647;

  fp = fopen("test.txt", "w");
  if (fp == NULL)
  {
    perror("Error opening file");
    return 1;
  }

  fprintf(fp, "This is a large file with a deliberately overflowed integer.");
  fclose(fp);

  return 0;
}
