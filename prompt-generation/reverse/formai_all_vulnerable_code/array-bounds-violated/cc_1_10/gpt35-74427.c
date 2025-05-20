//FormAI DATASET v1.0 Category: Spell checking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 50 // Maximum length of the word to be checked
#define DICTIONARY_SIZE 370099 // Size of the dictionary array

int isMisspelled(char *word, char *dictionary[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    if (strcmp(word, dictionary[i]) == 0)
      return 0;
  }
  return 1;
}

char *toLowerCase(char *str) {
  int i;
  for (i = 0; i < strlen(str); i++) {
    str[i] = tolower(str[i]);
  }
  return str;
}

int isLetter(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void removeNonLetters(char *str) {
  int readIndex, writeIndex;
  for (readIndex = 0, writeIndex = 0; str[readIndex] != '\0'; readIndex++) {
    if (isLetter(str[readIndex])) {
      str[writeIndex++] = str[readIndex];
    }
  }
  str[writeIndex] = '\0';
}

void checkAndPrint(char *word, char *dictionary[], int size) {
  char *lowercase = toLowerCase(word);
  removeNonLetters(lowercase);
  if (isMisspelled(lowercase, dictionary, size)) {
    printf("%s is misspelled.\n", word);
  }
}

int main() {
  char *dictionary[DICTIONARY_SIZE];
  FILE *dictFile = fopen("dictionary.txt", "r");
  if (dictFile == NULL) {
    printf("Error reading dictionary file.\n");
    return 1;
  }
  int count = 0;
  char buffer[MAX_WORD_LEN];
  while (fgets(buffer, MAX_WORD_LEN, dictFile) != NULL) {
    buffer[strlen(buffer) - 1] = '\0'; // Remove newline
    dictionary[count++] = strdup(buffer);
  }
  printf("%d words loaded into dictionary.\n", count);
  fclose(dictFile);

  char *textFile = "text.txt";
  FILE *fp = fopen(textFile, "r");
  if (fp == NULL) {
    printf("Error reading text file.\n");
    return 1;
  }
  printf("Misspelled words:\n");
  char c;
  int wordIndex = 0;
  char word[MAX_WORD_LEN];
  while ((c = fgetc(fp)) != EOF) {
    if (isLetter(c)) {
      if (wordIndex < MAX_WORD_LEN - 1) {
        word[wordIndex++] = c;
      }
      else {
        // Word too long, ignore rest of it
        while ((c = fgetc(fp)) != EOF && isLetter(c))
          ;
        wordIndex = 0;
      }
    }
    else {
      // End of a word reached
      if (wordIndex > 0) {
        word[wordIndex] = '\0';
        checkAndPrint(word, dictionary, count);
        wordIndex = 0;
      }
    }
  }
  fclose(fp);

  return 0;
}