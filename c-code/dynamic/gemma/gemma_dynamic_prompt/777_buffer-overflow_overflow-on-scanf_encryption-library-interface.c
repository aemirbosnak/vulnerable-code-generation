#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buf[16];
  scanf("%s", buf);
  buf[15] = 'A';
  printf("%s", buf);
  return 0;
}
