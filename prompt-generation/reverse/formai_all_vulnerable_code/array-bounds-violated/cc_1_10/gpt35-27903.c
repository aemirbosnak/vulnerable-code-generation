//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: detailed
/*
This is a simple implementation of Sentiment Analysis Tool in C
It takes input sentence from user and returns the sentiment score between -1 and 1
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000

int parse_score(char *word);

int main() {
  char sentence[MAX_SENTENCE_LENGTH];
  int length;
  double score = 0;
  int word_count = 0;

  printf("Enter a sentence to analyze: ");
  fgets(sentence, MAX_SENTENCE_LENGTH, stdin); // taking input sentence from user

  length = strlen(sentence);
  
  if (sentence[length - 1] == '\n') {
    sentence[length - 1] = '\0';
  }

  // parsing score for each word in the sentence
  char *word = strtok(sentence, " ");
  while (word != NULL) {
    score += parse_score(word);
    word_count++;
    word = strtok(NULL, " ");
  }

  // calculating average score of sentence
  if (word_count != 0) {
    score /= word_count;
  }

  printf("Sentiment score for the sentence is %.2f.", score);

  return 0;
}

// function to parse the sentiment score for each word
int parse_score(char *word) {
  static const char *positive_words[] = {"good", "great", "excellent", "positive", "happy", "joyful", "wonderful"};
  static const char *negative_words[] = {"bad", "terrible", "poor", "negative", "sad", "depressed", "worst"};
  
  int word_score = 0;
  int i;

  // converting word to lowercase for case-insensitive comparison
  for (i = 0; word[i]; i++) {
    word[i] = tolower(word[i]);
  }

  // assigning score for positive and negative words
  for (i = 0; i < 7; i++) {
    if (strcmp(word, positive_words[i]) == 0) {
      word_score = 1;
      break;
    }
    if (strcmp(word, negative_words[i]) == 0) {
      word_score = -1;
      break;
    }
  }

  return word_score;
}