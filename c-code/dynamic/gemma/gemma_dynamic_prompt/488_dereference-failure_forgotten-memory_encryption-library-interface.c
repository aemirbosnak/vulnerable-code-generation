#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void encrypt(void) {
  int *ptr = NULL;
  *ptr = 42;
  printf("%d", *ptr);
}

int main() {
  encrypt();
  return 0;
}
