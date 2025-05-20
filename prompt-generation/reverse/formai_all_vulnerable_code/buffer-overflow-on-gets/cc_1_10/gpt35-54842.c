//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: synchronous
#include <stdio.h>
#include <string.h>

// Function to get the sentiment score for a given word
int getSentimentScore(char* word) {
  int sentimentScore = 0; // Initialize sentiment score to zero

  // Define list of positive and negative words
  char posWords[10][20] = {"happy", "joyful", "great", "love", "excited", "success", "awesome", "best", "perfect", "nice"};
  char negWords[10][20] = {"sad", "angry", "frustrated", "bad", "hate", "failure", "terrible", "worst", "disappointing", "not good"};

  // Check if given word is in the list of positive words
  for (int i = 0; i < 10; i++) {
    if (strcmp(word, posWords[i]) == 0) {
      sentimentScore += 1; // Add one if positive word is found
    }
  }

  // Check if given word is in the list of negative words
  for (int i = 0; i < 10; i++) {
    if (strcmp(word, negWords[i]) == 0) {
      sentimentScore -= 1; // Subtract one if negative word is found
    }
  }

  return sentimentScore;
}

int main() {
  char sentence[100]; // Define sentence variable to store user input
  int sentimentValue = 0; // Initialize the sentiment value to zero

  printf("Enter a sentence: ");
  gets(sentence); // Get input sentence
  char* word = strtok(sentence, " "); // Split sentence into words

  // Loop through each word in the sentence and get its sentiment score
  while (word != NULL) {
    int currSentiment = getSentimentScore(word); // Get sentiment score for current word
    sentimentValue += currSentiment; // Add current sentiment score to total sentiment value
    word = strtok(NULL, " "); // Move to next word in sentence
  }

  // Determine overall sentiment based on sentiment value
  if (sentimentValue > 0) {
    printf("Positive sentiment!\n");
  } else if (sentimentValue < 0) {
    printf("Negative sentiment!\n");
  } else {
    printf("Neutral sentiment.\n");
  }

  return 0;
}