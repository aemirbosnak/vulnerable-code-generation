#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *fp = fopen("test.txt", "w");
  char *buf = malloc(10);
  fwrite(buf, 1, 10, fp);
  free(buf);
  fclose(fp);

  return 0;
}
