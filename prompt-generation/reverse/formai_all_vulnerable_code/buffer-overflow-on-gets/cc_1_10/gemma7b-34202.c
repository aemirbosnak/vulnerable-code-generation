//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: real-life
#include <stdio.h>
#include <time.h>

int main() {
  time_t start, end;
  int i, words, characters, average_words;
  char text[1000];

  printf("Type the following text as quickly as possible:\n");
  printf("The quick brown fox jumps over the lazy dog.\n\n");

  start = time(NULL);

  // Replace this line with your own code to measure typing speed
  gets(text);

  end = time(NULL);

  words = words_in_text(text);
  characters = characters_in_text(text);

  average_words = words / (end - start);

  printf("Your typing speed is: %.2f words per second\n", average_words);

  return 0;
}

int words_in_text(char *text) {
  int words = 0;
  char *word = text;

  while (word) {
    word = strchr(word, ' ') ? strchr(word, ' ') : NULL;
    if (word) {
      words++;
    }
  }

  return words;
}

int characters_in_text(char *text) {
  int characters = 0;

  for (int i = 0; text[i] != '\0'; i++) {
    characters++;
  }

  return characters;
}