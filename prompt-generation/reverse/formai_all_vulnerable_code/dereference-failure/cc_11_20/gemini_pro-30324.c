//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Spam detection system
int main() {
  // Get the input from the user
  char *input = (char *) malloc(1024);
  printf("Enter the text you want to check: ");
  gets(input);

  // Check for common spam words
  char *spamWords[] = {"free", "money", "click", "win", "prize", "urgent", "limited time offer"};
  int numSpamWords = 7;
  int numSpamWordsFound = 0;
  for (int i = 0; i < numSpamWords; i++) {
    if (strstr(input, spamWords[i]) != NULL) {
      numSpamWordsFound++;
    }
  }

  // Check for repeated words
  char *words[1024];
  int numWords = 0;
  char *token = strtok(input, " ");
  while (token != NULL) {
    words[numWords] = token;
    numWords++;
    token = strtok(NULL, " ");
  }
  int numRepeatedWords = 0;
  for (int i = 0; i < numWords; i++) {
    for (int j = i + 1; j < numWords; j++) {
      if (strcmp(words[i], words[j]) == 0) {
        numRepeatedWords++;
      }
    }
  }

  // Check for excessive punctuation
  int numPunctuationMarks = 0;
  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == '.' || input[i] == ',' || input[i] == '!' || input[i] == '?' || input[i] == ':') {
      numPunctuationMarks++;
    }
  }

  // Check for excessive capital letters
  int numCapitalLetters = 0;
  for (int i = 0; i < strlen(input); i++) {
    if (input[i] >= 'A' && input[i] <= 'Z') {
      numCapitalLetters++;
    }
  }

  // Check for excessive white space
  int numWhiteSpaceCharacters = 0;
  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == ' ' || input[i] == '\t' || input[i] == '\n') {
      numWhiteSpaceCharacters++;
    }
  }

  // Calculate the spam score
  int spamScore = numSpamWordsFound + numRepeatedWords + numPunctuationMarks + numCapitalLetters + numWhiteSpaceCharacters;

  // Print the spam score
  printf("Spam score: %d\n", spamScore);

  // Free the allocated memory
  free(input);

  return 0;
}