#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char str[1024];
  gets(str);

  int letter_frequency[26] = {0};
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      letter_frequency[str[i] - 'a']++;
    }
  }

  int max_frequency = 0;
  for (int i = 0; i < 26; i++) {
    if (letter_frequency[i] > max_frequency) {
      max_frequency = letter_frequency[i];
    }
  }

  printf("The most frequent letter is: %c, with frequency %d\n", 'a' + max_frequency, max_frequency);

  return 0;
}
