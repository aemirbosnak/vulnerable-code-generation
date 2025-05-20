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

  if (strlen(input) > 10)
  {
    buffer[0] = input[0];
    buffer[1] = input[1];
    buffer[2] = input[2];
    buffer[3] = input[3];
    buffer[4] = input[4];
    buffer[5] = input[5];
    buffer[6] = input[6];
    buffer[7] = input[7];
    buffer[8] = input[8];
    buffer[9] = '\0';

    printf("Cache entry updated: %s\n", buffer);
  }
  else
  {
    printf("Error: insufficient input.\n");
  }

  return 0;
}
