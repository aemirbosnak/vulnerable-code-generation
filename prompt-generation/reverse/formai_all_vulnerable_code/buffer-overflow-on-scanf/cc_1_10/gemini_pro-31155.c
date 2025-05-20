//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  // Welcome the user to the futuristic spell checker.
  printf("Welcome to the futuristic spell checker!\n");
  
  // Get the input from the user.
  char input[100];
  printf("Enter a word: ");
  scanf("%s", input);

  // Create a dictionary of known words.
  char *dictionary[] = {"hello", "world", "computer", "science", "future", "technology"};

  // Check if the input word is in the dictionary.
  int found = 0;
  for (int i = 0; i < sizeof(dictionary) / sizeof(char *); i++) {
    if (strcmp(input, dictionary[i]) == 0) {
      found = 1;
      break;
    }
  }

  // If the word is in the dictionary, print a message.
  if (found) {
    printf("The word '%s' is spelled correctly.\n", input);
  }

  // If the word is not in the dictionary, suggest some corrections.
  else {
    printf("The word '%s' is not spelled correctly.\n", input);
    printf("Here are some suggestions:\n");

    // Generate a list of possible corrections.
    int corrections = 0;
    for (int i = 0; i < sizeof(dictionary) / sizeof(char *); i++) {
      int distance = levenshtein(input, dictionary[i]);
      if (distance <= 2) {
        printf("%s\n", dictionary[i]);
        corrections++;
      }
    }

    // If no corrections were found, print a message.
    if (corrections == 0) {
      printf("No corrections found.\n");
    }
  }

  return 0;
}

// Compute the Levenshtein distance between two strings.
int levenshtein(char *a, char *b) {
  int m = strlen(a);
  int n = strlen(b);

  int matrix[m + 1][n + 1];

  // Initialize the matrix.
  for (int i = 0; i <= m; i++) {
    matrix[i][0] = i;
  }
  for (int j = 0; j <= n; j++) {
    matrix[0][j] = j;
  }

  // Compute the Levenshtein distance.
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      int cost = (a[i - 1] == b[j - 1]) ? 0 : 1;
      matrix[i][j] = min(
          matrix[i - 1][j] + 1,  // Deletion
          matrix[i][j - 1] + 1,  // Insertion
          matrix[i - 1][j - 1] + cost  // Substitution
      );
    }
  }

  return matrix[m][n];
}

// Compute the minimum of three integers.
int min(int a, int b, int c) {
  int min = a;
  if (b < min) {
    min = b;
  }
  if (c < min) {
    min = c;
  }
  return min;
}