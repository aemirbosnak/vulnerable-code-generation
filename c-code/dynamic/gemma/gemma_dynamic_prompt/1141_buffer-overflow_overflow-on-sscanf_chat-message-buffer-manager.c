#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

char buffer[1024];

int main()
{
  char message[2048];

  printf("Enter a message: ");
  scanf("%s", message);

  strcpy(buffer, message);

  printf("Your message: %s", buffer);

  return 0;
}
