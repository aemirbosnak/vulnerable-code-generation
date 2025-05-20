//Code Llama-13B DATASET v1.0 Category: Spell checking ; Style: imaginative
// Spell Checker Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 100
#define MAX_DICT_SIZE 1000

// Structure to store a word and its count
typedef struct {
  char word[MAX_WORD_LEN];
  int count;
} Word;

// Function to read a word from the standard input
char* read_word(char* word) {
  int i = 0;
  char c;
  while ((c = getchar()) != '\n' && c != EOF) {
    word[i++] = c;
  }
  word[i] = '\0';
  return word;
}

// Function to check if a word is in the dictionary
int is_in_dict(char* word, Word dict[], int dict_size) {
  for (int i = 0; i < dict_size; i++) {
    if (strcmp(word, dict[i].word) == 0) {
      return 1;
    }
  }
  return 0;
}

// Function to check if a word is spelled correctly
int spell_check(char* word, Word dict[], int dict_size) {
  if (is_in_dict(word, dict, dict_size)) {
    return 1;
  }
  return 0;
}

// Function to print the dictionary
void print_dict(Word dict[], int dict_size) {
  for (int i = 0; i < dict_size; i++) {
    printf("%s\n", dict[i].word);
  }
}

// Function to print the spelling suggestions
void print_suggestions(char* word, Word dict[], int dict_size) {
  if (!spell_check(word, dict, dict_size)) {
    printf("Did you mean: ");
    for (int i = 0; i < dict_size; i++) {
      if (strcmp(word, dict[i].word) == 0) {
        printf("%s\n", dict[i].word);
      }
    }
  }
}

int main() {
  // Initialize the dictionary
  Word dict[MAX_DICT_SIZE];
  int dict_size = 0;
  FILE* file = fopen("dictionary.txt", "r");
  if (file == NULL) {
    printf("Error opening dictionary file\n");
    return 1;
  }
  while (fscanf(file, "%s", dict[dict_size].word) != EOF) {
    dict_size++;
  }
  fclose(file);

  // Check the spelling of the input word
  char word[MAX_WORD_LEN];
  printf("Enter a word: ");
  read_word(word);
  spell_check(word, dict, dict_size);
  print_suggestions(word, dict, dict_size);

  return 0;
}