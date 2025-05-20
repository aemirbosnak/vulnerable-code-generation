#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
  char buffer[1024];
  char *ptr = buffer;

  printf("Enter HTTP request: ");
  scanf("%s", ptr);

  if (ptr - buffer >= 1024)
  {
    printf("Error: Buffer overflow.\n");
  }
  else
  {
    printf("Request received: %s\n", buffer);
  }

  return 0;
}
