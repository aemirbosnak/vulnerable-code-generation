//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALIEN_LANG_LEN 100

typedef struct {
  char *alien_word;
  char *english_word;
} AlienWord;

AlienWord alien_words[] = {
  {"floopy", "hello"},
  {"doogy", "goodbye"},
  {"slippy", "friend"},
  {"flippy", "enemy"},
  {"blorpy", "food"},
  {"zorpy", "water"},
  {"slippy", "friend"},
  {"floopy", "hello"},
  {"doogy", "goodbye"},
  {"slippy", "friend"},
  {"flippy", "enemy"},
  {"blorpy", "food"},
  {"zorpy", "water"},
  {"slippy", "friend"},
  {"floopy", "hello"},
  {"doogy", "goodbye"},
  {"slippy", "friend"},
  {"flippy", "enemy"},
  {"blorpy", "food"},
  {"zorpy", "water"},
  {"slippy", "friend"},
  {"floopy", "hello"},
  {"doogy", "goodbye"},
  {"slippy", "friend"},
  {"flippy", "enemy"},
  {"blorpy", "food"},
  {"zorpy", "water"},
  {"slippy", "friend"},
  {"floopy", "hello"},
  {"doogy", "goodbye"},
  {"slippy", "friend"},
  {"flippy", "enemy"},
  {"blorpy", "food"},
  {"zorpy", "water"},
  {"slippy", "friend"},
  {"floopy", "hello"},
  {"doogy", "goodbye"},
  {"slippy", "friend"},
  {"flippy", "enemy"},
  {"blorpy", "food"},
  {"zorpy", "water"},
  {"slippy", "friend"},
  {"floopy", "hello"},
  {"doogy", "goodbye"},
  {"slippy", "friend"},
  {"flippy", "enemy"},
  {"blorpy", "food"},
  {"zorpy", "water"},
  {"slippy", "friend"},
  {"floopy", "hello"},
  {"doogy", "goodbye"},
  {"slippy", "friend"},
  {"flippy", "enemy"},
  {"blorpy", "food"},
  {"zorpy", "water"},
  {"slippy", "friend"},
  {"floopy", "hello"},
  {"doogy", "goodbye"},
  {"slippy", "friend"},
  {"flippy", "enemy"},
  {"blorpy", "food"},
  {"zorpy", "water"},
  {"slippy", "friend"},
  {"floopy", "hello"},
  {"doogy", "goodbye"},
  {"slippy", "friend"},
  {"flippy", "enemy"},
  {"blorpy", "food"},
  {"zorpy", "water"},
  {"slippy", "friend"},
  {"floopy", "hello"},
  {"doogy", "goodbye"},
  {"slippy", "friend"},
  {"flippy", "enemy"},
  {"blorpy", "food"},
  {"zorpy", "water"},
  {"slippy", "friend"},
  {"floopy", "hello"},
  {"doogy", "goodbye"},
  {"slippy", "friend"},
  {"flippy", "enemy"},
  {"blorpy", "food"},
  {"zorpy", "water"},
  {"slippy", "friend"},
  {"floopy", "hello"},
  {"doogy", "goodbye"},
  {"slippy", "friend"},
  {"flippy", "enemy"},
  {"blorpy", "food"},
  {"zorpy", "water"},
  {"slippy", "friend"},
  {"floopy", "hello"},
  {"doogy", "goodbye"},
  {"slippy", "friend"},
  {"flippy", "enemy"},
  {"blorpy", "food"},
  {"zorpy", "water"},
  {"slippy", "friend"},
  {"floopy", "hello"},
  {"doogy", "goodbye"},
  {"slippy", "friend"},
  {"flippy", "enemy"},
  {"blorpy", "food"},
  {"zorpy", "water"},
  {"slippy", "friend"},
  {"floopy", "hello"},
  {"doogy", "goodbye"},
  {"slippy", "friend"},
  {"flippy", "enemy"},
  {"blorpy", "food"},
  {"zorpy", "water"},
  {"slippy", "friend"},
  {"floopy", "hello"},
  {"doogy", "goodbye"},
  {"slippy", "friend"},
  {"flippy", "enemy"},
  {"blorpy", "food"},
  {"zorpy", "water"},
  {"slippy", "friend"},
  {"floopy", "hello"},
  {"doogy", "goodbye"},
  {"slippy", "friend"},
  {"flippy", "enemy"},
  {"blorpy", "food"},
  {"zorpy", "water"},
  {"slippy", "friend"},
  {"floopy", "hello"},
  {"doogy", "goodbye"},
  {"slippy", "friend"}
};

int main() {
  char alien_word[ALIEN_LANG_LEN];
  char english_word[ALIEN_LANG_LEN];
  int i;

  printf("Enter an Alien word: ");
  scanf("%s", alien_word);

  for (i = 0; i < sizeof(alien_words) / sizeof(AlienWord); i++) {
    if (strcmp(alien_word, alien_words[i].alien_word) == 0) {
      strcpy(english_word, alien_words[i].english_word);
      break;
    }
  }

  if (i == sizeof(alien_words) / sizeof(AlienWord)) {
    printf("Unknown Alien word: %s\n", alien_word);
  } else {
    printf("English translation: %s\n", english_word);
  }

  return 0;
}