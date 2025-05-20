//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of words in a sentence
#define MAX_WORDS 100

// Define the maximum length of a word
#define MAX_WORD_LENGTH 20

// Create a structure to store a word
typedef struct {
  char word[MAX_WORD_LENGTH];
  int count;
} Word;

// Create a function to compare two words
int compareWords(const void *a, const void *b) {
  return strcmp(((Word *)a)->word, ((Word *)b)->word);
}

// Create a function to count the number of words in a sentence
int countWords(char *sentence) {
  int count = 0;
  char *word = strtok(sentence, " ");
  while (word != NULL) {
    count++;
    word = strtok(NULL, " ");
  }
  return count;
}

// Create a function to count the number of occurrences of each word in a sentence
void countOccurrences(char *sentence, Word *words) {
  int numWords = countWords(sentence);
  char *word = strtok(sentence, " ");
  while (word != NULL) {
    int found = 0;
    for (int i = 0; i < numWords; i++) {
      if (strcmp(word, words[i].word) == 0) {
        words[i].count++;
        found = 1;
        break;
      }
    }
    if (!found) {
      strcpy(words[numWords].word, word);
      words[numWords].count = 1;
      numWords++;
    }
    word = strtok(NULL, " ");
  }
}

// Create a function to print the words and their counts
void printWords(Word *words, int numWords) {
  // Sort the words in alphabetical order
  qsort(words, numWords, sizeof(Word), compareWords);

  // Print the words and their counts
  for (int i = 0; i < numWords; i++) {
    printf("%s: %d\n", words[i].word, words[i].count);
  }
}

// Main function
int main() {
  // Get the sentence from the user
  char sentence[1000];
  printf("Enter a sentence: ");
  gets(sentence);

  // Create an array of words to store the words and their counts
  Word words[MAX_WORDS];

  // Count the number of occurrences of each word in the sentence
  countOccurrences(sentence, words);

  // Print the words and their counts
  printWords(words, countWords(sentence));

  return 0;
}