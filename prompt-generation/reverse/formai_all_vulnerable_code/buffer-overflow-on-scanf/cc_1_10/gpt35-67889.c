//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 50
#define MAX_LENGTH 20

int main() {
  printf("Welcome to the Post-Apocalyptic Word Frequency Counter!\n\n");
  printf("Please enter your words below:\n");

  char words[MAX_WORDS][MAX_LENGTH];
  int frequency[MAX_WORDS] = {0};

  // read in the words
  int word_count = 0;
  while (word_count < MAX_WORDS) {
    char word[MAX_LENGTH];
    scanf("%s", word);

    // check for end of input
    if (strcmp(word, "exit") == 0) {
      break;
    }

    // check for word length
    if (strlen(word) > MAX_LENGTH) {
      printf("Your word '%s' is too long!\nPlease enter a word that is less than 20 characters.\n\n", word);
      continue;
    }

    // add the word to the array
    strcpy(words[word_count], word);
    word_count++;
  }

  // count the frequency of each word
  for (int i = 0; i < word_count; i++) {
    // skip already counted words
    if (frequency[i] != 0) {
      continue;
    }

    frequency[i] = 1;
    for (int j = i + 1; j < word_count; j++) {
      if (strcmp(words[i], words[j]) == 0) {
        frequency[i]++;
        frequency[j] = -1;
      }
    }
  }

  // print out the word frequency
  printf("\nWord Frequency:\n");
  for (int i = 0; i < word_count; i++) {
    if (frequency[i] != -1) {
      printf("%s - %d\n", words[i], frequency[i]);
    }
  }

  return 0;
}