#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
  char buffer[1024];
  int i = 0;

  printf("Enter text: ");

  // Overflow the buffer
  while (scanf("%s", buffer) != EOF)
  {
    i++;
    printf("Enter more text (optional): ");
    buffer[i] = '\0';
  }

  printf("Your text: %s", buffer);

  return 0;
}
