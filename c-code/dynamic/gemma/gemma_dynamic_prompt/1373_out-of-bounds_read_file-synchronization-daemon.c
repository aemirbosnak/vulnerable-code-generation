#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  FILE* file = fopen("file.txt", "r");
  char* data = NULL;
  long offset = 1000000;

  if (file)
  {
    data = (char*)malloc(1024);
    if (data)
    {
      fseek(file, offset, SEEK_SET);
      fread(data, 1024, 1, file);
    }
  }

  if (data)
  {
    printf("%s", data);
  }

  fclose(file);
  free(data);

  return 0;
}
