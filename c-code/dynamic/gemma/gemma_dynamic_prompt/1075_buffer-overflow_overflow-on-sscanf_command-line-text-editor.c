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

  printf("Enter text: ");
  scanf("%s", buf);

  len = strlen(buf);

  if (len > 1024)
  {
    printf("Error: Text exceeds buffer size.\n");
  }
  else
  {
    printf("Your text: %s\n", buf);
  }

  return 0;
}
