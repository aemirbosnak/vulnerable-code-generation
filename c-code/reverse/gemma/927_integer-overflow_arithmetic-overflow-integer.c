#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <limits.h>

int main() {
  int num_operations = 0;
  int i = 0;
  int a, b, c;

  printf("Enter the number of operations (up to 10): ");
  scanf("%d", &num_operations);

  for (i = 0; i < num_operations; i++) {
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    c = a + b;

    if (c > INT_MAX) {
      printf("Overflow!\n");
    } else {
      printf("The result is: %d\n", c);
    }
  }

  return 0;
}
