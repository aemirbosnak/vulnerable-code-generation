#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int num1 = 2147483647;
  int num2 = 2;
  int result = num1 * num2;

  printf("The result of num1 * num2 is: %d", result);

  return 0;
}
