#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char buffer[10];
  scanf("%s", buffer);

  // Overflow on the buffer size
  sprintf(buffer, "This string is too long for the buffer, but I'm writing it anyway!");

  printf("The modified string is: %s", buffer);

  return 0;
}
