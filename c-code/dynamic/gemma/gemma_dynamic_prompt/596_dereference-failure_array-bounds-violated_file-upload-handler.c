#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *fp;
  char *buf;
  int i;

  fp = fopen("test.txt", "w");
  buf = malloc(1024);

  for (i = 0; i < 1024; i++)
  {
    buf[i] = 'a';
  }

  fwrite(buf, 1, 1024, fp);
  fclose(fp);

  return 0;
}
