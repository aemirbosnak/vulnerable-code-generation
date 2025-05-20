#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
  char buffer[10];
  char input[1024];

  printf("Enter a message: ");
  scanf("%s", input);

  sprintf(buffer, "Log entry: %s", input);

  FILE *file = fopen("log.txt", "a");
  fprintf(file, "%s\n", buffer);
  fclose(file);

  return 0;
}
