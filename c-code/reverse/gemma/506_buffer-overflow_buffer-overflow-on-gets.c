#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char arr[10];
  gets(arr);
  int num1, num2;
  scanf("%d %d", &num1, &num2);
  int result = num1 + num2 + strlen(arr);
  printf("%d", result);
  return 0;
}
