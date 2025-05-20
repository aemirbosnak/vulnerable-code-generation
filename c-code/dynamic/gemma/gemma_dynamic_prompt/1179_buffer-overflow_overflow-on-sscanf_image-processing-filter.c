#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char buffer[1024];
  scanf("%s", buffer);
  buffer[1024 - 1] = 'a';
  printf("%s", buffer);
  return 0;
}
