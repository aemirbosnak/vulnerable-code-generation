#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *fp = fopen("test.txt", "w");
  fclose(fp);

  free(fp); // Use after free vulnerability

  return 0;
}
