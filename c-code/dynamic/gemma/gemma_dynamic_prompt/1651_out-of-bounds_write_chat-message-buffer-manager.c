#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char buffer[1024];
  int index = 0;

  while (1)
  {
    char message[1024];

    printf("Enter message: ");
    fgets(message, 1024, stdin);

    if (index + strlen(message) >= 1024)
    {
      printf("Error: buffer overflow.\n");
    }
    else
    {
      memcpy(buffer + index, message, strlen(message));
      index += strlen(message);
      printf("Message stored.\n");
    }
  }
}
