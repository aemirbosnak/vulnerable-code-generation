#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char sentence[100];
  gets(sentence);

  int positive_words = 0;
  int negative_words = 0;

  for (int i = 0; sentence[i] != '\0'; i++) {
    char letter = sentence[i];
    letter = tolower(letter);

    if (letter == 'p' || letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u') {
      positive_words++;
    } else if (letter == 'n' || letter == 's' || letter == 't' || letter == 'h' || letter == 'r' || letter == 'b' || letter == 'f') {
      negative_words++;
    }
  }

  printf("Positive words: %d\n", positive_words);
  printf("Negative words: %d\n", negative_words);

  return 0;
}
