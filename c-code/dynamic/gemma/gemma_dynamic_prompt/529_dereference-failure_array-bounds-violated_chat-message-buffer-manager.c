#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
  char buffer[10];
  int index = 10;

  printf("Enter a message: ");
  fgets(buffer, 10, stdin);

  // Overwrite the buffer limit and cause a dereference failure
  buffer[index] = '\0';

  printf("Your message: %s", buffer);

  return 0;
}
