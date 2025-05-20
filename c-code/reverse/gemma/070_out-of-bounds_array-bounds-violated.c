#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char str[1001];
  scanf("%s", str);
  int len = strlen(str);
  int i = 0;
  for (i = 0; i < len / 2; i++) {
    if (str[i] != str[len - 1 - i]) {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
  return 0;
}
