#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void parse_parens(char *str) {
  int len = strlen(str);
  char **parens = (char **)malloc(len * sizeof(char *));
  int i = 0;
  for (; i < len; i++) {
    switch (str[i]) {
      case '(':
      case '{' :
      case '[' :
        parens[i] = (char *)malloc(len * sizeof(char));
        break;
      case ')':
      case '}':
      case ']':
        if (!parens[i]) {
          free(parens[i - 1]);
          parens[i - 1] = NULL;
        }
        printf("%s", parens[i]);
        free(parens[i]);
        break;
    }
  }
  free(parens);
}

int main() {
  parse_parens("(())");
  return 0;
}
