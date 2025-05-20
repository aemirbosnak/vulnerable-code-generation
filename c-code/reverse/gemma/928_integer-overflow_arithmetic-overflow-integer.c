#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  int a, b, c, d, product;
  printf("Enter two integers:");
  scanf("%d %d", &a, &b);
  c = a * b;
  d = c / 2;
  product = d * 3;
  printf("The product is: %d", product);
  return 0;
}
