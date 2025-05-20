//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char str[] = "This is a sample text for word frequency counting.";
  int i = 0;
  char word[20];
  int word_count = 0;

  // Iterate over the text and split words
  while (str[i] != '\0') {
    if (str[i] == ' ' || str[i] == '.' || str[i] == ',') {
      word[0] = '\0';
      word_count++;
    } else {
      word[i - 1] = str[i];
      i++;
    }
  }

  // Create a dictionary to store word frequencies
  int dictionary[word_count];
  for (i = 0; i < word_count; i++) {
    dictionary[i] = 0;
  }

  // Count the frequency of each word
  i = 0;
  while (word[i] != '\0') {
    int word_length = 0;
    char current_word[20];
    current_word[0] = '\0';
    while (word[i] != ' ' && word[i] != '.' && word[i] != ',') {
      current_word[word_length] = word[i];
      word_length++;
      i++;
    }
    current_word[word_length] = '\0';
    dictionary[strcmp(current_word, word)]++;
  }

  // Print the word frequencies
  i = 0;
  printf("Word frequencies:\n");
  while (dictionary[i] != 0) {
    printf("%s: %d\n", dictionary[i], dictionary[i]);
    i++;
  }

  return 0;
}