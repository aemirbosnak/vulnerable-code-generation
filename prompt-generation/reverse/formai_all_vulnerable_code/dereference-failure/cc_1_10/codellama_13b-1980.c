//Code Llama-13B DATASET v1.0 Category: Text processing ; Style: post-apocalyptic
// A post-apocalyptic text processing program in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_WORD_LEN 32

// Structure to store a word and its count
typedef struct {
  char word[MAX_WORD_LEN];
  int count;
} word_t;

// Function to read a line from stdin and tokenize it
word_t* read_line(char* line) {
  word_t* words = malloc(sizeof(word_t) * MAX_LINE_LEN);
  char* token;
  int i = 0;

  token = strtok(line, " ");
  while (token != NULL) {
    strcpy(words[i].word, token);
    words[i].count = 1;
    i++;
    token = strtok(NULL, " ");
  }

  return words;
}

// Function to sort an array of words by frequency
void sort_words(word_t* words, int len) {
  int i, j;
  word_t temp;

  for (i = 0; i < len - 1; i++) {
    for (j = i + 1; j < len; j++) {
      if (words[i].count < words[j].count) {
        temp = words[i];
        words[i] = words[j];
        words[j] = temp;
      }
    }
  }
}

// Function to print an array of words
void print_words(word_t* words, int len) {
  int i;

  for (i = 0; i < len; i++) {
    printf("%s: %d\n", words[i].word, words[i].count);
  }
}

int main() {
  char line[MAX_LINE_LEN];
  word_t* words;
  int len;

  // Read a line from stdin
  fgets(line, MAX_LINE_LEN, stdin);

  // Tokenize the line and store the words in an array
  words = read_line(line);
  len = strlen(line);

  // Sort the array of words by frequency
  sort_words(words, len);

  // Print the sorted array of words
  print_words(words, len);

  // Free the memory allocated for the array of words
  free(words);

  return 0;
}