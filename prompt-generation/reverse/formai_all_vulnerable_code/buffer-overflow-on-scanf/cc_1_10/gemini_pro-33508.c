//GEMINI-pro DATASET v1.0 Category: Educational ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of characters in a word
#define MAX_WORD_LENGTH 100

// Define the maximum number of words in a sentence
#define MAX_SENTENCE_LENGTH 1000

// Define the maximum number of sentences in a paragraph
#define MAX_PARAGRAPH_LENGTH 10000

// Get a word from the user
char *get_word() {
  char *word = malloc(MAX_WORD_LENGTH);
  scanf("%s", word);
  return word;
}

// Get a sentence from the user
char *get_sentence() {
  char *sentence = malloc(MAX_SENTENCE_LENGTH);
  scanf("%[^\n]%*c", sentence);
  return sentence;
}

// Get a paragraph from the user
char *get_paragraph() {
  char *paragraph = malloc(MAX_PARAGRAPH_LENGTH);
  scanf("%[^\n]%*c", paragraph);
  return paragraph;
}

// Print a word
void print_word(char *word) {
  printf("%s", word);
}

// Print a sentence
void print_sentence(char *sentence) {
  printf("%s", sentence);
}

// Print a paragraph
void print_paragraph(char *paragraph) {
  printf("%s", paragraph);
}

// Main function
int main() {
  // Get a word from the user
  char *word = get_word();

  // Print the word
  print_word(word);

  // Get a sentence from the user
  char *sentence = get_sentence();

  // Print the sentence
  print_sentence(sentence);

  // Get a paragraph from the user
  char *paragraph = get_paragraph();

  // Print the paragraph
  print_paragraph(paragraph);

  return 0;
}