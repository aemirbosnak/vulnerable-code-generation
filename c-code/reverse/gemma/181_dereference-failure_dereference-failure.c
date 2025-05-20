#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

char translate(char c) {
  if (c >= 'a' && c <= 'z') {
    return c - 32;
  }
  return c;
}

int main() {
  char str[100];
  printf("Enter an alien language string: ");
  scanf("%s", str);

  for (int i = 0; str[i] != '\0'; i++) {
    str[i] = translate(str[i]);
  }

  printf("Translated string: %s\n", str);

  return 0;
}
