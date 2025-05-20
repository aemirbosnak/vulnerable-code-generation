//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: high level of detail
#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_WORDS 1000

int main() {

  char word[MAX_WORD_LEN]; 
  int i, j, freq, wordCount = 0;

  // create an array to store all the words
  char words[MAX_WORDS][MAX_WORD_LEN];

  // prompt the user to enter a sentence
  printf("Enter a sentence: ");

  // read the input sentence from the user
  while (scanf("%s", word) == 1) {

    // strip non-alphabetic characters from the input word
    for (i = 0, j = 0; word[i] != '\0'; i++) {
      if (isalpha(word[i]))
        word[j++] = tolower(word[i]);
    }

    // null-terminate the word
    word[j] = '\0';

    // if the word is not null, add it to the list of words
    if (j > 0) {
      for (i = 0; i < wordCount; i++) {
        // if the word already exists in the list
        if (strcmp(words[i], word) == 0) {
          freq++;
          break;
        }
      }

      // if the word does not exist in the list, add it
      if (i == wordCount) {
        strcpy(words[i], word);
        freq = 1;
        wordCount++;
      }
    }
  }

  // print the word frequency table
  printf("\nWord frequency table:\n");

  for (i = 0; i < wordCount; i++) {
    printf("%s \t\t %d\n", words[i], freq);
  }

  return 0;
}