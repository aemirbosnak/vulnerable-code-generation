//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE  100
#define MAX_WORDS      1000

struct word {
  char* alien;
  char* english;
};

int compare_words(const void* a, const void* b) {
  return strcmp(((struct word*)a)->alien, ((struct word*)b)->alien);
}

int main() {
  // Load the dictionary
  struct word dictionary[MAX_WORDS];
  int num_words = 0;

  FILE* fp = fopen("alien_dictionary.txt", "r");
  if (fp == NULL) {
    fprintf(stderr, "Error opening dictionary file\n");
    return EXIT_FAILURE;
  }

  while (fscanf(fp, "%s %s", dictionary[num_words].alien,
             dictionary[num_words].english) == 2) {
    num_words++;
  }

  fclose(fp);

  // Sort the dictionary
  qsort(dictionary, num_words, sizeof(struct word), compare_words);

  // Get the input text
  char input_text[1024];
  printf("Enter the alien text to translate:\n");
  fgets(input_text, sizeof(input_text), stdin);

  // Translate the input text
  char* translated_text = malloc(strlen(input_text) * MAX_WORD_SIZE);
  int translated_text_length = 0;

  char* word = strtok(input_text, " ");
  while (word != NULL) {
    // Find the corresponding English word in the dictionary
    struct word* found_word =
        bsearch(word, dictionary, num_words, sizeof(struct word),
               compare_words);

    // Append the English word to the translated text
    if (found_word != NULL) {
      strcat(translated_text, found_word->english);
      translated_text_length += strlen(found_word->english);
    } else {
      // The word was not found in the dictionary
      strcat(translated_text, word);
      translated_text_length += strlen(word);
    }

    // Append a space to the translated text
    strcat(translated_text, " ");
    translated_text_length++;

    // Get the next word
    word = strtok(NULL, " ");
  }

  // Print the translated text
  printf("The translated text is:\n");
  printf("%s\n", translated_text);

  // Free the memory allocated for the translated text
  free(translated_text);

  return EXIT_SUCCESS;
}