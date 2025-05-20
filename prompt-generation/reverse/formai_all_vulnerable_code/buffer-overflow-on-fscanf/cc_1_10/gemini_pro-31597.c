//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 20

// Define the maximum number of words in the dictionary
#define MAX_WORDS 10000

// Create a data structure to store the dictionary
typedef struct {
  char word[MAX_WORD_LENGTH];
  int frequency;
} Word;

// Create an array to store the dictionary
Word dictionary[MAX_WORDS];

// Load the dictionary from a file
void load_dictionary(char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening dictionary file");
    exit(1);
  }

  // Read the words from the file
  int i = 0;
  while (fscanf(file, "%s", dictionary[i].word) != EOF) {
    dictionary[i].frequency = 0;
    i++;
  }

  // Close the file
  fclose(file);
}

// Check if a word is in the dictionary
int is_in_dictionary(char *word) {
  // Linear search for the word in the dictionary
  for (int i = 0; i < MAX_WORDS; i++) {
    if (strcmp(word, dictionary[i].word) == 0) {
      return 1;
    }
  }

  // The word is not in the dictionary
  return 0;
}

// Find the frequency of a word in the dictionary
int get_frequency(char *word) {
  // Linear search for the word in the dictionary
  for (int i = 0; i < MAX_WORDS; i++) {
    if (strcmp(word, dictionary[i].word) == 0) {
      return dictionary[i].frequency;
    }
  }

  // The word is not in the dictionary
  return 0;
}

// Update the frequency of a word in the dictionary
void update_frequency(char *word) {
  // Linear search for the word in the dictionary
  for (int i = 0; i < MAX_WORDS; i++) {
    if (strcmp(word, dictionary[i].word) == 0) {
      dictionary[i].frequency++;
      break;
    }
  }
}

// Check the spelling of a word
int check_spelling(char *word) {
  // Check if the word is in the dictionary
  if (is_in_dictionary(word)) {
    return 1;
  } else {
    // The word is not in the dictionary
    // Find the closest word in the dictionary
    char closest_word[MAX_WORD_LENGTH];
    int min_distance = MAX_WORD_LENGTH;
    for (int i = 0; i < MAX_WORDS; i++) {
      int distance = levenshtein_distance(word, dictionary[i].word);
      if (distance < min_distance) {
        min_distance = distance;
        strcpy(closest_word, dictionary[i].word);
      }
    }

    // Print the closest word
    printf("Did you mean '%s'?\n", closest_word);

    return 0;
  }
}

// Calculate the Levenshtein distance between two words
int levenshtein_distance(char *word1, char *word2) {
  int m = strlen(word1);
  int n = strlen(word2);
  int dp[m + 1][n + 1];

  // Initialize the first row and column of the DP table
  for (int i = 0; i <= m; i++) {
    dp[i][0] = i;
  }
  for (int j = 0; j <= n; j++) {
    dp[0][j] = j;
  }

  // Calculate the rest of the DP table
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      int cost = (word1[i - 1] == word2[j - 1]) ? 0 : 1;
      dp[i][j] = min(dp[i - 1][j] + 1, // Deletion
                     min(dp[i][j - 1] + 1, // Insertion
                          dp[i - 1][j - 1] + cost)); // Substitution
    }
  }

  // Return the last entry in the DP table
  return dp[m][n];
}

// Find the minimum of three numbers
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

// Main function
int main(int argc, char *argv[]) {
  // Load the dictionary from a file
  load_dictionary("dictionary.txt");

  // Check the spelling of a word
  char word[MAX_WORD_LENGTH];
  printf("Enter a word: ");
  scanf("%s", word);
  if (check_spelling(word)) {
    printf("The word is spelled correctly.\n");
  } else {
    printf("The word is spelled incorrectly.\n");
  }

  return 0;
}