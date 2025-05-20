//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORDS 1000

typedef struct {
  char *word;
  int count;
} WordCount;

int compareWordCounts(const void *a, const void *b) {
  return ((WordCount *)a)->count - ((WordCount *)b)->count;
}

int main() {
  FILE *fp;
  char *filename = "text.txt";
  char buffer[256];
  char *words[MAX_WORDS];
  int wordCount[MAX_WORDS];
  int numWords = 0;

  printf("Yay! Let's count some words!\n");

  // Open the file
  if ((fp = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "Oops! Couldn't open the file %s\n", filename);
    return 1;
  }

  // Read the file and count the words
  while (fscanf(fp, "%s", buffer) != EOF) {
    // Convert the buffer to lowercase
    for (int i = 0; i < strlen(buffer); i++) {
      buffer[i] = tolower(buffer[i]);
    }

    // Check if the word is already in the list
    int found = 0;
    for (int i = 0; i < numWords; i++) {
      if (strcmp(buffer, words[i]) == 0) {
        wordCount[i]++;
        found = 1;
        break;
      }
    }

    // If the word is not in the list, add it
    if (!found) {
      words[numWords] = strdup(buffer);
      wordCount[numWords] = 1;
      numWords++;
    }
  }

  // Close the file
  fclose(fp);

  // Sort the words by count
  qsort(words, numWords, sizeof(WordCount), compareWordCounts);

  // Print the top 10 words
  printf("Here are the top 10 words and their counts:\n");
  for (int i = numWords - 1; i >= numWords - 10; i--) {
    printf("%s: %d\n", words[i], wordCount[i]);
  }

  // Free the allocated memory
  for (int i = 0; i < numWords; i++) {
    free(words[i]);
  }

  printf("Yippee! We're done! 😊");
  return 0;
}