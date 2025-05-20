#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

char buffer[1024];

int main() {
  fgets(buffer, 1024, stdin);
  return 0;
}
