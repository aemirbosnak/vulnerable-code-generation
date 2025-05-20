#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
  char buffer[1024];
  printf("Enter data: ");
  scanf("%s", buffer);

  // Overflow on scanf
  buffer[1024 - 1] = '\0';

  printf("Data stored: %s", buffer);

  return 0;
}
