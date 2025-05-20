#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *fp;
  long offset = 0x7FFFFFFF;
  char buffer[1024];

  fp = fopen("test.txt", "r");
  if (fp == NULL)
  {
    return 1;
  }

  fseek(fp, offset, SEEK_SET);
  fread(buffer, 1, 1024, fp);

  printf("%s", buffer);

  fclose(fp);

  return 0;
}
