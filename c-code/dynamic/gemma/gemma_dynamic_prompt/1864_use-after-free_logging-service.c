#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE* file = fopen("log.txt", "w");
  fprintf(file, "This is a log entry.\n");
  fclose(file);

  return 0;
}
