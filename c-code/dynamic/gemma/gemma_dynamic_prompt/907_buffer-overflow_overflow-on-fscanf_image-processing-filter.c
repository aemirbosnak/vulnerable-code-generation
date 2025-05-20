#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main()
{
  char buf[10] = "Hello, world!";
  scanf("%s", buf);
  printf("%s", buf);
  return 0;
}
