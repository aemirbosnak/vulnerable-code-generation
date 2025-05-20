#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  FILE *fp = NULL;
  char *buf = NULL;
  size_t size = 0;

  fp = fopen("test.txt", "w");
  if (fp == NULL)
  {
    return 1;
  }

  buf = malloc(size);
  if (buf == NULL)
  {
    fclose(fp);
    return 1;
  }

  size = fread(buf, 1, 1024, fp);
  if (size > 0)
  {
    fwrite(buf, 1, size, fp);
  }

  fclose(fp);
  free(buf);

  return 0;
}
