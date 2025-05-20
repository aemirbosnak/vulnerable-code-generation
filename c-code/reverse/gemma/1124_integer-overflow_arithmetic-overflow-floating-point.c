#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  int i = 0;
  float x = 0.0f;
  for (i = 0; i < 2147483647; i++) {
    x += 0.00001f;
  }
  return 0;
}
