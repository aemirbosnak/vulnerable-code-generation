#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
  char message[1024];
  int len = 0;

  printf("Enter your message: ");
  scanf("%s", message);

  len = strlen(message) + 1;
  if (len > 1024)
  {
    printf("Error: Message too long.\n");
  }
  else
  {
    printf("Message received: %s\n", message);
  }

  return 0;
}
