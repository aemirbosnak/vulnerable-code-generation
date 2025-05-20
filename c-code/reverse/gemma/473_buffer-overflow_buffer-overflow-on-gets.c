#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char str[100];
  printf("Enter text: ");
  scanf("%s", str);

  char search[20];
  printf("Enter search string: ");
  scanf("%s", search);

  char replace[20];
  printf("Enter replacement string: ");
  scanf("%s", replace);

  int len = strlen(str);
  int i = 0;
  for (i = 0; i < len; i++) {
    if (strstr(str, search) == str + i) {
      int j = 0;
      for (j = 0; replace[j] != '\0'; j++) {
        str[i + j] = replace[j];
      }
      i += strlen(replace) - 1;
    }
  }

  printf("Updated text: %s\n", str);

  return 0;
}
