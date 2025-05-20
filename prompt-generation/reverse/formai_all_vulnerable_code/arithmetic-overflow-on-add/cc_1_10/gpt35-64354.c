//FormAI DATASET v1.0 Category: Text Summarizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 50
#define MAX_SENTENCE_LENGTH 200

// function to count the occurrence of a word in a sentence
int countOccurrences(char *sentence, char *word) {
  int count = 0;
  char *token = strtok(sentence, " .,!:");
  while (token != NULL) {
    if (strcmp(token, word) == 0) {
      count++;
    }
    token = strtok(NULL, " .,!:");
  }
  return count;
}

// function to calculate score of a sentence based on the frequency of the words
int calculateSentenceScore(char *sentence, char *keywords[], int numKeywords) {
  int score = 0;
  for (int i = 0; i < numKeywords; i++) {
    score += countOccurrences(sentence, keywords[i]);
  }
  return score;
}

// main function
int main() {
  char text[MAX_SENTENCES][MAX_SENTENCE_LENGTH];
  char keywords[5][10];
  int numKeywords;
  
  // get input from user
  printf("Enter the text: \n");
  for (int i = 0; i < MAX_SENTENCES; i++) {
    fgets(text[i], MAX_SENTENCE_LENGTH, stdin);
    if (text[i][0] == '\n') {
      break;
    }
  }
  
  printf("Enter the keywords: \n");
  for (int i = 0; i < 5; i++) {
    scanf("%s", keywords[i]);
    if (keywords[i][0] == '\n') {
      break;
    }
    numKeywords++;
  }
  
  // calculate score of each sentence
  int sentenceScores[MAX_SENTENCES];
  for (int i = 0; i < MAX_SENTENCES; i++) {
    sentenceScores[i] = calculateSentenceScore(text[i], keywords, numKeywords);
  }
  
  // sort the sentence scores in descending order
  int tempScore;
  char tempSentence[MAX_SENTENCE_LENGTH];
  for (int i = 0; i < MAX_SENTENCES; i++) {
    for (int j = i + 1; j < MAX_SENTENCES; j++) {
      if (sentenceScores[i] < sentenceScores[j]) {
        tempScore = sentenceScores[i];
        sentenceScores[i] = sentenceScores[j];
        sentenceScores[j] = tempScore;
        
        strcpy(tempSentence, text[i]);
        strcpy(text[i], text[j]);
        strcpy(text[j], tempSentence);
      }
    }
  }
  
  // print the top 3 sentences
  printf("Summary:\n");
  for (int i = 0; i < 3 && i < MAX_SENTENCES; i++) {
    printf("%s", text[i]);
  }
  
  return 0;
}