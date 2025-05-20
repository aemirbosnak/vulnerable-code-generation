#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
  char buffer[10];
  char input[100];

  printf("Enter a message: ");
  scanf("%s", input);

  // Overflow the buffer
  strcpy(buffer, input);

  printf("Your message is: %s", buffer);

  return 0;
}
