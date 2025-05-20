//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_SPAM_WORDS 50

// Function to check if a word is a spam word
int isSpamWord(char *word) {
  char *spamWords[] = {"free", "offer", "discount", "sale", "click here"};
  int i;

  for (i = 0; i < MAX_SPAM_WORDS; i++) {
    if (strcmp(word, spamWords[i]) == 0) {
      return 1;
    }
  }

  return 0;
}

// Function to count the number of spam words in a string
int countSpamWords(char *str) {
  char *words[MAX_WORDS];
  int i, count = 0;

  // Split the string into words
  char *ptr = strtok(str, " ");
  while (ptr != NULL) {
    words[i++] = ptr;
    ptr = strtok(NULL, " ");
  }

  // Count the number of spam words
  for (i = 0; i < MAX_WORDS; i++) {
    if (isSpamWord(words[i])) {
      count++;
    }
  }

  return count;
}

// Function to check if a string is spam
int isSpam(char *str) {
  int spamCount = countSpamWords(str);

  // If the number of spam words is greater than or equal to 3, the string is considered spam
  if (spamCount >= 3) {
    return 1;
  }

  return 0;
}

int main() {
  char str[100];

  // Get the input string
  printf("Enter a string: ");
  gets(str);

  // Check if the string is spam
  if (isSpam(str)) {
    printf("The string is spam.\n");
  } else {
    printf("The string is not spam.\n");
  }

  return 0;
}