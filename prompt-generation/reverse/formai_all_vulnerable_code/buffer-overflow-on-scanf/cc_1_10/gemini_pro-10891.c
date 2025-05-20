//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h> // For power function

#define MAX_WORDS 1000

// Structure to represent a word and its count
typedef struct {
  char word[100];
  int count;
} WordCount;

// Function to compare two WordCount structures
int compareWordCount(const void *a, const void *b) {
  WordCount *wc1 = (WordCount *)a;
  WordCount *wc2 = (WordCount *)b;

  // Sort in descending order of count
  return wc2->count - wc1->count;
}

int main() {
  // Initialize variables
  FILE *file;
  char filename[100];
  char word[100];
  WordCount wordCounts[MAX_WORDS];
  int numWords = 0;
  int i, j;

  // Get the filename from the user
  printf("Enter the name of the file to be processed: ");
  scanf("%s", filename);

  // Open the file
  file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  // Read the file and count the words
  while (fscanf(file, "%s", word) != EOF) {
    // Check if the word is already in the list
    for (i = 0; i < numWords; i++) {
      if (strcmp(word, wordCounts[i].word) == 0) {
        // If the word is already in the list, increment its count
        wordCounts[i].count++;
        break;
      }
    }

    // If the word is not in the list, add it to the list
    if (i == numWords) {
      strcpy(wordCounts[numWords].word, word);
      wordCounts[numWords].count = 1;
      numWords++;
    }
  }

  // Close the file
  fclose(file);

  // Sort the list of words by count
  qsort(wordCounts, numWords, sizeof(WordCount), compareWordCount);

  // Print the list of words and their counts
  printf("Word Count\n");
  printf("----------\n");
  for (i = 0; i < numWords; i++) {
    printf("%s %d\n", wordCounts[i].word, wordCounts[i].count);
  }

  // Calculate the Zipf exponent
  double zipfExponent = 0;
  for (i = 0; i < numWords; i++) {
    zipfExponent += log10(wordCounts[i].count) * log10(i + 1);
  }
  zipfExponent /= log10(numWords);

  // Print the Zipf exponent
  printf("\nZipf exponent: %.2f\n", zipfExponent);

  return 0;
}