//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: peaceful
// Spell-checking program in a peaceful style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Are we a word?
int is_word(char *word) {
  // Check if the word is empty
  if (!*word) {
    return 0;
  }
  // Check if the word is a number
  for (int i = 0; word[i]; i++) {
    if (!isdigit(word[i])) {
      return 0;
    }
  }
  // Check if the word is a symbol
  for (int i = 0; word[i]; i++) {
    if (!isalpha(word[i])) {
      return 0;
    }
  }
  // The word is valid!
  return 1;
}

// Main function
int main() {
  // Get the dictionary
  FILE *f = fopen("dictionary.txt", "r");
  if (!f) {
    printf("Error opening dictionary file.\n");
    return 1;
  }
  // Read the dictionary into an array of strings
  char *words[10000];
  int num_words = 0;
  while (!feof(f)) {
    char word[100];
    fscanf(f, "%s", word);
    words[num_words++] = strdup(word);
  }
  fclose(f);
  // Get the text to check
  char text[10000];
  printf("Enter the text to check: ");
  scanf("%s", text);
  // Check the spelling of each word in the text
  char *p = text;
  while (*p) {
    // Get the next word
    char word[100];
    int i = 0;
    while (*p && !isspace(*p)) {
      word[i++] = *p++;
    }
    word[i] = '\0';
    // Check if the word is in the dictionary
    int found = 0;
    for (int i = 0; i < num_words; i++) {
      if (!strcmp(word, words[i])) {
        found = 1;
        break;
      }
    }
    // If the word is not in the dictionary, print it out
    if (!found && is_word(word)) {
      printf("The word \"%s\" is not in the dictionary.\n", word);
    }
    // Move on to the next word
    p++;
  }
  // Free the memory allocated for the dictionary
  for (int i = 0; i < num_words; i++) {
    free(words[i]);
  }
  // Return 0 to indicate success
  return 0;
}