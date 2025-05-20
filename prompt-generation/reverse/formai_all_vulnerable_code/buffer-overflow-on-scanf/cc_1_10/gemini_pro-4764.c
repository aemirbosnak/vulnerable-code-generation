//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 255
#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
  char *word;
  int count;
} Word;

int main() {
  // Create an array to store the words in the email
  Word words[MAX_WORDS];

  // Create an array to store the number of occurrences of each word
  int word_counts[MAX_WORDS];

  // Create a variable to store the total number of words in the email
  int total_words = 0;

  // Create a variable to store the total number of spam words in the email
  int spam_words = 0;

  // Read the email from the user
  char email[MAX_EMAIL_LENGTH];
  printf("Enter the email: ");
  scanf("%s", email);

  // Tokenize the email into words
  char *token = strtok(email, " ");
  while (token != NULL) {
    // Check if the word is already in the array
    int found = 0;
    for (int i = 0; i < total_words; i++) {
      if (strcmp(token, words[i].word) == 0) {
        word_counts[i]++;
        found = 1;
        break;
      }
    }

    // If the word is not already in the array, add it to the array
    if (!found) {
      words[total_words].word = strdup(token);
      word_counts[total_words] = 1;
      total_words++;
    }

    // Move to the next token
    token = strtok(NULL, " ");
  }

  // Check each word in the email against the list of spam words
  for (int i = 0; i < total_words; i++) {
    if (is_spam_word(words[i].word)) {
      spam_words++;
    }
  }

  // Print the results
  printf("Total words: %d\n", total_words);
  printf("Spam words: %d\n", spam_words);
  if (spam_words > 0) {
    printf("This email is spam.\n");
  } else {
    printf("This email is not spam.\n");
  }

  // Free the memory allocated for the words
  for (int i = 0; i < total_words; i++) {
    free(words[i].word);
  }

  return 0;
}

// Function to check if a word is a spam word
int is_spam_word(char *word) {
  // Create an array of spam words
  char *spam_words[] = {
    "free",
    "money",
    "win",
    "prize",
    "click",
    "here",
    "offer",
    "sale",
    "discount",
    "guarantee"
  };

  // Check if the word is in the array of spam words
  for (int i = 0; i < sizeof(spam_words) / sizeof(char *); i++) {
    if (strcmp(word, spam_words[i]) == 0) {
      return 1;
    }
  }

  // The word is not a spam word
  return 0;
}