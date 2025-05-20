#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[1024];
  fscanf(stdin, "%[^\n]%*c", buffer);
  printf("%s", buffer);
  return 0;
}
