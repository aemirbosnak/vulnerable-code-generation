#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char buffer[1024];
  FILE *fp;

  fp = fopen("test.txt", "r");
  fscanf(fp, "%s", buffer);
  fclose(fp);

  printf("%s", buffer);

  return 0;
}
