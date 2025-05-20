#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
  char buffer[1024];
  int size = 0;

  printf("Enter file data: ");
  scanf("%s", buffer);

  size = strlen(buffer) + 1;

  if (size > 1024)
  {
    printf("Error: File data too large.\n");
  }
  else
  {
    printf("File data received: %s\n", buffer);
  }

  return 0;
}
