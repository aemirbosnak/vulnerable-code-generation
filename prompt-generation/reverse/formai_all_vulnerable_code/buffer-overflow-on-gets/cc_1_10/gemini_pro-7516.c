//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum number of words to count
#define MAX_WORDS 1000

// Define the structure of a word count entry
typedef struct word_count {
  char *word;
  int count;
} word_count;

// Function to compare two word count entries by word
int compare_word_counts(const void *a, const void *b) {
  const word_count *word_count_a = (const word_count *)a;
  const word_count *word_count_b = (const word_count *)b;
  return strcmp(word_count_a->word, word_count_b->word);
}

// Function to count the words in a string
int count_words(char *string, word_count *word_counts) {
  // Allocate memory for the word count array
  word_counts = malloc(MAX_WORDS * sizeof(word_count));

  // Initialize the word count array
  for (int i = 0; i < MAX_WORDS; i++) {
    word_counts[i].word = NULL;
    word_counts[i].count = 0;
  }

  // Tokenize the string into words
  char *token = strtok(string, " ");
  while (token != NULL) {
    // Convert the word to lowercase
    for (int i = 0; i < strlen(token); i++) {
      token[i] = tolower(token[i]);
    }

    // Find the word in the word count array
    int index = -1;
    for (int i = 0; i < MAX_WORDS; i++) {
      if (word_counts[i].word != NULL && strcmp(word_counts[i].word, token) == 0) {
        index = i;
        break;
      }
    }

    // If the word was not found, add it to the array
    if (index == -1) {
      index = 0;
      while (word_counts[index].word != NULL) {
        index++;
      }
      word_counts[index].word = malloc(strlen(token) + 1);
      strcpy(word_counts[index].word, token);
      word_counts[index].count = 1;
    } else {
      // If the word was found, increment its count
      word_counts[index].count++;
    }

    // Get the next token
    token = strtok(NULL, " ");
  }

  // Return the number of words in the string
  return index;
}

// Function to print the word counts
void print_word_counts(word_count *word_counts, int count) {
  // Sort the word counts by word
  qsort(word_counts, count, sizeof(word_count), compare_word_counts);

  // Print the word counts
  for (int i = 0; i < count; i++) {
    printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
  }
}

// Main function
int main() {
  // Get the input string from the user
  char *string = malloc(1024);
  printf("Enter a string: ");
  gets(string);

  // Count the words in the string
  word_count word_counts[MAX_WORDS];
  int count = count_words(string, word_counts);

  // Print the word counts
  print_word_counts(word_counts, count);

  // Free the memory allocated for the word count array
  for (int i = 0; i < MAX_WORDS; i++) {
    if (word_counts[i].word != NULL) {
      free(word_counts[i].word);
    }
  }
  free(word_counts);

  // Free the memory allocated for the input string
  free(string);

  return 0;
}