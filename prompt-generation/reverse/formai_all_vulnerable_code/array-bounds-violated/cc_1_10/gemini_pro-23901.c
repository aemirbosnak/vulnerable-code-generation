//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum word size
#define MAX_WORD_SIZE 100

// Define the maximum number of words in the dictionary
#define MAX_DICT_SIZE 1000

// Define the dictionary
char *dict[MAX_DICT_SIZE];

// Load the dictionary from a file
void load_dictionary(const char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening dictionary file");
    exit(1);
  }

  char line[MAX_WORD_SIZE];
  int i = 0;
  while (fgets(line, MAX_WORD_SIZE, file)) {
    // Remove the newline character from the end of the word
    line[strlen(line) - 1] = '\0';

    // Add the word to the dictionary
    dict[i++] = strdup(line);
  }

  fclose(file);
}

// Check if a word is in the dictionary
int is_in_dictionary(const char *word) {
  for (int i = 0; i < MAX_DICT_SIZE; i++) {
    if (strcmp(word, dict[i]) == 0) {
      return 1;
    }
  }

  return 0;
}

// Get the closest word in the dictionary to the given word
char *get_closest_word(const char *word) {
  char *closest_word = NULL;
  int closest_distance = MAX_WORD_SIZE;

  for (int i = 0; i < MAX_DICT_SIZE; i++) {
    int distance = levenshtein_distance(word, dict[i]);
    if (distance < closest_distance) {
      closest_distance = distance;
      closest_word = dict[i];
    }
  }

  return closest_word;
}

// Calculate the Levenshtein distance between two words
int levenshtein_distance(const char *word1, const char *word2) {
  int len1 = strlen(word1);
  int len2 = strlen(word2);

  // Create a matrix to store the distances
  int matrix[len1 + 1][len2 + 1];

  // Initialize the first row and column of the matrix
  for (int i = 0; i <= len1; i++) {
    matrix[i][0] = i;
  }
  for (int j = 0; j <= len2; j++) {
    matrix[0][j] = j;
  }

  // Calculate the distances
  for (int i = 1; i <= len1; i++) {
    for (int j = 1; j <= len2; j++) {
      if (word1[i - 1] == word2[j - 1]) {
        matrix[i][j] = matrix[i - 1][j - 1];
      } else {
        matrix[i][j] = 1 + fmin(matrix[i - 1][j - 1], fmin(matrix[i - 1][j], matrix[i][j - 1]));
      }
    }
  }

  // Return the distance
  return matrix[len1][len2];
}

// Print the suggested word
void print_suggestion(const char *word, const char *suggestion) {
  printf("Did you mean \"%s\"?\n", suggestion);
}

// Main function
int main(int argc, char **argv) {
  // Load the dictionary
  load_dictionary("dictionary.txt");

  // Get the word from the user
  char word[MAX_WORD_SIZE];
  printf("Enter a word: ");
  scanf("%s", word);

  // Check if the word is in the dictionary
  if (is_in_dictionary(word)) {
    printf("The word is correct.\n");
  } else {
    // Get the closest word in the dictionary
    char *closest_word = get_closest_word(word);

    // Print the suggested word
    print_suggestion(word, closest_word);
  }

  return 0;
}