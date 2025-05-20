#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char str[1000];
  printf("Enter a string: ");
  scanf("%s", str);

  char output[1000];
  int i = 0;
  for (int j = 0; str[j] != '\0'; j++) {
    int offset = (str[j] - 'a') * 3 + 11;
    output[i++] = (char)('a' + offset);
  }

  output[i] = '\0';
  printf("Cryptic output: %s\n", output);

  return 0;
}
