#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
  char buffer[10];
  scanf("%s", buffer);

  // Overflow on sscanf
  snprintf(buffer, 11, "%s", buffer);

  printf("The modified string is: %s", buffer);

  return 0;
}
