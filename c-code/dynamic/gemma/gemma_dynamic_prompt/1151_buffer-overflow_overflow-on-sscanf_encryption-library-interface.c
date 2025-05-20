#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

char buffer[1024];

int main() {
  scanf("%s", buffer);

  printf("The input is: %s", buffer);

  return 0;
}
