#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char str[100000];
  gets(str);

  int word_count = 0;
  int special_char_count = 0;
  int average_word_length = 0;

  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == ' ') {
      word_count++;
    } else if (!isalnum(str[i])) {
      special_char_count++;
    }
  }

  average_word_length = (word_count * 3) / special_char_count;

  printf("Word count: %d\n", word_count);
  printf("Special character count: %d\n", special_char_count);
  printf("Average word length: %d\n", average_word_length);

  return 0;
}
