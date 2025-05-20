#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char *filename = malloc(10);
  filename = NULL;
  FILE *fp = fopen("test.txt", "w");
  fprintf(fp, "Hello, world!");
  fclose(fp);
  return 0;
}
