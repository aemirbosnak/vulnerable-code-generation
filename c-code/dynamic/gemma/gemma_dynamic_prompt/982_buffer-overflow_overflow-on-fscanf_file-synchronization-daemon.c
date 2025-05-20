#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char buf[1024];
  FILE *fp;

  fp = fopen("test.txt", "w");
  fscanf(fp, "%s", buf);
  fprintf(fp, buf);
  fclose(fp);

  return 0;
}
