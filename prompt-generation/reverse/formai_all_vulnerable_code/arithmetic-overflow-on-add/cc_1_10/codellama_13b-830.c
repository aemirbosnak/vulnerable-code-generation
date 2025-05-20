//Code Llama-13B DATASET v1.0 Category: Word Frequency Counter ; Style: configurable
// Word Frequency Counter
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Customizable parameters
#define MAX_LINE_LEN 1024
#define MAX_WORD_LEN 64
#define MAX_WORDS 1024

// Global variables
char *words[MAX_WORDS];
int word_count = 0;

// Function to count the frequency of a word
void count_word(char *word) {
  for (int i = 0; i < word_count; i++) {
    if (strcmp(word, words[i]) == 0) {
      words[i][MAX_WORD_LEN - 1]++;
      return;
    }
  }
  words[word_count++] = word;
}

// Function to print the word frequency table
void print_table() {
  for (int i = 0; i < word_count; i++) {
    printf("%s: %d\n", words[i], words[i][MAX_WORD_LEN - 1]);
  }
}

// Main function
int main(int argc, char *argv[]) {
  // Initialize the word count to 0
  word_count = 0;

  // Read each line from the input
  char line[MAX_LINE_LEN];
  while (fgets(line, MAX_LINE_LEN, stdin) != NULL) {
    // Remove the newline character at the end of the line
    line[strcspn(line, "\n")] = '\0';

    // Split the line into words
    char *word = strtok(line, " ");
    while (word != NULL) {
      count_word(word);
      word = strtok(NULL, " ");
    }
  }

  // Print the word frequency table
  print_table();

  return 0;
}