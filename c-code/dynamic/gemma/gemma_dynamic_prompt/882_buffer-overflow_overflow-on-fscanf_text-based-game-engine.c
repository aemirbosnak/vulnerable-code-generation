#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main()
{
  char buffer[10];
  scanf("%s", buffer);

  printf("You entered: %s", buffer);

  return 0;
}
