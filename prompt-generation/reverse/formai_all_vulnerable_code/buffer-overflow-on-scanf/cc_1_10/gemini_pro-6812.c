//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dictionary of words
char *dictionary[] = {"apple", "banana", "cherry", "dog", "elephant", "fish", "grape", "horse", "ice cream", "juice"};

// Function to check if a word is in the dictionary
int is_in_dictionary(char *word, int start, int end) {
  if (start > end) {
    return 0;
  }

  int mid = (start + end) / 2;

  if (strcmp(word, dictionary[mid]) == 0) {
    return 1;
  } else if (strcmp(word, dictionary[mid]) < 0) {
    return is_in_dictionary(word, start, mid - 1);
  } else {
    return is_in_dictionary(word, mid + 1, end);
  }
}

// Function to check if a word is spelled correctly
int is_spelled_correctly(char *word) {
  int len = strlen(word);

  if (len == 0) {
    return 0;
  }

  for (int i = 0; i < len; i++) {
    if (!isalpha(word[i])) {
      return 0;
    }
  }

  return is_in_dictionary(word, 0, 9);
}

// Main function
int main() {
  char word[100];

  printf("Enter a word to check: ");
  scanf("%s", word);

  if (is_spelled_correctly(word)) {
    printf("The word is spelled correctly.\n");
  } else {
    printf("The word is not spelled correctly.\n");
  }

  return 0;
}