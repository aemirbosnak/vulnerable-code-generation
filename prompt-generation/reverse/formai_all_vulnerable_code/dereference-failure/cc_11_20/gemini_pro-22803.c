//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: paranoid
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A paranoid spell checker that checks every possible permutation of the word.

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <word>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the word to check.
  char *word = argv[1];

  // Get the length of the word.
  int length = strlen(word);

  // Allocate memory for the permutations.
  char **permutations = malloc(sizeof(char *) * length);
  for (int i = 0; i < length; i++) {
    permutations[i] = malloc(sizeof(char) * (length + 1));
  }

  // Generate all possible permutations of the word.
  int permutations_count = 0;
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length; j++) {
      if (i == j) {
        continue;
      }

      // Swap the characters at indices i and j.
      char temp = word[i];
      word[i] = word[j];
      word[j] = temp;

      // Copy the modified word to the permutations array.
      strcpy(permutations[permutations_count], word);

      // Increment the number of permutations.
      permutations_count++;

      // Swap the characters back to their original positions.
      temp = word[i];
      word[i] = word[j];
      word[j] = temp;
    }
  }

  // Check each permutation for spelling errors.
  int errors_found = 0;
  for (int i = 0; i < permutations_count; i++) {
    // Open the dictionary file.
    FILE *dictionary = fopen("/usr/share/dict/words", "r");
    if (dictionary == NULL) {
      fprintf(stderr, "Error opening dictionary file\n");
      return EXIT_FAILURE;
    }

    // Search for the permutation in the dictionary.
    int found = 0;
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), dictionary) != NULL) {
      // Remove the newline character from the buffer.
      buffer[strlen(buffer) - 1] = '\0';

      // Check if the permutation matches the word in the dictionary.
      if (strcmp(permutations[i], buffer) == 0) {
        found = 1;
        break;
      }
    }

    // Close the dictionary file.
    fclose(dictionary);

    // If the permutation was not found in the dictionary, print an error message.
    if (!found) {
      printf("Error: %s is not a valid word\n", permutations[i]);
      errors_found++;
    }
  }

  // Free the memory allocated for the permutations.
  for (int i = 0; i < length; i++) {
    free(permutations[i]);
  }
  free(permutations);

  // Return the number of errors found.
  return errors_found;
}