//GEMINI-pro DATASET v1.0 Category: Educational ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of characters in a word
#define MAX_WORD_LENGTH 20

// Define the maximum number of words in a sentence
#define MAX_SENTENCE_LENGTH 100

// Define the structure of a word
typedef struct {
  char word[MAX_WORD_LENGTH];
  int length;
} Word;

// Define the structure of a sentence
typedef struct {
  Word words[MAX_SENTENCE_LENGTH];
  int length;
} Sentence;

// Function to get a word from the user
Word get_word() {
  Word word;

  // Get the word from the user
  printf("Enter a word (max %d characters): ", MAX_WORD_LENGTH);
  scanf("%s", word.word);

  // Get the length of the word
  word.length = strlen(word.word);

  // Return the word
  return word;
}

// Function to get a sentence from the user
Sentence get_sentence() {
  Sentence sentence;

  // Get the first word of the sentence
  sentence.words[0] = get_word();

  // Get the rest of the words in the sentence
  int i = 1;
  while (sentence.words[i - 1].length > 0) {
    sentence.words[i] = get_word();
    i++;
  }

  // Get the length of the sentence
  sentence.length = i - 1;

  // Return the sentence
  return sentence;
}

// Function to print a word
void print_word(Word word) {
  // Print the word
  printf("%s", word.word);
}

// Function to print a sentence
void print_sentence(Sentence sentence) {
  // Print the words in the sentence
  for (int i = 0; i < sentence.length; i++) {
    print_word(sentence.words[i]);

    // Print a space after the word
    printf(" ");
  }

  // Print a newline after the sentence
  printf("\n");
}

// Main function
int main() {
  // Get a sentence from the user
  Sentence sentence = get_sentence();

  // Print the sentence
  print_sentence(sentence);

  return 0;
}