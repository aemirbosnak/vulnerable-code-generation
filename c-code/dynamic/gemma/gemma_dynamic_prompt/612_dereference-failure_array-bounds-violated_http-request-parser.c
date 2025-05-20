#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buf[10] = "hello";
  int i = 0;

  for (i = 0; i < 10; i++) {
    printf("%c", buf[i]);
  }

  return 0;
}
