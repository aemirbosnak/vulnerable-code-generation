#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main()
{
  char buffer[10];

  printf("Enter a message: ");
  scanf("%s", buffer);

  // Buffer overflow!
  scanf("%s", buffer);

  printf("Your message: %s\n", buffer);

  return 0;
}
