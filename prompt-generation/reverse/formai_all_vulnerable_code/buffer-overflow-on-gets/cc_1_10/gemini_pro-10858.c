//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize a dictionary of positive and negative words
char *positiveWords[] = {"good", "great", "excellent", "awesome", "superb"};
char *negativeWords[] = {"bad", "terrible", "awful", "horrible", "dreadful"};

// Initialize a function to analyze the sentiment of a given sentence
int analyzeSentiment(char *sentence) {
  // Tokenize the sentence into words
  char *words[100];
  int numWords = 0;
  char *word = strtok(sentence, " ");
  while (word != NULL) {
    words[numWords++] = word;
    word = strtok(NULL, " ");
  }

  // Count the number of positive and negative words in the sentence
  int numPositiveWords = 0;
  int numNegativeWords = 0;
  for (int i = 0; i < numWords; i++) {
    for (int j = 0; j < 5; j++) {
      if (strcmp(words[i], positiveWords[j]) == 0) {
        numPositiveWords++;
      }
      if (strcmp(words[i], negativeWords[j]) == 0) {
        numNegativeWords++;
      }
    }
  }

  // Return the sentiment of the sentence based on the number of positive and negative words
  if (numPositiveWords > numNegativeWords) {
    return 1;
  } else if (numNegativeWords > numPositiveWords) {
    return -1;
  } else {
    return 0;
  }
}

// Main function
int main() {
  // Get the input sentence from the user
  printf("Enter a sentence: ");
  char sentence[100];
  gets(sentence);

  // Analyze the sentiment of the sentence
  int sentiment = analyzeSentiment(sentence);

  // Print the sentiment of the sentence
  if (sentiment == 1) {
    printf("The sentence is positive.\n");
  } else if (sentiment == -1) {
    printf("The sentence is negative.\n");
  } else {
    printf("The sentence is neutral.\n");
  }

  return 0;
}