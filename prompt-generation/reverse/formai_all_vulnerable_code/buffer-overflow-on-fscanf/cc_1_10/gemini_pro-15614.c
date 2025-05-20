//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_DICTIONARY_SIZE 100

// Function to read the dictionary from a file
int read_dictionary(char *filename, char dictionary[][MAX_WORD_LENGTH]) {
  FILE *fp;
  int i = 0;

  // Open the file
  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return -1;
  }

  // Read the words from the file
  while (fscanf(fp, "%s", dictionary[i]) != EOF) {
    i++;
  }

  // Close the file
  fclose(fp);

  // Return the number of words in the dictionary
  return i;
}

// Function to translate a word from Alien to English
char *translate_word(char *word, char dictionary[][MAX_WORD_LENGTH], int dictionary_size) {
  int i;

  // Loop through the dictionary
  for (i = 0; i < dictionary_size; i++) {
    // If the word matches a word in the dictionary, return the English translation
    if (strcmp(word, dictionary[i]) == 0) {
      return dictionary[i];
    }
  }

  // If the word is not in the dictionary, return NULL
  return NULL;
}

// Function to translate a sentence from Alien to English
char *translate_sentence(char *sentence, char dictionary[][MAX_WORD_LENGTH], int dictionary_size) {
  char *translated_sentence;
  char *word;
  char *translated_word;

  // Allocate memory for the translated sentence
  translated_sentence = malloc(strlen(sentence) + 1);
  if (translated_sentence == NULL) {
    perror("Error allocating memory");
    return NULL;
  }

  // Tokenize the sentence
  word = strtok(sentence, " ");

  // Translate each word in the sentence
  while (word != NULL) {
    translated_word = translate_word(word, dictionary, dictionary_size);
    if (translated_word == NULL) {
      // If the word is not in the dictionary, leave it untranslated
      strcat(translated_sentence, word);
    } else {
      // If the word is in the dictionary, append the translation to the translated sentence
      strcat(translated_sentence, translated_word);
    }

    // Add a space to the translated sentence
    strcat(translated_sentence, " ");

    // Get the next word in the sentence
    word = strtok(NULL, " ");
  }

  // Return the translated sentence
  return translated_sentence;
}

// Main function
int main() {
  char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_LENGTH];
  int dictionary_size;
  char sentence[100];
  char *translated_sentence;

  // Read the dictionary from the file
  dictionary_size = read_dictionary("dictionary.txt", dictionary);
  if (dictionary_size == -1) {
    return EXIT_FAILURE;
  }

  // Get the sentence to be translated
  printf("Enter the sentence to be translated: ");
  gets(sentence);

  // Translate the sentence
  translated_sentence = translate_sentence(sentence, dictionary, dictionary_size);

  // Print the translated sentence
  printf("Translated sentence: %s\n", translated_sentence);

  // Free the memory allocated for the translated sentence
  free(translated_sentence);

  return EXIT_SUCCESS;
}