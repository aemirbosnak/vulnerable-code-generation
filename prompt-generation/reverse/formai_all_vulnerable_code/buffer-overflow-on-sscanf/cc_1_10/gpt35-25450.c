//FormAI DATASET v1.0 Category: Spell checking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50 // maximum length of a word
#define DICT_SIZE 1000 // maximum number of words in the dictionary

// function to load words from dictionary file into array
int loadDictionary(char* filename, char dictionary[DICT_SIZE][MAX_WORD_LENGTH]) {
  FILE* fp;
  int count = 0;
  char word[MAX_WORD_LENGTH];

  fp = fopen(filename, "r");

  if (fp == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }

  while (fgets(word, MAX_WORD_LENGTH, fp) != NULL && count < DICT_SIZE) {
    sscanf(word, "%s", dictionary[count]);
    count++;
  }

  fclose(fp);

  return count;
}

// function to check if a word is spelled correctly
int checkSpelling(char* word, char dictionary[DICT_SIZE][MAX_WORD_LENGTH], int numWords) {
  int i;

  for (i = 0; i < numWords; i++) {
    if (strcmp(dictionary[i], word) == 0) {
      return 1; // word is spelled correctly
    }
  }

  return 0; // word is not in the dictionary
}

// function to convert a string to lowercase
void toLowercase(char* str) {
  int i;

  for (i = 0; str[i]; i++) {
    str[i] = tolower(str[i]);
  }
}

int main() {
  char dictionary[DICT_SIZE][MAX_WORD_LENGTH];
  char input[MAX_WORD_LENGTH];
  int numWords;
  int i;

  printf("Loading dictionary...\n");
  numWords = loadDictionary("dictionary.txt", dictionary);
  printf("%d words loaded.\n", numWords);

  printf("Enter a word (or type 'exit' to quit): ");
  fgets(input, MAX_WORD_LENGTH, stdin);

  while (strcmp(input, "exit\n") != 0) {
    input[strlen(input) - 1] = '\0'; // remove newline character

    toLowercase(input);

    if (checkSpelling(input, dictionary, numWords)) {
      printf("%s is spelled correctly.\n", input);
    } else {
      printf("%s is misspelled.\n", input);
    }

    printf("Enter a word (or type 'exit' to quit): ");
    fgets(input, MAX_WORD_LENGTH, stdin);
  }

  return 0;
}