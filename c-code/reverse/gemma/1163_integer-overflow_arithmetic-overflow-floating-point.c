#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char str[100001];
  scanf("%s", str);

  int word_count = 0;
  int special_char_count = 0;
  int average_word_length = 0;
  int entropy = 0;

  char *word = strtok(str, " ");
  while (word) {
    word_count++;
    char *special_char = strchr(word, '$');
    if (special_char) {
      special_char_count++;
    }
    average_word_length += strlen(word) / word_count;
    word = strtok(NULL, " ");
  }

  entropy = (word_count * average_word_length) * 2 + special_char_count * 3;

  printf("Word count: %d\n", word_count);
  printf("Special character count: %d\n", special_char_count);
  printf("Average word length: %.2f\n", (double)average_word_length);
  printf("Entropy: %.2f\n", (double)entropy);

  return 0;
}
