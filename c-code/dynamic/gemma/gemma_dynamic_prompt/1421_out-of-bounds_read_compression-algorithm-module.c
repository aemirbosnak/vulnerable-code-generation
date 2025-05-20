#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *fp = fopen("test.txt", "r");
  long pos = 0;
  char buffer[1024];

  while (!feof(fp))
  {
    int read_size = fread(buffer, 1, 1024, fp);
    buffer[read_size - 1] = '\0';

    printf("%s", buffer);
    pos += read_size;
  }

  fclose(fp);

  return 0;
}
