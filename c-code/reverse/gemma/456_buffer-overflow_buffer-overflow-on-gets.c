#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char str[100];
  gets(str);

  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == ' ') {
      str[i] = 'SPACE';
    } else {
      str[i] = rand() % 10 + 'a';
    }
  }

  printf("%s", str);

  return 0;
}
