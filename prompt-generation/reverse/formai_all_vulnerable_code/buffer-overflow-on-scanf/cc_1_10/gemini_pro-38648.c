//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of words in a phrase
#define MAX_WORDS 100

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Define the number of potential spam words
#define NUM_SPAM_WORDS 10

// Define the potential spam words
const char *spam_words[] = {
  "free",
  "money",
  "win",
  "prize",
  "offer",
  "click",
  "now",
  "today",
  "limited",
  "exclusive"
};

// Function to check if a word is a spam word
int is_spam_word(const char *word) {
  for (int i = 0; i < NUM_SPAM_WORDS; i++) {
    if (strcmp(word, spam_words[i]) == 0) {
      return 1;
    }
  }
  return 0;
}

// Function to count the number of spam words in a phrase
int count_spam_words(const char *phrase) {
  int count = 0;
  char *word;
  char *words = strdup(phrase);

  for (word = strtok(words, " "); word; word = strtok(NULL, " ")) {
    if (is_spam_word(word)) {
      count++;
    }
  }

  free(words);
  return count;
}

// Function to check if a phrase is spam
int is_spam(const char *phrase) {
  int num_spam_words = count_spam_words(phrase);
  return num_spam_words >= 3;
}

int main() {
  char phrase[MAX_WORD_LENGTH];
  printf("Enter a phrase: ");
  scanf("%s", phrase);

  if (is_spam(phrase)) {
    printf("Beep boop! That phrase sounds like spam. Please try again.\n");
  } else {
    printf("Great! That phrase doesn't sound like spam. :)\n");
  }

  return 0;
}