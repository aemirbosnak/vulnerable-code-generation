#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int x = 0;
  int y = 0;
  int z = 0;

  printf("Enter two integers: ");
  scanf("%d %d", &x, &y);

  z = x + y;

  if (z > 1000000) {
    printf("Overflow! The sum is too large.\n");
  } else {
    printf("The sum is: %d\n", z);
  }

  return 0;
}
