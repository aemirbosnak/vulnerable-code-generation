//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LENGTH 20
#define MAX_SENTENCE_LENGTH 50

// Global variables
char word[MAX_WORD_LENGTH];
char sentence[MAX_SENTENCE_LENGTH];
int numWords = 0;
int numSentences = 0;

// Function to get a word from the user
void getWord() {
  printf("Enter a word: ");
  fgets(word, MAX_WORD_LENGTH, stdin);
  word[strcspn(word, "\n")] = 0; // Remove newline character
}

// Function to get a sentence from the user
void getSentence() {
  printf("Enter a sentence: ");
  fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
  sentence[strcspn(sentence, "\n")] = 0; // Remove newline character
}

// Function to print the number of words and sentences
void printStats() {
  printf("Number of words: %d\n", numWords);
  printf("Number of sentences: %d\n", numSentences);
}

int main() {
  // Initialize variables
  numWords = 0;
  numSentences = 0;

  // Get a word from the user
  getWord();

  // Print the word and ask for another one
  printf("Great word! Here's a sentence for you: %s\n", sentence);
  printf("Would you like to enter another word? (y/n): ");
  char answer;
  scanf(" %c", &answer);

  // If the user enters "y", continue getting words and sentences
  while (answer == 'y' || answer == 'Y') {
    // Get another word from the user
    getWord();

    // Add the word to the sentence
    strcat(sentence, " ");
    strcat(sentence, word);

    // Increment the number of words and sentences
    numWords++;
    numSentences++;

    // Print the updated sentence and ask for another word
    printf("Here's your updated sentence: %s\n", sentence);
    printf("Would you like to enter another word? (y/n): ");
    scanf(" %c", &answer);
  }

  // Print the final sentence and exit
  printf("Here's your final sentence: %s\n", sentence);
  printStats();
  return 0;
}