//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

// Initialize the dictionary with a few common words
char *dictionary[] = {
  "love", "heart", "passion", "desire", "romance",
  "adore", "cherish", "treasure", "cherub", "cupid",
  "kiss", "hug", "cuddle", "embrace", "snuggle",
  "flower", "chocolate", "candle", "music", "wine"
};

int main() {
  // Get the input text from the user
  char text[1000];
  printf("Enter your romantic text:\n");
  gets(text);

  // Tokenize the input text into words
  char *words[MAX_WORDS];
  int num_words = 0;
  char *token = strtok(text, " ");
  while (token != NULL) {
    words[num_words++] = token;
    token = strtok(NULL, " ");
  }

  // Check each word in the input text against the dictionary
  int misspelled_words = 0;
  for (int i = 0; i < num_words; i++) {
    int found = 0;
    for (int j = 0; j < MAX_WORDS; j++) {
      if (strcmp(words[i], dictionary[j]) == 0) {
        found = 1;
        break;
      }
    }
    if (!found) {
      printf("Misspelled word: %s\n", words[i]);
      misspelled_words++;
    }
  }

  // Display the number of misspelled words
  if (misspelled_words == 0) {
    printf("Your romantic text is perfectly spelled! Congratulations!\n");
  } else {
    printf("Your romantic text contains %d misspelled words.\n", misspelled_words);
  }

  return 0;
}