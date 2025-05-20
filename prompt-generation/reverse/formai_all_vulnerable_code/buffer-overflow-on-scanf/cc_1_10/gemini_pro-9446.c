//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alien_dictionary {
  char alien_word[255];
  char english_translation[255];
};

struct alien_dictionary dictionary[] = {
  {"ali", "hello"},
  {"anbe", "good"},
  {"ashe", "thank you"},
  {"bah", "no"},
  {"dah", "yes"},
  {"dek", "water"},
  {"den", "food"},
  {"di", "come"},
  {"do", "go"},
  {"ee", "yes"},
  {"eh", "no"},
  {"ek", "water"},
  {"en", "food"},
  {"fi", "come"},
  {"fo", "go"},
  {"gi", "sit"},
  {"go", "stand"},
  {"he", "sleep"},
  {"hi", "wake up"},
  {"ji", "eat"},
  {"jo", "drink"},
  {"ki", "speak"},
  {"ko", "listen"},
  {"le", "see"},
  {"lo", "look"},
  {"mi", "think"},
  {"mo", "know"},
  {"ne", "understand"},
  {"no", "forget"},
  {"ni", "happy"},
  {"no", "sad"},
  {"pi", "angry"},
  {"po", "calm"},
  {"qi", "love"},
  {"qo", "hate"},
  {"ri", "friend"},
  {"ro", "enemy"},
  {"se", "father"},
  {"so", "mother"},
  {"te", "brother"},
  {"to", "sister"},
  {"ve", "husband"},
  {"vo", "wife"},
  {"we", "son"},
  {"wo", "daughter"},
  {"xe", "home"},
  {"xo", "work"},
  {"ye", "school"},
  {"yo", "hospital"},
  {"ze", "market"},
  {"zo", "park"}
};

int num_words = sizeof(dictionary) / sizeof(struct alien_dictionary);

char *translate_alien_to_english(char *alien_word) {
  for (int i = 0; i < num_words; i++) {
    if (strcmp(alien_word, dictionary[i].alien_word) == 0) {
      return dictionary[i].english_translation;
    }
  }
  return NULL;
}

int main() {
  char alien_word[255];
  char *english_translation;

  printf("Enter an alien word: ");
  scanf("%s", alien_word);

  english_translation = translate_alien_to_english(alien_word);

  if (english_translation != NULL) {
    printf("The English translation of %s is %s.\n", alien_word, english_translation);
  } else {
    printf("I don't know that alien word.\n");
  }

  return 0;
}