#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *fp = fopen("file.txt", "w");
  int *ptr = NULL;
  fprintf(fp, "Hello, world!");
  *ptr = 10;
  fclose(fp);
  return 0;
}
