//Code Llama-13B DATASET v1.0 Category: Spam Detection System ; Style: Alan Turing
// C Spam Detection System in Alan Turing style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert a string to lowercase
void toLowerCase(char *str) {
  int i = 0;
  while (str[i] != '\0') {
    str[i] = tolower(str[i]);
    i++;
  }
}

// Function to remove non-alphanumeric characters from a string
void removeNonAlphanumeric(char *str) {
  int i = 0, j = 0;
  while (str[i] != '\0') {
    if (isalnum(str[i])) {
      str[j++] = str[i];
    }
    i++;
  }
  str[j] = '\0';
}

// Function to check if a string contains a spam word
int containsSpamWord(char *str) {
  char *spamWords[] = { "viagra", "pills", "phentermine", "cialis", "tramadol", "percocet" };
  int i = 0;
  while (spamWords[i] != NULL) {
    if (strstr(str, spamWords[i]) != NULL) {
      return 1;
    }
    i++;
  }
  return 0;
}

int main() {
  char input[1000];
  printf("Enter a message: ");
  fgets(input, 1000, stdin);

  // Convert input to lowercase and remove non-alphanumeric characters
  toLowerCase(input);
  removeNonAlphanumeric(input);

  // Check if input contains a spam word
  if (containsSpamWord(input)) {
    printf("Spam detected!\n");
  } else {
    printf("No spam detected.\n");
  }

  return 0;
}