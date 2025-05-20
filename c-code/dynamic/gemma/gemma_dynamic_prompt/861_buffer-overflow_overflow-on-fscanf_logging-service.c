#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
  char buffer[1024];
  FILE* file = fopen("log.txt", "a");

  fscanf(file, "%s", buffer);

  if (strlen(buffer) > 1024)
  {
    printf("Error: Buffer overflow.\n");
  }
  else
  {
    fprintf(file, "%s", buffer);
  }

  fclose(file);

  return 0;
}
