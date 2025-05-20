//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum word length
#define MAX_WORD_LENGTH 20

// Load the dictionary into memory
char *dictionary[] = {"apple", "banana", "cat", "dog", "elephant", "fish", "grape", "house", "ice cream", "juice", "kiwi", "lemon", "mango", "nut", "orange", "peach", "pear", "pineapple", "queen", "rabbit", "strawberry", "tiger", "umbrella", "violin", "watermelon", "x-ray", "yacht", "zebra"};

// Check if a word is in the dictionary
int is_word_in_dictionary(char *word) {
  for (int i = 0; i < sizeof(dictionary) / sizeof(char *); i++) {
    if (strcmp(word, dictionary[i]) == 0) {
      return 1;
    }
  }
  return 0;
}

// Get the closest word in the dictionary to a given word
char *get_closest_word_in_dictionary(char *word) {
  int min_distance = strlen(word);
  char *closest_word = NULL;

  for (int i = 0; i < sizeof(dictionary) / sizeof(char *); i++) {
    int distance = levenshtein_distance(word, dictionary[i]);
    if (distance < min_distance) {
      min_distance = distance;
      closest_word = dictionary[i];
    }
  }

  return closest_word;
}

// Calculate the Levenshtein distance between two words
int levenshtein_distance(char *word1, char *word2) {
  int len1 = strlen(word1);
  int len2 = strlen(word2);

  int matrix[len1 + 1][len2 + 1];

  for (int i = 0; i <= len1; i++) {
    matrix[i][0] = i;
  }

  for (int j = 0; j <= len2; j++) {
    matrix[0][j] = j;
  }

  for (int i = 1; i <= len1; i++) {
    for (int j = 1; j <= len2; j++) {
      if (word1[i - 1] == word2[j - 1]) {
        matrix[i][j] = matrix[i - 1][j - 1];
      } else {
        matrix[i][j] = 1 + min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]);
      }
    }
  }

  return matrix[len1][len2];
}

// Get the minimum of three numbers
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
  char word[MAX_WORD_LENGTH];

  printf("Enter a word: ");
  scanf("%s", word);

  if (is_word_in_dictionary(word)) {
    printf("%s is a valid word.\n", word);
  } else {
    char *closest_word = get_closest_word_in_dictionary(word);
    printf("%s is not a valid word. The closest word in the dictionary is %s.\n", word, closest_word);
  }

  return 0;
}