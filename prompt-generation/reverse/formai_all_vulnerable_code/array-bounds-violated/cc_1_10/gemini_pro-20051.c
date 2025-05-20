//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of words in the input file
#define MAX_WORDS 1000

// Define the maximum length of a word in the input file
#define MAX_WORD_LENGTH 50

// Define the structure of a word
typedef struct word {
  char word[MAX_WORD_LENGTH];
  int count;
} word;

// Define the comparison function for qsort()
int compareWords(const void *a, const void *b) {
  const word *word1 = (const word *)a;
  const word *word2 = (const word *)b;

  return strcmp(word1->word, word2->word);
}

// Read the words from the input file and store them in an array
void readWords(char *filename, word **words, int *numWords) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening input file");
    exit(EXIT_FAILURE);
  }

  char line[MAX_WORD_LENGTH];
  while (fgets(line, MAX_WORD_LENGTH, file) != NULL) {
    // Remove the newline character from the end of the line
    line[strlen(line) - 1] = '\0';

    // Allocate memory for the new word
    word *newWord = malloc(sizeof(word));
    if (newWord == NULL) {
      perror("Error allocating memory for new word");
      exit(EXIT_FAILURE);
    }

    // Copy the word into the new word structure
    strcpy(newWord->word, line);

    // Initialize the count of the new word to 1
    newWord->count = 1;

    // Add the new word to the array of words
    words[*numWords] = newWord;
    (*numWords)++;
  }

  fclose(file);
}

// Count the number of occurrences of each word in the array of words
void countWords(word **words, int numWords) {
  for (int i = 0; i < numWords; i++) {
    for (int j = i + 1; j < numWords; j++) {
      if (strcmp(words[i]->word, words[j]->word) == 0) {
        // The two words are the same, so increment the count of the first word
        words[i]->count++;

        // Remove the second word from the array
        for (int k = j; k < numWords - 1; k++) {
          words[k] = words[k + 1];
        }

        numWords--;

        // Decrement the index of the outer loop to account for the removed word
        j--;
      }
    }
  }
}

// Sort the array of words in alphabetical order
void sortWords(word **words, int numWords) {
  qsort(words, numWords, sizeof(word *), compareWords);
}

// Print the top 10 most frequently occurring words in the input file
void printTop10Words(word **words, int numWords) {
  printf("The top 10 most frequently occurring words in the input file are:\n");
  for (int i = 0; i < 10 && i < numWords; i++) {
    printf("%s: %d\n", words[i]->word, words[i]->count);
  }
}

// Free the memory allocated for the array of words
void freeWords(word **words, int numWords) {
  for (int i = 0; i < numWords; i++) {
    free(words[i]);
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <input file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Allocate memory for the array of words
  word **words = malloc(sizeof(word *) * MAX_WORDS);
  if (words == NULL) {
    perror("Error allocating memory for array of words");
    exit(EXIT_FAILURE);
  }

  // Initialize the number of words to 0
  int numWords = 0;

  // Read the words from the input file
  readWords(argv[1], words, &numWords);

  // Count the number of occurrences of each word
  countWords(words, numWords);

  // Sort the array of words in alphabetical order
  sortWords(words, numWords);

  // Print the top 10 most frequently occurring words
  printTop10Words(words, numWords);

  // Free the memory allocated for the array of words
  freeWords(words, numWords);

  return EXIT_SUCCESS;
}