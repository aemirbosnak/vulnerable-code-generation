//Falcon2-11B DATASET v1.0 Category: Cat Language Translator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 100

int main(int argc, char **argv) {
  char original_string[MAX_WORD_SIZE];
  char translation_string[MAX_WORD_SIZE];
  int original_length = 0;
  int translation_length = 0;
  
  printf("Enter the original string: ");
  fgets(original_string, MAX_WORD_SIZE, stdin);
  original_length = strlen(original_string);
  
  printf("Enter the translation string: ");
  fgets(translation_string, MAX_WORD_SIZE, stdin);
  translation_length = strlen(translation_string);
  
  char *original_words[original_length];
  char *translation_words[translation_length];
  
  int i = 0;
  while (original_string[i]!= '\0') {
    original_words[i] = malloc(MAX_WORD_SIZE);
    fgets(original_words[i], MAX_WORD_SIZE, stdin);
    i++;
  }
  
  i = 0;
  while (translation_string[i]!= '\0') {
    translation_words[i] = malloc(MAX_WORD_SIZE);
    fgets(translation_words[i], MAX_WORD_SIZE, stdin);
    i++;
  }
  
  int random_index = rand() % original_length;
  char *random_original_word = original_words[random_index];
  char *random_translation_word = translation_words[random_index];
  
  char *p = original_string;
  while (*p!= '\0') {
    *p = *random_original_word;
    p++;
    random_original_word++;
  }
  
  p = translation_string;
  while (*p!= '\0') {
    *p = *random_translation_word;
    p++;
    random_translation_word++;
  }
  
  printf("Translated string: %s\n", translation_string);
  
  return 0;
}