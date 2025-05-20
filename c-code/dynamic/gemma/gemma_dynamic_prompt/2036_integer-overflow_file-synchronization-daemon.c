#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int i = 0;
  int j = 0;
  int n = 1;

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      int product = i * j;
      printf("%d ", product);
    }
  }

  return 0;
}
