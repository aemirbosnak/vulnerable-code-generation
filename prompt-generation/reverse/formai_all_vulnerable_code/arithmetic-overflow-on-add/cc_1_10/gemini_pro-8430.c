//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Define the maximum number of words
#define MAX_WORDS 10000

// Create a struct to store a word and its count
typedef struct {
  char word[MAX_WORD_LENGTH];
  int count;
} Word;

// Create an array of words
Word words[MAX_WORDS];

// Create a pointer to the current word
Word *current_word;

// Create a function to compare two words
int compare_words(const void *a, const void *b) {
  Word *word1 = (Word *)a;
  Word *word2 = (Word *)b;
  return strcmp(word1->word, word2->word);
}

// Create a function to count the words in a file
int count_words(FILE *file) {
  // Initialize the word count
  int word_count = 0;

  // Read the file line by line
  char line[1024];
  while (fgets(line, sizeof(line), file)) {
    // Tokenize the line into words
    char *word = strtok(line, " ");

    // Loop through the words
    while (word) {
      // Check if the word is already in the array
      current_word = bsearch(word, words, word_count, sizeof(Word), compare_words);

      // If the word is not in the array, add it
      if (!current_word) {
        strcpy(words[word_count].word, word);
        words[word_count].count = 1;
        word_count++;
      }
      // If the word is already in the array, increment its count
      else {
        current_word->count++;
      }

      // Get the next word
      word = strtok(NULL, " ");
    }
  }

  // Return the word count
  return word_count;
}

// Create a function to print the word counts
void print_word_counts(int word_count) {
  // Sort the words by count
  qsort(words, word_count, sizeof(Word), compare_words);

  // Print the word counts
  for (int i = 0; i < word_count; i++) {
    printf("%s: %d\n", words[i].word, words[i].count);
  }
}

int main() {
  // Open the file
  FILE *file = fopen("input.txt", "r");
  if (!file) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  // Count the words in the file
  int word_count = count_words(file);

  // Print the word counts
  print_word_counts(word_count);

  // Close the file
  fclose(file);

  return EXIT_SUCCESS;
}