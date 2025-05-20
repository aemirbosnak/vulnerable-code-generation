//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 20
#define MAX_SENTENCE_LEN 100

typedef struct {
  char *alien_word;
  char *english_word;
} Word;

typedef struct {
  Word *words;
  int num_words;
} Dictionary;

Dictionary *load_dictionary() {
  Dictionary *dict = malloc(sizeof(Dictionary));
  dict->words = malloc(sizeof(Word) * MAX_WORD_LEN);
  dict->num_words = 0;

  FILE *f = fopen("dictionary.txt", "r");
  while (!feof(f)) {
    char alien_word[MAX_WORD_LEN];
    char english_word[MAX_WORD_LEN];

    fscanf(f, "%s %s\n", alien_word, english_word);
    dict->words[dict->num_words].alien_word = strdup(alien_word);
    dict->words[dict->num_words].english_word = strdup(english_word);
    dict->num_words++;
  }
  fclose(f);

  return dict;
}

void free_dictionary(Dictionary *dict) {
  for (int i = 0; i < dict->num_words; i++) {
    free(dict->words[i].alien_word);
    free(dict->words[i].english_word);
  }
  free(dict->words);
  free(dict);
}

char *translate_word(Dictionary *dict, char *alien_word) {
  for (int i = 0; i < dict->num_words; i++) {
    if (!strcmp(dict->words[i].alien_word, alien_word)) {
      return dict->words[i].english_word;
    }
  }
  return NULL;
}

char *translate_sentence(Dictionary *dict, char *sentence) {
  char *translated_sentence = malloc(MAX_SENTENCE_LEN);
  char *token = strtok(sentence, " ");
  while (token != NULL) {
    char *translated_word = translate_word(dict, token);
    if (translated_word != NULL) {
      strcat(translated_sentence, translated_word);
    } else {
      strcat(translated_sentence, token);
    }
    strcat(translated_sentence, " ");
    token = strtok(NULL, " ");
  }

  return translated_sentence;
}

int main() {
  Dictionary *dict = load_dictionary();
  char sentence[] = "Glooby zoob boogly boogly";
  char *translated_sentence = translate_sentence(dict, sentence);
  printf("%s\n", translated_sentence);

  free_dictionary(dict);
  free(translated_sentence);
  return 0;
}