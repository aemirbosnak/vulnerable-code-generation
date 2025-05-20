#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char str[100];
  gets(str);

  int len = strlen(str);
  if (len == 0) {
    printf("Error: Input is empty.\n");
    return 1;
  }

  int letter_count[26] = {0};
  for (int i = 0; i < len; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      letter_count[str[i] - 'a']++;
    }
  }

  printf("Letter frequency:\n");
  for (int i = 0; i < 26; i++) {
    if (letter_count[i] > 0) {
      printf("%c: %d\n", i + 'a', letter_count[i]);
    }
  }

  return 0;
}
