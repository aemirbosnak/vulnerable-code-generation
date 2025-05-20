//FormAI DATASET v1.0 Category: Spell checking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// The following function is used to convert the given word into lowercase
void toLower(char *word) {
  int i = 0;
  while(word[i] != '\0') {
    word[i] = tolower(word[i]);
    i++;
  }
}

// This function is used to check if the given word is valid or not
// In this function, we consider a word valid if it contains only alphabets and apostrophes
int isWord(char *word) {
  int i = 0;
  while(word[i] != '\0') {
    if(!isalpha(word[i]) && word[i] != '\'')
      return 0;
    i++;
  }
  return 1;
}

// This function is used to remove the trailing newline character from a string
void removeNewline(char *str) {
  int i = 0;
  while(str[i] != '\0') {
    if(str[i] == '\n') {
      str[i] = '\0';
      break;
    }
    i++;
  }
}

// This function is used to check if the given word is spelled correctly or not
// In this function, we check if the given word is present in the dictionary or not
// If the word is not present in the dictionary, we consider it as a misspelled word
int checkSpelling(char *word, char **dictionary, int size) {
  int i;
  for(i = 0; i < size; i++) {
    if(strcmp(word, dictionary[i]) == 0)
      return 1;
  }
  return 0;
}

int main() {
  int size = 0, i;
  char **dictionary = NULL;
  char sentence[1000], word[100];

  // In this section of the code, we read the dictionary file and store it in an array
  FILE *fp = fopen("dictionary.txt", "r");
  if(fp == NULL) {
    printf("Error opening dictionary file!");
    exit(1);
  }
  while(fscanf(fp, "%s", word) != EOF) {
    toLower(word);
    if(isWord(word)) {
      size++;
      dictionary = (char **) realloc(dictionary, size * sizeof(char *));
      dictionary[size-1] = (char *) malloc(strlen(word) + 1);
      strcpy(dictionary[size-1], word);
    }
  }
  fclose(fp);

  // In this section of the code, we read the input sentence and check for spelling errors
  printf("Enter a sentence: ");
  fgets(sentence, 1000, stdin);
  removeNewline(sentence);

  i = 0;
  while(sentence[i] != '\0') {
    int j = 0;
    while(sentence[i] != ' ' && sentence[i] != '\0') {
      word[j++] = sentence[i++];
    }
    word[j] = '\0';
    toLower(word);
    if(isWord(word)) {
      if(!checkSpelling(word, dictionary, size))
        printf("Misspelled word: %s\n", word);
    }
    if(sentence[i] == ' ')
      i++;
  }

  // Freeing the memory used by the dictionary array
  for(i = 0; i < size; i++)
    free(dictionary[i]);
  free(dictionary);

  return 0;
}