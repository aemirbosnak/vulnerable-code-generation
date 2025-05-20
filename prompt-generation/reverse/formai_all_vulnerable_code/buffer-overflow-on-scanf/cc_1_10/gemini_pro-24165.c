//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 100

// Post-Apocalyptic Dictionary
char *dictionary[] = {
  "abaddon", "apocalypse", "barbarism", "catastrophe", "devastation",
  "endgame", "extinction", "hellfire", "holocaust", "inferno",
  "judgement", "madness", "nightmare", "oblivion", "pandemonium",
  "purgatory", "ruin", "wasteland", "wrath", "zombie"
};

// Check if a word is in the dictionary
int is_word_in_dictionary(char *word) {
  int i;
  for (i = 0; i < sizeof(dictionary) / sizeof(char*); i++) {
    if (strcmp(word, dictionary[i]) == 0) {
      return 1;
    }
  }
  return 0;
}

// Get suggestions for a misspelled word
char **get_suggestions(char *word) {
  int i, j;
  char **suggestions = malloc(sizeof(char*) * 10);
  int num_suggestions = 0;

  // Check for single character errors
  for (i = 0; i < strlen(word); i++) {
    for (j = 0; j < 26; j++) {
      char new_word[MAX_WORD_LEN];
      strcpy(new_word, word);
      new_word[i] = 'a' + j;
      if (is_word_in_dictionary(new_word)) {
        suggestions[num_suggestions++] = strdup(new_word);
      }
    }
  }

  // Check for transposed characters
  for (i = 0; i < strlen(word) - 1; i++) {
    char new_word[MAX_WORD_LEN];
    strcpy(new_word, word);
    char tmp = new_word[i];
    new_word[i] = new_word[i+1];
    new_word[i+1] = tmp;
    if (is_word_in_dictionary(new_word)) {
      suggestions[num_suggestions++] = strdup(new_word);
    }
  }

  // Check for missing characters
  for (i = 0; i < strlen(word); i++) {
    char new_word[MAX_WORD_LEN];
    strcpy(new_word, word);
    memmove(new_word + i + 1, new_word + i, strlen(word) - i);
    new_word[i] = 'a';
    if (is_word_in_dictionary(new_word)) {
      suggestions[num_suggestions++] = strdup(new_word);
    }
  }

  // Check for extra characters
  for (i = 0; i < strlen(word); i++) {
    char new_word[MAX_WORD_LEN];
    strcpy(new_word, word);
    memmove(new_word + i, new_word + i + 1, strlen(word) - i);
    if (is_word_in_dictionary(new_word)) {
      suggestions[num_suggestions++] = strdup(new_word);
    }
  }

  return suggestions;
}

int main() {
  char word[MAX_WORD_LEN];
  int i;

  printf("Enter a word to check: ");
  scanf("%s", word);

  if (is_word_in_dictionary(word)) {
    printf("The word is spelled correctly.\n");
  } else {
    printf("The word is misspelled.\n");
    printf("Suggestions:\n");
    char **suggestions = get_suggestions(word);
    for (i = 0; i < 10; i++) {
      if (suggestions[i] != NULL) {
        printf("  %s\n", suggestions[i]);
        free(suggestions[i]);
      }
    }
    free(suggestions);
  }

  return 0;
}