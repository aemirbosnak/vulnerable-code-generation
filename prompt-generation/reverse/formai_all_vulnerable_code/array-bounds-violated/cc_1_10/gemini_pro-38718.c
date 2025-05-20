//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

// The dictionary of words
char *dictionary[MAX_WORDS];

// The number of words in the dictionary
int num_words = 0;

// Loads the dictionary from a file
void load_dictionary(char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening dictionary file");
    exit(1);
  }

  char line[MAX_WORD_LENGTH];
  while (fgets(line, MAX_WORD_LENGTH, file) != NULL) {
    // Remove the newline character from the end of the word
    line[strlen(line) - 1] = '\0';

    // Add the word to the dictionary
    dictionary[num_words++] = strdup(line);
  }

  fclose(file);
}

// Checks if a word is in the dictionary
int is_in_dictionary(char *word) {
  for (int i = 0; i < num_words; i++) {
    if (strcmp(word, dictionary[i]) == 0) {
      return 1;
    }
  }

  return 0;
}

// Corrects a word by finding the closest word in the dictionary
char *correct_word(char *word) {
  // Find the closest word in the dictionary
  char *closest_word = NULL;
  int closest_distance = MAX_WORD_LENGTH;
  for (int i = 0; i < num_words; i++) {
    int distance = levenshtein_distance(word, dictionary[i]);
    if (distance < closest_distance) {
      closest_word = dictionary[i];
      closest_distance = distance;
    }
  }

  return closest_word;
}

// Computes the Levenshtein distance between two strings
int levenshtein_distance(char *s1, char *s2) {
  int m = strlen(s1);
  int n = strlen(s2);

  // Create a matrix to store the distances
  int matrix[m + 1][n + 1];

  // Initialize the first row and column of the matrix
  for (int i = 0; i <= m; i++) {
    matrix[i][0] = i;
  }
  for (int j = 0; j <= n; j++) {
    matrix[0][j] = j;
  }

  // Compute the rest of the matrix
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        matrix[i][j] = matrix[i - 1][j - 1];
      } else {
        matrix[i][j] = 1 + min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]);
      }
    }
  }

  // Return the distance
  return matrix[m][n];
}

// Finds the minimum of three integers
int min(int a, int b, int c) {
  if (a < b && a < c) {
    return a;
  } else if (b < a && b < c) {
    return b;
  } else {
    return c;
  }
}

// Main function
int main(int argc, char *argv[]) {
  // Load the dictionary
  load_dictionary("dictionary.txt");

  // Get the word to be corrected
  char word[MAX_WORD_LENGTH];
  printf("Enter a word to be corrected: ");
  scanf("%s", word);

  // Check if the word is in the dictionary
  if (is_in_dictionary(word)) {
    printf("The word is spelled correctly.\n");
  } else {
    // Correct the word
    char *corrected_word = correct_word(word);

    // Print the corrected word
    printf("The corrected word is: %s\n", corrected_word);
  }

  return 0;
}