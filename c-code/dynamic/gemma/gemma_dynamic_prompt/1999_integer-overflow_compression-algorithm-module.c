#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int n = 0x7fffffff;
  int m = n + 1;
  printf("%d", m);
  return 0;
}
