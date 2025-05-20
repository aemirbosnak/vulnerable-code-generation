//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Cat Language keywords
#define CAT_MEOW "meow"
#define CAT_PURR "purr"
#define CAT_HISS "hiss"
#define CAT_SCRATCH "scratch"

// Define the English Language translations
#define ENG_MEOW "Hello"
#define ENG_PURR "I'm happy"
#define ENG_HISS "Go away"
#define ENG_SCRATCH "I'm angry"

// Define the Cat Language grammar
#define CAT_SENTENCE_START "CAT "
#define CAT_SENTENCE_END ";"

// Define the maximum length of a Cat Language sentence
#define CAT_SENTENCE_MAX_LEN 100

// Function to translate a Cat Language sentence to English
char *cat_to_eng(char *cat_sentence) {
  // Check if the sentence is valid
  if (strncmp(cat_sentence, CAT_SENTENCE_START, strlen(CAT_SENTENCE_START)) != 0 || strncmp(cat_sentence + strlen(cat_sentence) - strlen(CAT_SENTENCE_END), CAT_SENTENCE_END, strlen(CAT_SENTENCE_END)) != 0) {
    return NULL;
  }

  // Allocate memory for the English translation
  char *eng_sentence = malloc(CAT_SENTENCE_MAX_LEN);
  if (eng_sentence == NULL) {
    return NULL;
  }

  // Copy the sentence without the start and end markers
  strncpy(eng_sentence, cat_sentence + strlen(CAT_SENTENCE_START), strlen(cat_sentence) - strlen(CAT_SENTENCE_START) - strlen(CAT_SENTENCE_END));

  // Replace the Cat Language keywords with the English translations
  char *word = strtok(eng_sentence, " ");
  while (word != NULL) {
    if (strcmp(word, CAT_MEOW) == 0) {
      strcpy(word, ENG_MEOW);
    } else if (strcmp(word, CAT_PURR) == 0) {
      strcpy(word, ENG_PURR);
    } else if (strcmp(word, CAT_HISS) == 0) {
      strcpy(word, ENG_HISS);
    } else if (strcmp(word, CAT_SCRATCH) == 0) {
      strcpy(word, ENG_SCRATCH);
    }
    word = strtok(NULL, " ");
  }

  // Return the English translation
  return eng_sentence;
}

// Function to translate an English sentence to Cat Language
char *eng_to_cat(char *eng_sentence) {
  // Allocate memory for the Cat Language translation
  char *cat_sentence = malloc(CAT_SENTENCE_MAX_LEN);
  if (cat_sentence == NULL) {
    return NULL;
  }

  // Copy the sentence without the start and end markers
  strncpy(cat_sentence, CAT_SENTENCE_START, strlen(CAT_SENTENCE_START));
  strncat(cat_sentence, eng_sentence, strlen(eng_sentence));
  strncat(cat_sentence, CAT_SENTENCE_END, strlen(CAT_SENTENCE_END));

  // Replace the English Language translations with the Cat Language keywords
  char *word = strtok(cat_sentence, " ");
  while (word != NULL) {
    if (strcmp(word, ENG_MEOW) == 0) {
      strcpy(word, CAT_MEOW);
    } else if (strcmp(word, ENG_PURR) == 0) {
      strcpy(word, CAT_PURR);
    } else if (strcmp(word, ENG_HISS) == 0) {
      strcpy(word, CAT_HISS);
    } else if (strcmp(word, ENG_SCRATCH) == 0) {
      strcpy(word, CAT_SCRATCH);
    }
    word = strtok(NULL, " ");
  }

  // Return the Cat Language translation
  return cat_sentence;
}

int main() {
  // Get the Cat Language sentence from the user
  char cat_sentence[CAT_SENTENCE_MAX_LEN];
  printf("Enter a Cat Language sentence: ");
  scanf("%s", cat_sentence);

  // Translate the Cat Language sentence to English
  char *eng_sentence = cat_to_eng(cat_sentence);
  if (eng_sentence == NULL) {
    printf("Invalid Cat Language sentence\n");
  } else {
    printf("English translation: %s\n", eng_sentence);
  }

  // Translate the English sentence to Cat Language
  char *cat_sentence2 = eng_to_cat(eng_sentence);
  if (cat_sentence2 == NULL) {
    printf("Invalid English sentence\n");
  } else {
    printf("Cat Language translation: %s\n", cat_sentence2);
  }

  // Free the allocated memory
  free(eng_sentence);
  free(cat_sentence2);

  return 0;
}