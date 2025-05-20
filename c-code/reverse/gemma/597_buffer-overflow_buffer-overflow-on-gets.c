#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char str[100];
  printf("Enter a string: ");
  scanf("%s", str);

  char key[26] = "abcdefghijklmnopqrst";
  int i = 0;
  int len = strlen(str);

  for (i = 0; i < len; i++) {
    int idx = str[i] - 97;
    str[i] = key[idx] - 97 + 97;
  }

  printf("Translated string: %s\n", str);

  return 0;
}
