#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *word = NULL;
  int word_size = 0;
  char **words = NULL;
  int word_count = 0;

  // Allocate memory for the word list
  words = malloc(sizeof(char *) * 10);
  if (words == NULL) {
    return 1;
  }

  // Get the word from the user
  word = malloc(20);
  if (word == NULL) {
    return 1;
  }

  // Read the word from the user
  scanf("%s", word);

  // Increment the word count
  word_count++;

  // Add the word to the list
  words[word_count - 1] = word;

  // Free the memory allocated for the word
  free(word);

  // Free the memory allocated for the word list
  free(words);

  return 0;
}
