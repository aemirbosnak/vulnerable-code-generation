//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 1000

typedef struct {
  char word[MAX_WORD_LENGTH];
  int count;
} WordCount;

int readWords(char* filename, char** words) {
  FILE* file = fopen(filename, "r");
  if(file == NULL) {
    printf("Unable to open file '%s'\n", filename);
    return 0;
  }

  char buffer[MAX_WORD_LENGTH];

  int numWords = 0;
  while(fscanf(file, "%s", buffer) == 1) {
    char* word = strdup(buffer);
    if(numWords >= MAX_NUM_WORDS) {
      printf("Too many words in file '%s'\n", filename);
      free(word);
      break;
    }
    words[numWords++] = word;
  }

  fclose(file);

  return numWords;
}

void countWords(char** words, int numWords, WordCount* wordCounts, int* numUniqueWords) {
  *numUniqueWords = 0;
  for(int i = 0; i < numWords; i++) {
    char* word = words[i];

    //convert word to lowercase
    for(int j = 0; j < strlen(word); j++) {
      word[j] = tolower(word[j]);
    }

    //check if word already exists in wordCounts array
    int found = 0;
    for(int j = 0; j < *numUniqueWords; j++) {
      if(strcmp(word, wordCounts[j].word) == 0) {
    wordCounts[j].count++;
    found = 1;
    break;
      }
    }

    //if word doesn't exist, add it to wordCounts array
    if(!found) {
      if(*numUniqueWords >= MAX_NUM_WORDS) {
    printf("Too many unique words\n");
    break;
      }
      WordCount wordCount;
      strcpy(wordCount.word, word);
      wordCount.count = 1;
      wordCounts[*numUniqueWords] = wordCount;
      (*numUniqueWords)++;
    }
  }
}

void printWordCounts(WordCount* wordCounts, int numUniqueWords) {
  printf("WORD\tFREQUENCY\n");
  for(int i = 0; i < numUniqueWords; i++) {
    printf("%s\t%d\n", wordCounts[i].word, wordCounts[i].count);
  }
}

int main() {
  char filename[100];
  char* words[MAX_NUM_WORDS];
  int numUniqueWords = 0;
  WordCount wordCounts[MAX_NUM_WORDS];
  
  printf("Enter name of file to read: ");
  scanf("%s", filename);

  int numWords = readWords(filename, words);

  if(numWords > 0) {
    countWords(words, numWords, wordCounts, &numUniqueWords);
    printWordCounts(wordCounts, numUniqueWords);
  }

  for(int i = 0; i < numWords; i++) {
    free(words[i]);
  }

  return 0;
}