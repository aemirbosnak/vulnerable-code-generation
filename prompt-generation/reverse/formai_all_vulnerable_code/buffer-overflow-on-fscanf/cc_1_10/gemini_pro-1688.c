//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

// Define the dictionary
char *dictionary[MAX_WORDS];

// Initialize the dictionary
void init_dictionary() {
  FILE *f = fopen("dictionary.txt", "r");
  if (f == NULL) {
    perror("Error opening dictionary file");
    exit(1);
  }

  int i = 0;
  while (fscanf(f, "%s", dictionary[i]) != EOF) {
    i++;
  }

  fclose(f);
}

// Check if a word is in the dictionary
int is_in_dictionary(char *word) {
  for (int i = 0; i < MAX_WORDS; i++) {
    if (strcmp(word, dictionary[i]) == 0) {
      return 1;
    }
  }

  return 0;
}

// Find the closest word in the dictionary to a given word
char *find_closest_word(char *word) {
  int min_distance = strlen(word);
  char *closest_word = NULL;

  for (int i = 0; i < MAX_WORDS; i++) {
    int distance = levenshtein_distance(word, dictionary[i]);
    if (distance < min_distance) {
      min_distance = distance;
      closest_word = dictionary[i];
    }
  }

  return closest_word;
}

// Calculate the Levenshtein distance between two strings
int levenshtein_distance(char *s1, char *s2) {
  int m = strlen(s1);
  int n = strlen(s2);

  int d[m + 1][n + 1];

  for (int i = 0; i <= m; i++) {
    d[i][0] = i;
  }

  for (int j = 0; j <= n; j++) {
    d[0][j] = j;
  }

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        d[i][j] = d[i - 1][j - 1];
      } else {
        d[i][j] = 1 + min(d[i - 1][j - 1], min(d[i - 1][j], d[i][j - 1]));
      }
    }
  }

  return d[m][n];
}

// Find the minimum of three integers
int min(int a, int b, int c) {
  if (a < b) {
    if (a < c) {
      return a;
    } else {
      return c;
    }
  } else {
    if (b < c) {
      return b;
    } else {
      return c;
    }
  }
}

// Main function
int main() {
  // Initialize the dictionary
  init_dictionary();

  // Get the input word from the user
  char word[MAX_WORD_LENGTH];
  printf("Enter a word: ");
  scanf("%s", word);

  // Check if the word is in the dictionary
  if (is_in_dictionary(word)) {
    printf("The word is spelled correctly.\n");
  } else {
    // Find the closest word in the dictionary
    char *closest_word = find_closest_word(word);

    // Print the closest word
    printf("The closest word in the dictionary is: %s\n", closest_word);
  }

  return 0;
}