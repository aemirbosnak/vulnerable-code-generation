#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
  char buffer[1024];

  printf("Enter a message: ");
  scanf("%s", buffer);

  if (strlen(buffer) > 1024)
  {
    printf("Error: Message too long.\n");
  }
  else
  {
    printf("Message received: %s\n", buffer);
  }

  return 0;
}
