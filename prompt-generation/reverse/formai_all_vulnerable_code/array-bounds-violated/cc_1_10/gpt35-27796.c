//FormAI DATASET v1.0 Category: Text processing ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to remove punctuation from a string
char *remove_punctuation(char *str) {
  int len = strlen(str);
  char *new_str = (char *)malloc(len * sizeof(char)); 
  int j = 0;
  for (int i = 0; i < len; i++) {
    if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
      new_str[j] = str[i];
      j++;
    }
  }
  new_str[j] = '\0';
  return new_str;
}

int main() {
  // read input text string from user
  char text[1000];
  printf("Enter a sentence: ");
  fgets(text, sizeof(text), stdin);

  // remove newline character from string
  if (text[strlen(text) - 1] == '\n') {
    text[strlen(text) - 1] = '\0';
  }

  // convert text to lowercase
  for (int i = 0; i < strlen(text); i++) {
    text[i] = tolower(text[i]);
  }

  // tokenize string into words
  char *word;
  char *delim = " ";
  char *words[100];
  int word_count = 0;
  word = strtok(text, delim);
  while (word != NULL) {
    words[word_count] = word;
    word_count++;
    word = strtok(NULL, delim);
  }

  // remove punctuation from each word
  for (int i = 0; i < word_count; i++) {
    words[i] = remove_punctuation(words[i]);
  }

  // count frequency of each word
  int freq[word_count];
  for (int i = 0; i < word_count; i++) {
    freq[i] = 1;
    for (int j = i + 1; j < word_count; j++) {
      if (strcmp(words[i], words[j]) == 0) {
        freq[i]++;
        for (int k = j; k < word_count - 1; k++) {
          strcpy(words[k], words[k+1]);
          freq[k] = freq[k+1];
        }
        word_count--;
        j--;
      }
    }
  }

  // print result
  printf("Word\t\tFrequency\n");
  for (int i = 0; i < word_count; i++) {
    printf("%s\t\t%d\n", words[i], freq[i]);
    free(words[i]);
  }

  return 0;
}