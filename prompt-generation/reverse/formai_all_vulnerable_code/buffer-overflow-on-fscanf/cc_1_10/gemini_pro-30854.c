//GEMINI-pro DATASET v1.0 Category: File handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to hold a word and its count
typedef struct {
  char word[50];
  int count;
} WordCount;

// A function to compare two WordCount structures
int compareWordCount(const void *a, const void *b) {
  WordCount *wa = (WordCount *)a;
  WordCount *wb = (WordCount *)b;
  return strcmp(wa->word, wb->word);
}

// A function to print the top 10 most frequently used words in a file
void printTop10Words(FILE *file) {
  // Create an array to store the word counts
  WordCount wordCounts[10000];
  int wordCountIndex = 0;

  // Read the file and count the occurrences of each word
  char word[50];
  int *count;
  while (fscanf(file, "%s", word) != EOF) {
    // Check if the word is already in the array
    count = bsearch(&word, wordCounts, wordCountIndex, sizeof(WordCount), compareWordCount);
    if (count != NULL) {
      // The word is already in the array, so increment its count
      (*count)++;
    } else {
      // The word is not in the array, so add it to the array
      strcpy(wordCounts[wordCountIndex].word, word);
      wordCounts[wordCountIndex].count = 1;
      wordCountIndex++;
    }
  }

  // Sort the array by word count
  qsort(wordCounts, wordCountIndex, sizeof(WordCount), compareWordCount);

  // Print the top 10 most frequently used words
  printf("The top 10 most frequently used words in the file are:\n");
  for (int i = 0; i < 10 && i < wordCountIndex; i++) {
    printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
  }
}

// The main function
int main() {
  // Open the file
  FILE *file = fopen("text.txt", "r");
  if (file == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  // Print the top 10 most frequently used words in the file
  printTop10Words(file);

  // Close the file
  fclose(file);

  return EXIT_SUCCESS;
}