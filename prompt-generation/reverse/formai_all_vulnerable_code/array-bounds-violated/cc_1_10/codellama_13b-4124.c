//Code Llama-13B DATASET v1.0 Category: Word Frequency Counter ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Struct to store word and its frequency
struct Word {
  char *word;
  int frequency;
};

// Function to sort array of words by frequency
void sort_words(struct Word *words, int n) {
  // Bubble sort algorithm
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      if (words[j].frequency > words[j + 1].frequency) {
        struct Word temp = words[j];
        words[j] = words[j + 1];
        words[j + 1] = temp;
      }
    }
  }
}

// Function to count the frequency of each word in a given string
int count_frequency(struct Word *words, char *str, int n) {
  // Split the string into individual words
  char *word = strtok(str, " ");

  // Iterate through each word and increment its frequency
  while (word != NULL) {
    for (int i = 0; i < n; i++) {
      if (strcmp(words[i].word, word) == 0) {
        words[i].frequency++;
        break;
      }
    }
    word = strtok(NULL, " ");
  }

  return n;
}

int main() {
  // Get input string from user
  char str[100];
  printf("Enter a sentence: ");
  fgets(str, 100, stdin);

  // Remove newline character from the end of the string
  str[strlen(str) - 1] = '\0';

  // Create an array of words and their frequencies
  struct Word words[100];
  int n = 0;
  for (int i = 0; i < 100; i++) {
    words[i].word = (char *)malloc(100 * sizeof(char));
    words[i].frequency = 0;
  }

  // Count the frequency of each word in the string
  n = count_frequency(words, str, n);

  // Sort the array of words by frequency
  sort_words(words, n);

  // Print the top 10 most frequent words
  for (int i = 0; i < 10; i++) {
    printf("%s - %d\n", words[i].word, words[i].frequency);
  }

  return 0;
}