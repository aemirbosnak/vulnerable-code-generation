//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
  // Get the input text from the user.
  char *text = malloc(1000);
  printf("Enter your text: ");
  gets(text);

  // Convert the text to lowercase.
  for (int i = 0; i < strlen(text); i++) {
    text[i] = tolower(text[i]);
  }

  // Count the number of words in the text.
  int word_count = 0;
  for (int i = 0; i < strlen(text); i++) {
    if (text[i] == ' ') {
      word_count++;
    }
  }

  // Find the most frequent word in the text.
  char *most_frequent_word = NULL;
  int most_frequent_count = 0;
  for (int i = 0; i < strlen(text); i++) {
    // Get the current word.
    char *word = malloc(100);
    int word_length = 0;
    while (text[i] != ' ' && text[i] != '\0') {
      word[word_length] = text[i];
      word_length++;
      i++;
    }
    word[word_length] = '\0';

    // Count the number of occurrences of the current word.
    int count = 0;
    for (int j = 0; j < strlen(text); j++) {
      char *word2 = malloc(100);
      int word2_length = 0;
      while (text[j] != ' ' && text[j] != '\0') {
        word2[word2_length] = text[j];
        word2_length++;
        j++;
      }
      word2[word2_length] = '\0';
      if (strcmp(word, word2) == 0) {
        count++;
      }
      free(word2);
    }

    // Update the most frequent word and count if necessary.
    if (count > most_frequent_count) {
      most_frequent_count = count;
      most_frequent_word = word;
    }
    free(word);
  }

  // Print the most frequent word and count.
  printf("Most frequent word: %s\n", most_frequent_word);
  printf("Frequency: %d\n", most_frequent_count);

  // Free the allocated memory.
  free(text);
  free(most_frequent_word);
  return 0;
}