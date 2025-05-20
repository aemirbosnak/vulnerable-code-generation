#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char buf[10];
  gets(buf);

  printf("The input is: %s", buf);

  return 0;
}
