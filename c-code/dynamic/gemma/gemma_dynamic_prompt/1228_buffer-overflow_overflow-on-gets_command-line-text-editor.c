#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
  char buf[1024];
  int len = 0;

  while (1)
  {
    printf("Enter text: ");
    len = gets(buf);

    if (len > 1024)
    {
      printf("Error: buffer overflow.\n");
    }
    else
    {
      printf("Your text: %s\n", buf);
    }

    if (strcmp(buf, "quit") == 0)
    {
      break;
    }
  }

  return 0;
}
