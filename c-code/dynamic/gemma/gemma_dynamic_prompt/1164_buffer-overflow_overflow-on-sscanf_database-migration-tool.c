#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char buffer[10];
  char input[1024];

  printf("Enter a command: ");
  scanf("%s", input);

  // Buffer overflow on sscanf
  sscanf(input, "%s", buffer);

  printf("Command: %s\n", buffer);

  return 0;
}
