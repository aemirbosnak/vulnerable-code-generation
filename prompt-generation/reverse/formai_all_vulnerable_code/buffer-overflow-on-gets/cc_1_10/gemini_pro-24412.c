//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of characters in a word
#define MAX_WORD_LENGTH 100

// Define the maximum number of words in a sentence
#define MAX_SENTENCE_LENGTH 1000

// Define the maximum number of sentences in a paragraph
#define MAX_PARAGRAPH_LENGTH 10000

// Function to count the number of words in a sentence
int count_words(char *sentence) {
  // Initialize the word count to 0
  int word_count = 0;

  // Split the sentence into words
  char *words[MAX_WORD_LENGTH];
  int num_words = 0;
  for (char *word = strtok(sentence, " "); word != NULL; word = strtok(NULL, " ")) {
    words[num_words++] = word;
  }

  // Count the number of words
  for (int i = 0; i < num_words; i++) {
    word_count++;
  }

  // Return the word count
  return word_count;
}

// Function to count the number of sentences in a paragraph
int count_sentences(char *paragraph) {
  // Initialize the sentence count to 0
  int sentence_count = 0;

  // Split the paragraph into sentences
  char *sentences[MAX_SENTENCE_LENGTH];
  int num_sentences = 0;
  for (char *sentence = strtok(paragraph, "."); sentence != NULL; sentence = strtok(NULL, ".")) {
    sentences[num_sentences++] = sentence;
  }

  // Count the number of sentences
  for (int i = 0; i < num_sentences; i++) {
    sentence_count++;
  }

  // Return the sentence count
  return sentence_count;
}

// Function to count the number of paragraphs in a text
int count_paragraphs(char *text) {
  // Initialize the paragraph count to 0
  int paragraph_count = 0;

  // Split the text into paragraphs
  char *paragraphs[MAX_PARAGRAPH_LENGTH];
  int num_paragraphs = 0;
  for (char *paragraph = strtok(text, "\n"); paragraph != NULL; paragraph = strtok(NULL, "\n")) {
    paragraphs[num_paragraphs++] = paragraph;
  }

  // Count the number of paragraphs
  for (int i = 0; i < num_paragraphs; i++) {
    paragraph_count++;
  }

  // Return the paragraph count
  return paragraph_count;
}

// Main function
int main() {
  // Get the text from the user
  char text[MAX_PARAGRAPH_LENGTH];
  printf("Enter the text: ");
  gets(text);

  // Count the number of words, sentences, and paragraphs in the text
  int word_count = count_words(text);
  int sentence_count = count_sentences(text);
  int paragraph_count = count_paragraphs(text);

  // Print the results
  printf("The text contains %d words, %d sentences, and %d paragraphs.\n", word_count, sentence_count, paragraph_count);

  return 0;
}