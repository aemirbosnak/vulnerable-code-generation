//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_DICTIONARY_SIZE 1000

// Define the Alien language dictionary
typedef struct {
  char alien_word[MAX_WORD_LENGTH];
  char english_word[MAX_WORD_LENGTH];
} DictionaryEntry;

DictionaryEntry dictionary[MAX_DICTIONARY_SIZE];
int dictionary_size = 0;

// Load the Alien language dictionary from a file
void load_dictionary(char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening dictionary file");
    exit(EXIT_FAILURE);
  }

  while (fscanf(file, "%s %s", dictionary[dictionary_size].alien_word, dictionary[dictionary_size].english_word) != EOF) {
    dictionary_size++;
  }

  fclose(file);
}

// Translate an Alien language word to English
char *translate_word(char *alien_word) {
  for (int i = 0; i < dictionary_size; i++) {
    if (strcmp(alien_word, dictionary[i].alien_word) == 0) {
      return dictionary[i].english_word;
    }
  }

  return NULL;
}

// Translate an Alien language sentence to English
char *translate_sentence(char *alien_sentence) {
  char *english_sentence = malloc(strlen(alien_sentence) + 1);
  if (english_sentence == NULL) {
    perror("Error allocating memory for English sentence");
    exit(EXIT_FAILURE);
  }

  char *alien_word = strtok(alien_sentence, " ");
  while (alien_word != NULL) {
    char *english_word = translate_word(alien_word);
    if (english_word == NULL) {
      strcpy(english_sentence, "Unknown alien word");
      break;
    } else {
      strcat(english_sentence, english_word);
      strcat(english_sentence, " ");
    }

    alien_word = strtok(NULL, " ");
  }

  return english_sentence;
}

// Main function
int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s <dictionary_file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  load_dictionary(argv[1]);

  char alien_sentence[100];
  printf("Enter an Alien language sentence: ");
  gets(alien_sentence);

  char *english_sentence = translate_sentence(alien_sentence);
  printf("English translation: %s\n", english_sentence);

  free(english_sentence);

  return EXIT_SUCCESS;
}