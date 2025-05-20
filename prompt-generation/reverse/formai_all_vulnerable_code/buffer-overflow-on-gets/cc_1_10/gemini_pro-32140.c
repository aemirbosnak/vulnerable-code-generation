//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 30

// Function to check if a character is alphanumeric
int is_alphanumeric(char c) {
  return isalpha(c) || isdigit(c);
}

// Function to count the number of words in a string
int count_words(char *str) {
  int i, word_count = 0;
  int in_word = 0;
  
  for (i = 0; str[i] != '\0'; i++) {
    if (is_alphanumeric(str[i])) {
      if (!in_word) {
        word_count++;
        in_word = 1;
      }
    } else {
      in_word = 0;
    }
  }

  return word_count;
}

// Function to print the words and their frequencies in a string
void print_word_frequencies(char *str) {
  int i, j, word_count, word_frequency;
  char words[MAX_WORDS][MAX_WORD_LEN];
  int frequencies[MAX_WORDS];

  // Initialize the words and frequencies arrays
  for (i = 0; i < MAX_WORDS; i++) {
    words[i][0] = '\0';
    frequencies[i] = 0;
  }

  // Count the words and store them in the words array
  word_count = count_words(str);
  i = 0;
  int word_index = 0;
  int word_len = 0;
  while (str[i] != '\0') {
    if (is_alphanumeric(str[i])) {
      words[word_index][word_len] = str[i];
      word_len++;
    } else {
      words[word_index][word_len] = '\0';
      word_index++;
      word_len = 0;
    }
    i++;
  }

  // Count the frequencies of each word
  for (i = 0; i < word_count; i++) {
    word_frequency = 0;
    for (j = 0; j < word_count; j++) {
      if (strcmp(words[i], words[j]) == 0) {
        word_frequency++;
      }
    }
    frequencies[i] = word_frequency;
  }

  // Print the words and their frequencies
  printf("Words:\n");
  for (i = 0; i < word_count; i++) {
    printf("%s: %d\n", words[i], frequencies[i]);
  }
}

int main() {
  char str[1000];
  char *p;
  int word_count;

  printf("Enter a string: ");
  gets(str);

// Allocate memory for the string assuming max length is 500
  p = malloc(500);

  printf("Word count: %d\n", count_words(str));
  print_word_frequencies(str);

  return 0;
}