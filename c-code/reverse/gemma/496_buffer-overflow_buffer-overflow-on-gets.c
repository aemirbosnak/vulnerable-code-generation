#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char text[1024];
  gets(text);

  int letter_count[26] = {0};
  for (int i = 0; text[i] != '\0'; i++) {
    if (text[i] >= 'a' && text[i] <= 'z') {
      letter_count[text[i] - 'a']++;
    }
  }

  int max_count = 0;
  char most_frequent_letter = '\0';
  for (int i = 0; i < 26; i++) {
    if (letter_count[i] > max_count) {
      max_count = letter_count[i];
      most_frequent_letter = 'a' + i;
    }
  }

  printf("The most frequent letter is: %c, with a count of: %d\n", most_frequent_letter, max_count);

  return 0;
}
