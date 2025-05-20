#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char buffer[20];
  scanf("%s", buffer);

  if (strlen(buffer) > 16)
  {
    printf("Error: buffer overflow\n");
  }
  else
  {
    printf("Success: buffer data is %s\n", buffer);
  }

  return 0;
}
