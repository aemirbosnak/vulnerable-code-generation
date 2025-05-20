//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define WORD_COUNT_MAX 100000

// Global variables
int word_count = 0;
int longest_word = 0;
int average_word_length = 0;

// Function declarations
void get_words(const char* str, int* word_count_out, int* longest_word_out);
void print_stats(int word_count, int longest_word, int average_word_length);

int main() {
  // Example usage: ./word_count_tool "Hello World!"
  char str[100];
  gets(str); // Read input string from user

  int word_count_local = 0;
  int longest_word_local = 0;

  get_words(str, &word_count_local, &longest_word_local);

  word_count = word_count_local;
  longest_word = longest_word_local;
  average_word_length = (word_count > 0) ? (word_count_local / word_count) : 0;

  print_stats(word_count, longest_word, average_word_length);

  return 0;
}

void get_words(const char* str, int* word_count_out, int* longest_word_out) {
  char word[100];
  int i = 0;

  // Loop through each character in the input string
  for (; *str != '\0'; str++) {
    // Check if current character is a word boundary
    if (isspace(*str)) {
      // If it is, increment word count and reset longest word
      (*word_count_out)++;
      longest_word = 0;
    }

    // If current character is not a word boundary,
    // check if it is the start of a new word
    if (!isspace(*str) && !word[i]) {
      // If it is, record the start of the new word
      word[i] = *str;
      i++;

      // If the current word is longer than the previous longest word,
      // update the longest word and its index
      if (i > longest_word) {
        longest_word = i;
        word_count = 0;
      }
    }

    // If the current character is the end of the word,
    // increment the word count and reset the longest word
    if (*str == ' ' || *str == '\0') {
      word_count++;
      longest_word = 0;
    }
  }

  // Return the word count and longest word
  *word_count_out = word_count;
  *longest_word_out = longest_word;
}

void print_stats(int word_count, int longest_word, int average_word_length) {
  printf("Word Count: %d\n", word_count);
  printf("Longest Word: %s (%d characters)\n", longest_word, longest_word);
  printf("Average Word Length: %d\n", average_word_length);
}