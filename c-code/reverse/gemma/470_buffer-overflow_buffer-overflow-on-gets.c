#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char str[100];
  char search[20];
  char replace[20];

  printf("Enter text: ");
  gets(str);

  printf("Enter search word: ");
  gets(search);

  printf("Enter replacement word: ");
  gets(replace);

  int i, j, found = 0;
  for (i = 0; str[i] != '\0'; i++) {
    for (j = 0; search[j] != '\0'; j++) {
      if (str[i] == search[j] && str[i + 1] == search[j + 1] && str[i + 2] == search[j + 2]) {
        found = 1;
        str[i] = replace[0];
        str[i + 1] = replace[1];
        str[i + 2] = replace[2];
      }
    }
  }

  if (found) {
    printf("Text after replacement: \n");
    printf("%s", str);
  } else {
    printf("Word not found.\n");
  }

  return 0;
}
