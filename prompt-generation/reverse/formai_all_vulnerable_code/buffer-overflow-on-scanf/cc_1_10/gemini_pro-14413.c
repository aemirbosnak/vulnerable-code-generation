//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: Alan Turing
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

// Function to check if a string is a valid word in the Alien language
int is_valid_word(char *word) {
  int len = strlen(word);

  if (len < 3 || len > MAX_WORD_LENGTH) {
    return 0;
  }

  for (int i = 0; i < len; i++) {
    if (word[i] < 'a' || word[i] > 'z') {
      return 0;
    }
  }

  return 1;
}

// Function to translate a word from Alien to English
char *translate_word(char *word) {
  // Create a buffer for the translated word
  char *translated_word = malloc(MAX_WORD_LENGTH * sizeof(char));

  // Translate each character in the word
  for (int i = 0; i < strlen(word); i++) {
    translated_word[i] = word[strlen(word) - i - 1];
  }

  // Return the translated word
  return translated_word;
}

// Function to translate a sentence from Alien to English
char *translate_sentence(char *sentence) {
  // Create a buffer for the translated sentence
  char *translated_sentence = malloc(strlen(sentence) * sizeof(char));

  // Translate each word in the sentence
  char *word;
  while ((word = strtok(sentence, " ")) != NULL) {
    if (is_valid_word(word)) {
      strcat(translated_sentence, translate_word(word));
      strcat(translated_sentence, " ");
    } else {
      strcat(translated_sentence, word);
      strcat(translated_sentence, " ");
    }
  }

  // Return the translated sentence
  return translated_sentence;
}

// Main function
int main() {
  // Get the Alien sentence from the user
  char sentence[100];
  printf("Enter an Alien sentence: ");
  scanf("%s", sentence);

  // Translate the sentence from Alien to English
  char *translated_sentence = translate_sentence(sentence);

  // Print the translated sentence
  printf("Translated sentence: %s\n", translated_sentence);

  return 0;
}