#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void parseString(char *str) {
  int i = 0;
  char **parens = NULL;
  int parenCount = 0;

  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
      parens = realloc(parens, (parenCount + 1) * sizeof(char *));
      parens[parenCount++] = str[i];
    }
  }

  for (i = 0; i < parenCount; i++) {
    printf("%c", parens[i]);
  }

  free(parens);
  // Use-after-free vulnerability: Accessing memory freed in the previous line
  printf("%c", parens[0]);
}

int main() {
  parseString("(())");
  return 0;
}
