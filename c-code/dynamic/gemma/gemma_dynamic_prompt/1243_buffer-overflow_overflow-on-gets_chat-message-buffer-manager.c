#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
  char buffer[1024];
  int index = 0;
  int message_size = 0;

  // Get the message
  printf("Enter your message: ");
  gets(buffer);

  // Store the message in the buffer
  message_size = strlen(buffer) + 1;
  if (message_size > 1024)
  {
    printf("Error: Message too long.\n");
  }
  else
  {
    memcpy(buffer + index, buffer, message_size);
    index += message_size;
  }

  // Print the stored message
  printf("Your message: %s\n", buffer);

  return 0;
}
