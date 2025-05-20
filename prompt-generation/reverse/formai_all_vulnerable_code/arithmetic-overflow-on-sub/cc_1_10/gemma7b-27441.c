//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: ephemeral
#include <stdio.h>
#include <time.h>

int main() {
  time_t start, end;
  int i, words, characters, speed;
  char text[1000];

  start = time(NULL);

  printf("Please paste the text you want to type: ");
  gets(text);

  end = time(NULL);

  words = words_count(text);
  characters = characters_count(text);

  speed = characters / (end - start) * 60;

  printf("Your typing speed is: %d words per minute.\n", words);
  printf("Your typing speed is: %d characters per minute.\n", characters);
  printf("Your typing speed is: %d characters per second.\n", speed);

  return 0;
}

int words_count(char *text) {
  int words = 0;
  char *p = text;

  while (*p) {
    if (*p == ' ' || *p == '\n' || *p == '\t') {
      words++;
    }
    p++;
  }

  return words;
}

int characters_count(char *text) {
  int characters = 0;
  char *p = text;

  while (*p) {
    characters++;
    p++;
  }

  return characters;
}