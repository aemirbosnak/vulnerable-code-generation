#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
  char buffer[10];
  char message[1024];

  printf("Enter a message: ");
  scanf("%s", message);

  // Overflow the buffer
  sprintf(buffer, "The message is: %s", message);

  printf("Your message: %s\n", buffer);

  return 0;
}
